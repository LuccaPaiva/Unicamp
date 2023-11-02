.org 0x000
comeco:
LOAD MQ,M(0x105)
MUL M(const10)
LOAD MQ
STOR M(y)
halfk:
LOAD M(y)
DIV M(const2)
LOAD MQ
STOR M(k)
loop:
LOAD M(y)
DIV M(k)
LOAD MQ
ADD M(k)
DIV M(const2)
LOAD MQ
STOR M(k)
isum:
LOAD M(i)
ADD M(const1)
STOR M(i)
if:
LOAD M(const10)
SUB M(i)
JUMP+ M(loop)
fim:
LOAD M(k)
JUMP M(0x400)

.align 1
.org 0x090
const1:
.word 1
const2:
.word 2
const10:
.word 10
i:
.word 1
k:
.word 0
y:
.word 0
