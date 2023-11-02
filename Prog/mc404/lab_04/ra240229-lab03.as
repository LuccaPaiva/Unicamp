inst1:
LOAD M(0x3FE)
ADD M(i)
STA M(carrega)
inst2:
LOAD M(0x3FF)
ADD M(i)
STA M(mult)
carrega:
LOAD MQ, M(0x3FE)
mult:
MUL M(0x3FF)
LOAD MQ
ADD M(sum)
STOR M(sum)
isum:
LOAD M(i)
ADD M(const1)
STOR M(i)
if:
LOAD M(0x3FD)
SUB M(i)

JUMP+ M(inst1)
fim:
LOAD M(sum)
JUMP M(0x400)

.align 1
.org 0x50
const1:
.word 1
i:
.word 0
sum:
.word 0

