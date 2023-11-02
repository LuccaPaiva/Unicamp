#A chamada de sistema 2100 é utilizada para movimentar o carro
#a0: Inteiro de 32-bits representando o tempo (em milisegundos) que o carro deve se deslocar.
#a1: Deve conter o valor 1, para o carro se mover para frente e -1 para o carro se mover para trás
#a2: Define a direção que o carro deve se mover e deve conter um inteiro de 32-bits, de -1024 a 1024, onde, com valores positivos, o carro move-se para a direita, negativos para esquerda e 0, mantem-se reto.

#clang -g -O0 --target=riscv32 -march=rv32gc -mabi=ilp32d -mno-relax arquivo_de_entrada.s -c -o arquivo_de_saida.o
#ld.lld -g arquivo_de_saida.o -o executavel.x

move:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  li  a7, 2100     # Código da syscall: 63 == read
  ecall            # Invoca o sistema operacional
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret              # Retorna resultado em


.globl _start
_start:
.text

li a0, 800
li a1, 1
li a2, -928
jal move

li a0, 4800
li a1, 1
li a2, 0
jal move

fim:
  li a0, 1 # exit code
  li a7, 93 # syscall exit
  ecall
