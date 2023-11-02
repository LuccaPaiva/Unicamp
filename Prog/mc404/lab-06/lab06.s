.text
  .align 1
  .globl _start

_start:  
  # Converte angulo inteiro para radianos e coloca em f0
  jal funcao_pegar_angulo
  # Utilizado para calcular a série
  jal funcao_calcula_serie
  # Transforma um PF para inteiro, onde a0 contem o sinal, a1 a parte inteira e a2 a parte fracionaria (truncada com 3 casas decimais)
  jal funcao_float_para_inteiro
  # Imprime o resultado de a0, a1 e a2 na tela
  jal funcao_imprime
  
  li a0, 0 # exit code
  li a7, 93 # syscall exit
  ecall
  
funcao_calcula_serie:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Neste ponto o registrador f0 contem o valor de angle em radianos
  # *********************************************
  # ** INSIRA AQUI SEU CÓDIGO PARA CÁLCULO DA SERIE **
  
  #carrega sum = x em t0
  lw t0, 0(f0)
  #salva em t1 x^2
  fmul.s t1, f0, f0
  #carrega xpow em t2
  lw t2, 0(f0)
  #carrega fat = 1 em t3
  li t3, 1
  #carrega i = 1
  li t4, 1
  #carrega limite = 10 em t6
  li t6, 10
  loop:
  #xpow = xpow * x^2
  mul.s t2, t2, t1
  #fat = fat*(fat + 1)
  #fat = fat*(fat + 1) --> (fat + 2)!
  addi t5, t3, 1
  mul t3, t5, t3
  addi t5, t3, 1
  mul t3, t5, t3
  #fat --> fat.float
  fcvt t5, t3
  #t5 <- xpow/fat
  fdiv.s t5, t2, t3
  #sum += t5
  add.s t0, t0, t5
  addi t6, t6, 1
  #verifica se i < 10
  blt t4, t6, loop 
  
  lw f0, 0(t0)
  # *********************************************
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra


funcao_imprime:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Neste ponto os registradores contem:
  #   a0 -> valor 0 se f0 for negativo e !=0 caso contratio
  #   a1 -> Parte inteira de f0
  #   a2 -> Parte fracionaria de f0 (truncada com 3 casas decimais, i.e. 0 a 999)
  # **************************************
  # ** INSIRA AQUI SEU CÓDIGO PARA IMPRESSÃO **
  .data
  sin: .asciz "SENO"
  plus: .asciz "+"
  minus: .asciz "-"
  dot: .asciz "."
  zer: .asciz "0"

  .text
  addi sp, sp, -12
  sw a2, 0(sp)
  sw a1, 0(sp)
  sw a0, 0(sp)
  
  seno:
  li a0, 1   #a0 = stdout
  li a1, sin #a1 = "SENO"
  li a2, 4   #a2 = strlen(a1)
  li a7, 64  # Syscall code (write = 64)
  ecall      # Invoke the syscall
  
  sinal:
  lw t0, 0(sp)  #carrega +/- em t0
  addi sp, sp, 4
  beqz t0, menos
  mais:
  li a1, plus #a1 = "+"
  menos:
  li a1, minus #a1 = "-"
  li a2, 1   #a2 = strlen(a1)
  ecall      # Invoke the syscall
  
  inteiro:
  lw t0, 0(sp)  #carrega inteiro em t0
  addi sp, sp, 4
  li a1, 0(t0) #a1 = int
  #pode ter varios tamanhos
  li t1, 10
  li t2, 100
  bltu t0, t1, pequeno
  bltu t0, t2, medio
  j grande

  pequeno:
  li a2, 1
  j fim
  medio:
  li a2, 2
  j fim
  grande:
  li a2, 3
  fim:
  ecall
  
  float:
  lw t0, 0(sp)  #carrega float em t0
  addi sp, sp, 4
  li a0, 1     #a0 = stdout
  lw a1, 0(t0) #a1 = float
  li a2, 4     #a2 = strlen(a1)
  li a7, 64    # Syscall code (write = 64)
  ecall        # Invoke the syscall
  # **************************************
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra

  
funcao_pegar_angulo:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # load angle value to a0
  lw a0, angle
  # convert angle to float and put in f0
  fcvt.s.w f0, a0
  # load pi address to a0
  la a0, .float_pi
  # load float_pi value (from a0 address) into f1
  flw f1, 0(a0)
  # load value 180 into a0
  li a0, 180
  # convert 180 to float and put in f2
  fcvt.s.w f2, a0

  # f0 -> angle, f1 -> pi, f2 -> 180
  # Now, put angle in radians (angle*pi/180)
  # f0 = angle * pi
  fmul.s f0, f0, f1
  # f0 = f0 / 180
  fdiv.s f0, f0, f2
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
funcao_float_para_inteiro:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Get signal
  li a0, 0
  fcvt.s.w f1, a0
  flt.s a0, f0, f1
  
  # Drop float signal
  fabs.s f0, f0
  
  # Truncate integer part
  fcvt.s.w f1, a0
  fadd.s f1, f1, f0
  jal funcao_truncar_float
  fcvt.w.s a1, f0
  
  # Truncate float part with 3 decimal places
  fsub.s f1, f1, f0
  li a3, 1000
  fcvt.s.w f2, a3
  fmul.s f0, f1, f2
  jal funcao_truncar_float
  fcvt.w.s a2, f0
  li a3, 1000
  rem a2, a2, a3
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
funcao_truncar_float:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  fmv.x.w a5, f0
  li a3, 22
  srai a4, a5,0x17
  andi a4, a4, 255
  addi a4, a4, -127
  addi a2, a5, 0
  blt a3, a4, .funcao_truncar_float_continue
  lui a5, 0x80000
  and a5, a5, a2
  bltz a4, .funcao_truncar_float_continue
  lui a5, 0x800
  addi a5, a5, -1
  sra a5, a5, a4
  not a5, a5
  and a5, a5, a2
.funcao_truncar_float_continue:
  fmv.w.x f0, a5
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
  
# Additional data variables
.align  4
.data
  angle:
    .word 45
  .float_pi:
    .word 0x40490fdb

