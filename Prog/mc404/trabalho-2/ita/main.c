#include "api_robot.h"

/*
 * Tira o "floor" da raiz quadrada dos numeros
 */
int Sqrt (int a){
    register unsigned long op, res, one;

    op = a;
    res = 0;

    /* "one" starts at the highest power of four <= than the argument. */
    one = 1 << 30;  /* second-to-top bit set */
    while (one > op) one >>= 2;

    while (one != 0) {
        if (op >= res + one) {
            op -= res + one;
            res += one << 1;  // <-- faster than 2 * one
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

/*
 * Encontra o amigo dentro do vetor friends_locations que esta mais proximo de Uoli
 */
int amigoMaisProximo (Vector3 robo, Vector3 *friends){
    int Distancias[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i <= 4; i++){
        int d = ((robo.x - friends[i].x)(robo.x - friends[i].x)) + ((robo.z - friends[i].z)(robo.z - friends[i].z));
        d = Sqrt(d);
        Distancias[i] = d;
    }

    int menorDistancia = 999999;
    int amigo = 0;
    for (int i = 0; i <= 4; i++){
        if (Distancias[i] < menorDistancia){
            menorDistancia = Distancias[i];
            amigo = i;
        }
    }

    // Retorna o parametro i que possui o amigo mais proximo no vetor de amigos
    return amigo;
}

double encontraArctangente (Vector3 uoli, Vector3 amigo){
    double tangente = (uoli.z - amigo.z)/(uoli.x - amigo.x);

    if (tangente < 0){
        tangente = tangente*(-1);
    }
    return tangente;
}

double continued_faction_arctan(int n, double x){
    double x2 = x*x;
    double d = n * 2 + 1;
    for (int k = n; k > 0; k--){
        double f = k * 2 - 1;
        d = f + k*k*x2/d;
    }
    return x / d;
}


double arctan(int n, double x){
    if (x > 1.0)
        return 3.141592653590/2.0 - continued_faction_arctan(n, 1/x);
    return continued_faction_arctan(n, x);
}

/*
 * Seta o giroscopio para o valor 0 em y para rodar a partir de um numero fixo
 */
void zeraGiroscopio (Vector3 angulo){
    while (angulo.y != 0){
        if ( angulo.y < 180){
            set_engine_torque(1, 0);
            set_engine_torque(0, 70);
        }
        else{
            set_engine_torque(0, 0);
            set_engine_torque(1, 70);
        }
    }
}

/*
 * Alinha o angulo do robo Uoli com o amigo mais proximo atraves de uma funcao que computa o angulo do arctangente entre Uoli e o amigo
 */
void AlinhaComAmigoMaisProximo (Vector3 angulo, Vector3 posicao, Vector3 *friend, int amigo){

    double tangente = encontraArctangente (posicao, friend[amigo]);
    int arctangente = arctan (20, tangente);

    if (friend[amigo].z > posicao.z){
        if (friend[amigo].x > posicao.x){
            while (angulo.z > arctangente + 2 || angulo.z < arctangente){
                set_engine_torque(0, 0);
                set_engine_torque(1, 45);
                get_gyro_angles(&angulo);
            }
        }
        else{
            while (angulo.z > 1.570796*2 - arctangente || angulo.z < 3,1415 - arctangente){
                set_engine_torque(0, 0);
                set_engine_torque(1, 45);
                get_gyro_angles(&angulo);
            }
        }
    }
    else{
        if (friend[amigo].x > posicao.x){
            while (angulo.z > 1.570796 - arctangente - 2 || angulo.z < 1.570796 - arctangente){
                set_engine_torque(1, 0);
                set_engine_torque(0, 45);
                get_gyro_angles(&angulo);
            }
        }
        else{
            while (angulo.z > 1.570796 + arctangente - 2 || angulo.z < 1.570796 - arctangente){
                set_engine_torque(1, 0);
                set_engine_torque(0, 45);
                get_gyro_angles(&angulo);
            }
        }
    }
}

int distanciaAteAmigos (Vector3 posicao, Vector3* friends){ //Checa se o objeto encontrado pelo robo Uoli eh um amigo
    for ( int i = 0; i <= 4; i++){
        int d = ((posicao.x - friends[i].x)(posicao.x - friends[i].x)) + ((posicao.z - friends[i].z)(posicao.z - friends[i].z));
        d = Sqrt(d);
        if(d <= 500){
            return 1;
        }
    }
    return 0;
}

void desvia (Vector3 angulo){
    while (angulo.y != angulo.y - 90){ //Vira pra direita 90 graus
        set_engine_torque(1, 0);
        set_engine_torque(0, 45);
        get_gyro_angles(&angulo);
    }

    set_head_servo(2, 0);//Gira a cabeca do robo para a esquerda pra ver se tem objetos na frente dele
    while (get_us_distance() < 0){
        set_engine_torque(1, 75);
        set_engine_torque(0, 75);
    }

    while (angulo.y != angulo.y + 90){ //Vira pra esquerda 90 graus
        set_engine_torque(0, 0);
        set_engine_torque(1, 45);
        get_gyro_angles(&angulo);
    }
}

int main(){
    int contagem = 0; //Contagem de amigos visitados
    char *buffer="buffer aqui";
    set_time(1000);
    set_torque(60,60);

    Vector3 posicao;
    Vector3 angulo;

    comeco:
    if (contagem == 5){
        goto fim;
    }
    get_current_GPS_position(&posicao);
    get_gyro_angles(&angulo);

    int amigo = amigoMaisProximo (posicao, friends_locations);

    zeraGiroscopio(angulo);
    AlinhaComAmigoMaisProximo (angulo, posicao, friends_locations, amigo);

    while(1) {
        set_head_servo(2, 68);//Vira a cabeca do Uoli para ambos os lados para observar uma maior area a sua frente
        int bloqueio = get_us_distance();
        if (bloqueio < 0)
            goto laco;
        set_head_servo(2, 78);
        bloqueio = get_us_distance();
        if (bloqueio < 0)
            goto laco;
        set_head_servo(2, 88);
        bloqueio = get_us_distance();
        if (bloqueio < 0)
            goto laco;

        laco:
        if (bloqueio < 0) {
            set_engine_torque(0, 0);
            set_engine_torque(1, 0);
            //Existe um objeto no range do sensor que precisa ser desviado
            int distanciaAmigos = distanciaAteAmigos(posicao, friends_locations);
            if (distanciaAmigos == 1){
                zeraGiroscopio(angulo);
                contagem++;
                goto comeco;
            }
            else{ //Objeto no range do sensor eh uma localizacao perigosa
                desvia(angulo);
                AlinhaComAmigoMaisProximo(angulo, posicao, friends_locations, amigo);
            }
        }
        set_engine_torque(0, 60);
        set_engine_torque(1, 60);
    }

    fim:
    puts(buffer);


    return 0;

}
