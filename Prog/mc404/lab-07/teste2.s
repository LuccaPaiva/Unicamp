read:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  li a0, 0         #stdin
  li  a7, 63       # Código da syscall: 63 == read
  ecall            # Invoca o sistema operacional
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret              # Retorna resultado em


le_int:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
   li t6, 0         # t6 = sum = 0
  li t5, 10        # t5 = 10 cte

  1:
  li a2, 1   #le 1 char
  la t0, var #coloca em var
  mv a1, t0  #passa var como buffer
  jal read
  lb t1, 0(t0)


  li t2, 32      #32 = " "
  beq t2, t1, 3f

  li t2, 10      #13 = "\n"
  beq t2, t1, 3f

  2: #é numero
  li t2, 48
  sub t2, t1, t2 #char -> int
  mul t6, t6, t5  #sum = sum*10
  add t6, t6, t2  #sum += t1(x)
  jal 1b

  3: #é espaco ou \n

  mv a4, t6

  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret


write:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  li a0, 1         #stdout
  li  a7, 64       # Código da syscall: 64 == write
  ecall            # Invoca o sistema operacional
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret              # Retorna

print_int: #recebe em a4 numero a ser impresso
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra


  li t4, 1000
  li t5, 100
  li t6, 10

  rem t2, a4, t4  #t2 = ABCD%100 = BCD
  sub t1, a4, t1  #t1 = A000
  div t1, t1, t4  #t1 = A

  rem t3, t2, t5  #t3 = BCD%100 = CD
  sub t2, t2, t3  #t2 = B00
  div t2, t2, t5  #t2 = B

  rem t4, t3, t6  #t4 = CD%10 = D
  sub t3, t3, t4  #t3 = C0
  div t3, t3, t6  #t3 = C

  #t1 = A, t2 = B, t3 = C, t4 = D

  li a2, 1 #escreve um caractere

  digit1:
    la t0, var
    addi t1, t1, 48
    sw t1, 0(t0)
    mv a1, t0
    jal write

  digit2:
    la t0, var
    addi t2, t2, 48
    sw t2, 0(t0)
    mv a1, t0
    jal write

  digit3:
    la t0, var
    addi t3, t3, 48
    sw t3, 0(t0)
    mv a1, t0
    jal write

  digit4:
    la t0, var
    addi t4, t4, 48
    sw t4, 0(t0)
    mv a1, t0
    jal write

  fim:
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret


.globl _start
_start:
  .section .text

  li a0, 1
  li a1, 1
  li a2, 1
  li a4, 9876
  jal print_int


  la t0, var
  li t1, 0x0A
  sw t1, 0(t0)
  mv a1, t0
  jal write

  li a0, 0 # exit code
  li a7, 93 # syscall exit
  ecall


.data
.align 4
var: .word 0x0A
.align 4
