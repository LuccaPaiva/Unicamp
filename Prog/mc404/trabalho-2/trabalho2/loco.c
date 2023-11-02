//LUCCA FERREIRA PAIVA 240229

#include "api_car.h"

int direcao(unsigned char sensor[256], int aux){
  int i, j;
  for(i = 0; i <= 127; i++){
    if(sensor[i] > 200){
      break;
    }
  }
  i -= 127;
  for(j = 255; j >= 127; j--){
    if(sensor[j] > 200){
      break;
    }
  }
  j -= 127;
  int media = i + j;
  media = media / 2;
  if(media <= 20 && media >= -20){
    if(aux > 20){
      return -8;
    }
    else if(aux < -20){
      return 8;
    }
    return 00;
  }

  else if(media > 20 && media <= 35){
    if(aux < -5){
      return 35;
    }
    else if(aux < 20){
      return 20;
    }
    return 15;
  }
  else if(media > 35 && media < 60){
    if(aux < -5){
      return 50;
    }
    else if(aux < 20){
      return 35;
    }
    return 25;
  }
  else if(media >= 60){
    if(aux < 0){
      return 50;
    }
    else if(aux < 20){
      return 25;
    }
    return 35;
  }

  else if(media < -20 && media >= -35){
    if(aux > 5){
      return -35;
    }
    else if(aux < -20){
      return -20;
    }
    return -15;
  }
  else if(media < -35 && media > -60){
    if(aux > 5){
      return -50;
    }
    else if(aux > -20){
      return -35;
    }
    return -25;
  }
  else{
    if(aux > 0){
      return -50;
    }
    else if(aux > -20){
      return -25;
    }
    return -35;
  }
}

int dirigir(unsigned char sensor[256], int dir){
  int i, j;
  for(i = 25; i <= 127; i++){
    if(sensor[i] > 150){
      break;
    }
  }
  i -= 102;
  for(j = 230; j >= 127; j--){
    if(sensor[j] > 150){
      break;
    }
  }
  j -= 102;
  int media = i + j;
  media = media / 2;
  media -= dir;
  return media;
}

// Implemente aqui a lógica de controle do carro, utilizando as funções da api
void user_code(void) {

  int t = get_time(), lim, fim;
  unsigned char sensor[256];

  int posx, posy, poz;
  int rotx, roty, rotz;
  unsigned char vira;
  int aux = 0, a = 0;
  /*

  set_motor(1, 0);
  fim = t + 10000;
  while(t < fim){
    read_sensors(sensor);
    aux = direcao(sensor, aux);
    set_motor(1, aux);
    t = get_time();
    lim = t + 100;
    while(t < lim){
      t = get_time();
    }
  }
  */



























































































































































  
  //primeira curva
  set_motor(1, 0);
  t = get_time();
  lim = t + 500;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 20);
  t = get_time();
  lim = t + 2400;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 1850;
  while(t < lim){
    t = get_time();
  }
  //comeco segunda curva
  set_motor(1, -15);
  t = get_time();
  lim = t + 1500;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -35);
  t = get_time();
  lim = t + 1000;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -70);
  t = get_time();
  lim = t + 2000;
  while(t < lim){
    t = get_time();
  }

  //reta
  set_motor(1, 0);
  t = get_time();
  lim = t + 500;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -8);
  t = get_time();
  lim = t + 700;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 1200;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 5);
  t = get_time();
  lim = t + 350;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 800;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -15);
  t = get_time();
  lim = t + 800;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 700;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -115);
  t = get_time();
  lim = t + 400;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -125);
  t = get_time();
  lim = t + 600;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -105);
  t = get_time();
  lim = t + 500;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 600;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -10);
  t = get_time();
  lim = t + 500;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, 0);
  t = get_time();
  lim = t + 1100;
  while(t < lim){
    t = get_time();
  }

  set_motor(1, -55);
  t = get_time();
  lim = t + 700;
  while(t < lim){
    t = get_time();
  }

  set_motor(0, -35);
  t = get_time();
  lim = t + 200;
  while(t < lim){
    t = get_time();
  }


  set_motor(0, 0);
  set_handbreak(1);

  return;
}
