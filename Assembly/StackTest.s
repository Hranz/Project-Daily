@Stack test

.global _start
.text
_start:

mov r3,r13
mov r0,#1
mov r1,#2
mov r2,#3
stmfa r13!,{r0-r2}
@ldmfd r13!,{r0-r2}
mov r0,#4
mov r1,#5
mov r2,#6
stmfa r13!,{r0-r2}
mov r13,r3
ldmfdcc r13,{r0-r2}
@cmp r0,0x81818181
addeq r13,r13,#4
moveq r13,r0
cmpeq r13,r0




@exit
swi 0x11
