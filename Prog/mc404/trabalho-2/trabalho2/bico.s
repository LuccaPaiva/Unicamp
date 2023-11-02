#LUCCA FERREIRA PAIVA 240229


.globl set_motor
.globl set_handbreak
.globl read_sensors
.globl read_sensor_distance
.globl get_time
.globl get_position
.globl get_rotation

# Implemente aqui as funções da API_CAR.
# As funções devem checar os parametros e fazer as chamadas de sistema que serão
# tratadas na camada SoCa

#erro retornar -1

set_motor:
    #a0 = desloc vertical (-1, 1)
    #a1 = desloc horizontal (-127, 127)
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    #verificar se valores estao nos intervalos corretos
    #verifica a0
      li t0, 1
      li t1, -1
      bgt a0, t0, erro1 #se a0 >  1
      #blt a0, t1, erro1 #se a0 < -1

    #verifica a1
      li t0, 127
      li t1, -127
      #bgtu a1, t0, erro1 #se a1 >  127
      #bgtu a1, t1, erro1 #se a1 < -127

    li a7, 10

    ecall
    li a0, 0

    fim1:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

    erro1:
      li a0, -1
      j fim1



set_handbreak:
    #a0 = 1 -> acionar freio de mao
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra
    #verificar se valores estao nos intervalos corretos

    #verifica a0
    li t0, 1
    bne a0, t0, erro2

    li a7, 11
    ecall

    fim2:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

    erro2:
      li a0, -1
      jal fim2

read_sensors:
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    li a7, 12
    ecall

    fim3:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

read_sensor_distance:
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    li a7, 13
    ecall

    fim4:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

get_time:
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    li a7, 14

    ecall

    fim5:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

get_position:
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    li a7, 15
    ecall

    fim6:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret

get_rotation:
    addi sp, sp, -16 # Aloca o quadro de pilha
    sw ra, 0(sp)     # Salva ra

    li a7, 16
    ecall

    fim7:
      lw ra, 0(sp)     # Restaura ra
      addi sp, sp, 16  # Desaloca o quadro de pilha
      ret
