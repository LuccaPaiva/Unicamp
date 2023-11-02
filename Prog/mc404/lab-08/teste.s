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
li a2, 0
jal move

fim:
  li a0, 0 # exit code
  li a7, 93 # syscall exit
  ecall
