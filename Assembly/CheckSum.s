@@@ OPEN INPUT FILE, READ INTEGER FROM FILE, PRINT IT, CLOSE INPUT FILE
.equ SWI_Open, 0x66 @open a file
.equ SWI_Close,0x68 @close a file
.equ SWI_PrStr, 0x69 @ Write a null-ending string
.equ SWI_PrInt,0x6b @ Write an Integer
.equ SWI_RdStr,0x6a @ Read a String from a file
.equ Stdout, 1 @ Set output target to be Stdout
.equ SWI_Exit, 0x11 @ Stop execution
.global _start
.text
_start:
ldr r0,=InFileName @ set Name for input file
mov r1,#0 @ mode is input
swi SWI_Open @ open file for input
bcs InFileError @ Check Carry-Bit (C): if= 1 then ERROR
@ Save the file handle in memory:
ldr r1,=InFileHandle @ if OK, load input file handle
str r0,[r1] @ save the file handle

ldr r0,=InFileHandle
ldr r0,[r0]
ldr r1,=CharArray
mov r2,#1024
swi SWI_RdStr

RLoop:

ldrb r3,[r1] @loads a byte from the string into r3
add r1,r1,#1
cmp r3,#0
add r4,r4,r3

beq EofReached @ branch if null
bal RLoop @ keep reading till end of file
@ == End of file =============================================== End Loop

EofReached:
mov r5,#255
and r4,r4,r5
sub r4,r5,r4

mov r0, #Stdout @ print last message
ldr r1, =EndOfFileMsg
swi SWI_PrStr
mov r0, #Stdout
mov r1,r4
swi SWI_PrInt

@ == Close a file ===============================================
ldr r0, =InFileHandle @ get address of file handle
ldr r0, [r0] @ get value at address
swi SWI_Close

Exit:
swi SWI_Exit @ stop executing

InFileError:
mov r0, #Stdout
ldr r1, =FileOpenInpErrMsg
swi SWI_PrStr
bal Exit @ give up, go to end

.data
.align
InFileHandle: .skip 4
InFileName: .asciz "udp.dat"
CharArray: .skip 1025
FileOpenInpErrMsg: .asciz "Failed to open input file \n"
EndOfFileMsg: .asciz "The Check sum is: "
.end



