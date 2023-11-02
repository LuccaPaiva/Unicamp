#LUCCA FERREIRA PAIVA 240229


.align 4
# tratador de interrupção
int_handler:

  #salvar contexto
    csrrw sp, mscratch, sp # mscratch = antigo sp | sp pra salvar contexto
    addi sp, sp, -128

    sw ra, 0(sp)
    sw gp, 4(sp)
    sw tp, 8(sp)

    sw a0, 12(sp)
    sw a1, 16(sp)
    sw a2, 20(sp)
    sw a3, 24(sp)
    sw a4, 28(sp)
    sw a5, 32(sp)
    sw a6, 36(sp)
    sw a7, 40(sp)

    sw t0, 46(sp)
    sw t1, 50(sp)
    sw t2, 54(sp)
    sw t3, 58(sp)
    sw t4, 62(sp)
    sw t5, 66(sp)
    sw t6, 70(sp)


  # decodificar a causa da interrupção
  csrr a1, mcause      # 1 -> interrupcao | 0 -> excecao
  bge a1, zero, exception   #faz comparacao

  #Quer dizer que é interrupcao
  li t1, 2147483655           #Codigo de Machine timer interrupt
  beq t1, a2, timeLim         #Compara

  #Nao é uma das interrupcoes tratadas -> Saida
  j exit


  timeLim:
    j exit
    #  la t1, counter
    #  lw t2, 0(t1)
    #  addi t2, t2, 100
    #  sw t2, 0(t1)
    #  j exit


  exception:
    andi a1, a1, 0xff   #Codigo da chamada de sistema por user = 8
    li t0, 8
    beq a1, t0, uCall    #se nao for syscall
    j exit


    uCall:
    lw a0, 12(sp)       # restaura a0
    lw a1, 16(sp)       # restaura a1
    lw a2, 20(sp)       # restaura a2
    lw a3, 24(sp)       # restaura a3
    lw a7, 40(sp)       # restaura a7


    # verifica as syscalls
      li t0, 10   #Codigo Motor
      beq t0, a7, Syscall_set_motor

      li t0, 11    #Codigo Freio
      beq t0, a7, Syscall_set_handbreak

      li t0, 12   #Codigo Sensores
      beq t0, a7, Sycall_read_sensors

      li t0, 13   #Codigo Sensor distante
      beq t0, a7, Syscall_read_sensor_distance

      li t0, 14   #Codigo Tempo
      beq t0, a7, Syscall_get_time

      li t0, 15   #Codigo Posicao
      beq t0, a7, Syscall_get_position

      li t0, 16   #Codigo Rotacao
      beq t0, a7, Syscall_get_rotation


  # tratar interrupção
    Syscall_set_motor:
        li t0, 0xFFFF0120 #horizontal
        sb a1, 0(t0)
        li t1, 0xFFFF0121 #vertical
        sb a0, 0(t1)
        j exit_syscall

    Syscall_set_handbreak:
        li t0, 0xFFFF0122
        sb a0, 0(t0)
        j exit_syscall

    Sycall_read_sensors:
        li t0, 0xFFFF0101
        li t1, 1
        sb t1, 0(t0)  #carrega 1 no registrador
        loopSens:
          lb t1, 0(t0)
          bnez t1, loopSens  #ler ate ser 0
        li t0, 0xFFFF0124
        li t2, 0   #i
        li t5, 255 #limite
        for:
          lb t1, 0(t0)
          sb t1, 0(a0)
          addi t2, t2, 1  #i += 1
          addi t0, t0, 1  #t0 += 1
          blt t2, t5, for #t2 = i < t5 = 256
        j exit_syscall

    Syscall_read_sensor_distance:
        li t0, 0xFFFF0102
        li t1, 1
        sb t1, 0(t0)  #carrega 1 no registrador
        loopSenD:
          lb t1, 0(t0)
          bnez t1, loopSenD  #ler ate ser 0
        li t0, 0xFFFF011C
        lw a0, 0(t0)
        j exit_syscall

    Syscall_get_time:
        li t0, 0xFFFF0300
        li t1, 1
        sb t1, 0(t0)  #carrega 1 no registrador
        loopTime:
          lb t1, 0(t0)
          bnez t1, loopTime  #ler ate ser 0
        li t0, 0xFFFF0304
        lw a0, 0(t0)
        j exit_syscall

    Syscall_get_position:
        li t0, 0xFFFF0100
        li t1, 1
        sb t1, 0(t0)  #carrega 1 no registrador
        loopPos:
          lb t1, 0(t0)
          bnez t1, loopPos  #ler ate ser 0
        li t0, 0xFFFF0110
        lw t1, 0(t0)
        sw t1, 0(a0)
        li t0, 0xFFFF0114
        lw t1, 0(t0)
        sw t1, 0(a1)
        li t0, 0xFFFF0118
        lw t1, 0(t0)
        sw t1, 0(a2)
        j exit_syscall

    Syscall_get_rotation:
        li t0, 0xFFFF0100
        li t1, 1
        sb t1, 0(t0)  #carrega 1 no registrador
        loopRot:
          lb t1, 0(t0)
          bnez t1, loopRot  #ler ate ser 0
          li t0, 0xFFFF0104
          lw t1, 0(t0)
          sw t1, 0(a0)
          li t0, 0xFFFF0108
          lw t1, 0(t0)
          sw t1, 0(a1)
          li t0, 0xFFFF010C
          lw t1, 0(t0)
          sw t1, 0(a2)
          j exit_syscall

  exit_syscall:
  # interrupção foi tratada
  #  li t0, 0xFFFF0104
  #  li t1, 0
  #  sb t1, 0(t0)
  #      li t0, 0xFFFF0100
  #      li t1, 100 # gerar interrupcao a cada  milisegundos
  #      sw t1, 0(t0)



      exit:
    # Falar para o GPT que a interrupção foi tratada
      li t0, 0xFFFF0104
      li t1, 0
      sb t1, 0(t0)


     # recupera o contexto

       lw ra, 0(sp)
       lw gp, 4(sp)
       lw tp, 8(sp)

       #lw a0, 12(sp) #a0 nao precisa salvar
       lw a1, 16(sp)
       lw a2, 20(sp)
       lw a3, 24(sp)
       lw a4, 28(sp)
       lw a5, 32(sp)
       lw a6, 36(sp)
       lw a7, 40(sp)


       lw t0, 46(sp)
       lw t1, 50(sp)
       lw t2, 54(sp)
       lw t3, 58(sp)
       lw t4, 62(sp)
       lw t5, 66(sp)
       lw t6, 70(sp)

       addi sp, sp, 128

       csrrw sp, mscratch, sp # destroca eles q foram trocados no comeco

       # ajustando MEPC para retornar de uma chamada de sistema
       csrr t1, mepc
       addi t1, t1, 4
       csrw mepc, t1
       mret




# -----------------------------------------------------------------COMECO DO PROGRAMA----------------------------------------------------------

.globl _start

_start:
    # configurar o tratador de interrupções
      la t0, int_handler
      csrw mtvec, t0

    # ajusta o mscratch
      la t1, reg_buffer
      addi t1, t1, 2000
      csrw mscratch, t1

    # pilha usuario
      li sp, 0x7fffffc

    # muda para o modo de usario
      csrr t1, mstatus
      li t2, ~0x1800
      and t1, t1, t2
      csrw mstatus, t1

    #setar mepc
      la t3, user_code
      csrw mepc, t3
      mret


  # techo do codigo do usuario
    .align 4
    user:
        j user_code


# seção de dados

reg_buffer: .skip 4800
