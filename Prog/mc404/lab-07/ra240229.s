# Entrada: a0: descritor do arquivo (fd)
#          a1: apontador para o buffer
#          a2: número de bytes a ser lido
# Saída:   a0: número de bytes lidos pela syscall re

read:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  li a0, 0         #stdin
  li  a7, 63       # Código da syscall: 63 == read
  ecall            # Invoca o sistema operacional
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret              # Retorna resultado em

#Retorna em a4 o int correspondente
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
  li a0, 1         # stdout
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
    li a2, 1
    jal write

  digit2:
    la t0, var
    addi t2, t2, 48
    sw t2, 0(t0)
    mv a1, t0
    li a2, 1
    jal write

  digit3:
    la t0, var
    addi t3, t3, 48
    sw t3, 0(t0)
    mv a1, t0
    li a2, 1
    jal write

  digit4:
    la t0, var
    addi t4, t4, 48
    sw t4, 0(t0)
    mv a1, t0
    li a2, 1
    jal write



  fim:
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret


print_pos:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  la t0, pos       #endereco de "POS: "
  mv a1, t0
  li a2, 5
  jal write
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret

print_esp:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  la t0, var
  li t1, 0x20      #t1 = " "
  sw t1, 0(t0)
  mv a1, t0
  li a2, 1
  jal write
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret

print_ent:
  addi sp, sp, -16 # Aloca o quadro de pilha
  sw ra, 0(sp)     # Salva ra
  la t0, var
  li t1, 0x0A      #t1 = "\n"
  sw t1, 0(t0)
  mv a1, t0
  li a2, 1
  jal write
  lw ra, 0(sp)     # Restaura ra
  addi sp, sp, 16  # Desaloca o quadro de pilha
  ret

#--------------------------Inializacoes e Constantes-----------------------------------------

.globl _start
_start:
.text

x0:
  jal le_int
  mv s0, a4 #s0 = x0

y0:
  jal le_int
  mv s1, a4 #s0 = x0

#pula linha de P2
jal le_int

C:
  jal le_int
  mv s2, a4 #s9 = L

L:
  jal le_int
  mv s3, a4 #s3 = C

CMAX:
  li a1, 1 #le um caractere
  jal le_int
  mv s4, a4 #s4 = Cmax



#-------------------------------Leitura das Linhas----------------------------
li s5, 0 #s5 = i = 0

nova_linha:
  li s6, 0              #s6 = j = 0
  beq s5, s3, final     #i = L --> terminar programa
  mv s7, s0
  addi s7, s7, -1       #t1 = x - 1 --> gurdar 3x n

  coluna:
    beq s6, s7, verificacao #se nao for um q preciso, e so ler o valor e seguir
    beq s6, s2, decisao     #j = C --> proxima linha
    jal le_int              #le proximo valor mas n guarda
    addi s6, s6, 1          #j++
    jal coluna              #verificar proximo elemento

    verificacao:
      jal le_int
      mv s8, a4  #s8  = x - 1
      jal le_int
      mv s9, a4  #s9  = x
      jal le_int
      mv s10, a4 #s10 = x + 1
      addi s6, s6, 3
      jal coluna

    decisao:
      beqz s9, end_coluna #se X = 0 nao precisa mudar
      beqz s8, xmenos
      beqz s10, xmais
      jal menor


    menor:
      bgt s8, s9, 2f #s8 > s9
      1: #s8 < s9
        bgt s10, s8, 4f #s10 > s8
        3: #s10 < s8
          jal xmais  #| s10, s8, s9
        4: #s10 > s8
          jal xmenos #| s8, s10, s9 | s8, s9, s10

      2: #s8 > s9
        bgt s10, s8, 6f #s10 > s8
        5: #s10 < s8
          bgt s10, s9, 8f
          7: #s10 < s9
            jal xmais       #| s10, s9, s8
          8: #s10 > s9
            jal end_coluna  #| s9, s10, s8
        6:
          jal end_coluna    #| s9, s8, s10

    xmenos:
      addi s0, s0, -1
      jal end_coluna
    xmais:
      addi s0, s0, 1
      jal end_coluna

  end_coluna: #nova linha
    #atualiza X, Y, i, j e imprime na tela
    addi s1, s1, 1

    jal print_pos  #print "POS: "
    mv a4, s0
    jal print_int  #print X
    jal print_esp  #print " "
    mv a4, s1
    jal print_int  #print Y
    jal print_ent  #print "\n"

    addi s5, s5, 1 #i++
    jal nova_linha


final:

li a0, 0 # exit code
li a7, 93 # syscall exit
ecall
#-----------------------------------------------------------

.section .rodata
pos:  .asciz "POS: "  #coloca a string na memoria

.section .data

.align 4
var: .word 0
.align 4
