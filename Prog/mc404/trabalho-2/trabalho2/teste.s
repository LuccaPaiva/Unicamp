#A chamada de sistema 2100 é utilizada para movimentar o carro
#a0: Inteiro de 32-bits representando o tempo (em milisegundos) que o carro deve se deslocar.
#a1: Deve conter o valor 1, para o carro se mover para frente e -1 para o carro se mover para trás
#a2: Define a direção que o carro deve se mover e deve conter um inteiro de 32-bits, de -1024 a 1024, onde, com valores positivos, o carro move-se para a direita, negativos para esquerda e 0, mantem-se reto.

#clang -g -O0 --target=riscv32 -march=rv32gc -mabi=ilp32d -mno-relax arquivo_de_entrada.s -c -o arquivo_de_saida.o
#ld.lld -g arquivo_de_saida.o -o executavel.x

.globl comeco

comeco:
.text

li a0, 1
li a1, 0
li a7, 10
jal set_motor


fim:
  li a0, 1 # exit code
  li a7, 93 # syscall exit
  ecall
