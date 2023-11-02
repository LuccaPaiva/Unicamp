.align 4
# tratador de interrupção
int_handler:
 # salvar contexto
 csrrw s1,mscratch,s1
 sw a0,0(s1)
 sw a1,4(s1)
 sw a2,8(s1)
 sw a3,12(s1)
 sw a7,16(s1)
 sw t0,20(s1)
 sw t1,24(s1)   
 sw t2,28(s1)
 sw t3,32(s1)
 sw t4,36(s1)


 li t0, 0xFFFF0104
 li t1, 0
 beq t0, t1, exit
  
 

 # decodificar a causa da interrupção
 csrr a1,mcause
 bgez a1,exception
 andi a1,a1,0x3f
 li t1, 7
 beq t1,a1, intemporizador
 j exit
 intemporizador:
     la t1,counter
     lw t2,0(t1)
     addi t2,t2,100
     sw t2,0(t1)
     j exit
 
 exception:
 lw a0,0(s1) 
 lw a7,16(s1)
 lw a3, 12(s1)
 lw a2, 8(s1)
 lw a1, 4(s1)
 


 # verifica as syscalls
 li t0,10
 beq t0,a7,Syscall_set_motor
 li t0,11
 beq t0,a7,Syscall_set_handbreak
 li t0,12
 beq t0,a7,Sycall_read_sensors 
 li t0,13
 beq t0,a7,Syscall_read_sensor_distance
 li t0,14
 beq t0,a7,Syscall_get_time
 li t0,15
 beq t0,a7,Syscall_get_position
 li t0,16
 beq t0,a7,Syscall_get_rotation


 # tratar interrupção
 Syscall_set_motor:
 Syscall_set_handbreak:
    li t0,0xFFFF0122
    sb a0,0(t0)
    j exit_syscall
 Sycall_read_sensors:
 Syscall_read_sensor_distance:
 Syscall_get_time:
    la t1, counter
    lw a0,0(t1)
    j exit_syscall
 Syscall_get_position:
 Syscall_get_rotation:

 exit_syscall:
 # interrupção foi tratada

 li t0,0xFFFF0104
 li t1,0
 sb t1,0(t0)
   li t0, 0xFFFF0100
    li t1,100 # gerar interrupcao a cada  milisegundos
    sw t1,0(t0)
 # ajustando MEPC para retornar de uma chamada de sistema
  csrr a1,mepc
  addi a1,a1,4
  csrw mepc,a1
  mret 





 exit:

 # Falar para o GPT que a interrupção foi tratada
 li t0,0xFFFF0104
 li t1,0
 sb t1,0(t0)

 
 # recupera o contexto
 lw t4,36(s1)
 lw t3,32(s1)
 lw t2,28(s1)
 lw t1,24(s1)
 lw t0,20(s1)
 lw a7, 16(s1)
 lw a3, 12(s1)
 lw a2, 8(s1)
 lw a1, 4 (s1)
 lw a0,0(s1)
 csrrw s1, mscratch, s1

 mret 





#configurando o HARDWARE
# O SOUL deve ter uma rotina de inicialização chamada "_start" que deve ser executada quando o sistema é ligado. Esta rotina deve: 
# 1- Configurar o GPT para gerar interrupção após  ms;
# Configurar o torque dos dois motores para zero;
# Configurar as articulações da cabeça do Uóli para a posição natural (Base = 31, Mid = 80, Top = 78);
# Configurar o tratamento de interrupções;
.globl _start
_start:
    # iniciliza o counter com zero
    la t0,counter
    sw zero,0(t0)



    # configurar o tratador de interrupções

    la t0, int_handler
    csrw mtvec, t0

    # habilitar interrupções global

    csrr t1,mstatus # seta o bit 7 (MPIE)
    ori t1,t1,0x80
    csrw mie,t1

    # ajusta o mscratch
    la t1,reg_buffer
    csrw mscratch,t1
    # pilha usuario
    la sp,pilha_usuario
    li t0,500000
    add sp,sp,t0
    # muda para o modo de usario

    csrr t1,mstatus
    li t2, 0x1800 
    and t1,t1,t2
    csrw mstatus,t1

    la t0,user
    csrw mepc,t0
  
 

    mret

# techo do codigo do usuario
.align 4
user:
    j main

# seção de dados

counter: .word 0x00000000
reg_buffer: .skip 48000
pilha_usuario: .skip 500000