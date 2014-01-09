@-Read integers from "in.txt"
@   -Store as a stack using STMFD
@-Sort integers
@   -Start at index 0
@   -smallest_index = index
@   -test_index = smallest_index + 1
@   -Find smallest value in array
@      -if array[test_index] < array[smallest_index]
@         -smallest_index = test_index
@      -test_index + 1
@   -Swap 
@      -temp = array[index]
@      -array[index] = array[smallest_index]
@      -array[smallest_index] = temp
@      -Write array[smallest_index] to "sorted.txt"

.equ SWI_Open, 0x66 @open a file
.equ SWI_Close,0x68 @close a file
.equ SWI_PrStr, 0x69 @ Write a null-ending string
.equ SWI_PrInt,0x6b @ Write an Integer
.equ SWI_RdInt,0x6c @ Read an Integer from a file
.equ SWI_RdStr,0x6a @ Read a String from a file
.equ Stdout, 1 @ Set output target to be Stdout
.equ SWI_Exit, 0x11 @ Stop execution
.global _start
.text
_start:
@ open input file
ldr r0,=InFileName @ set Name for input file
mov r1,#0 @ mode is input
swi SWI_Open @ open file for input
bcs FileError @ Check Carry-Bit (C): if= 1 then ERROR
@ Save the file handle in memory:
ldr r1,=FileHandle @ if OK, load input file handle
str r0,[r1] @ save the file handle

mov r9,r13
sub r9,r9,#4 @ start of the stack
Store:
ldr r0,=FileHandle @ load input file handle
ldr r0,[r0]
swi SWI_RdInt @ read the integer into R0
bcs CloseIn @ branch into sort after all values are read and stored
stmfd r13!,{r0} @ push onto a stack, full descending
mov r8,r13 @ end of the stack
bal Store

CloseIn: @ close input file
ldr r0, =FileHandle @ get address of file handle
ldr r0, [r0] @ get value at address
swi SWI_Close

mov r6,r9

Sort:
mov r13,r6 
ldmfd r13,{r1}
mov r13,r8 @ resets stack pointer to the end of the stack
ldmda r13,{r2}

InnerLoop: @ find the smallest integer
cmp r2,r1
movlt r1,r2
movlt r3,r13
ldmed r13!,{r2}

cmp r6,r13
blt OuterLoop @ when r9 and r13 are equal, branch
bal InnerLoop

OuterLoop: @ Swap the integers
mov r13,r6
ldmfd r13,{r4} @ temp
stmed r13,{r1}
mov r13,r3
stmed r13,{r4}
mov r3,r6
sub r3,r3,#4

sub r6,r6,#4 @ increment the beginning of the stack
cmp r6, r8

blt OutFile
bal Sort @ keep reading till end of file

OutFile: @ open file for output
ldr r0,=OutFileName @ set Name for output file
mov r1,#1 @ mode is out
swi SWI_Open @ open file for output
bcs FileError @ Check Carry-Bit (C): if= 1 then ERROR
ldr r1,=FileHandle @ if OK, load input file handle
str r0,[r1] @ save the file handle
mov r13,r9

ReadOut:
ldmfa r13!,{r1}
@mov R0,#Stdout @ target is Stdout
swi SWI_PrInt
ldr r1,=Space
swi SWI_PrStr
cmp r13,r8 @ r8 is the end of  the stack

blt CloseOut @ when r13 and r8 are the same, branch
bal ReadOut

CloseOut: @ close out file
ldr r0, =FileHandle @ get address of file handle
ldr r0, [r0] @ get value at address
swi SWI_Close

Exit:
swi SWI_Exit @ stop executing

FileError:
mov r0, #Stdout
ldr r1, =FileOpenErrMsg
swi SWI_PrStr
bal Exit @ give up, go to end

.data
.align
FileHandle: .skip 4
InFileName: .asciz "in.txt"
OutFileName: .asciz "sorted.txt"
Space: .asciz " "
FileOpenErrMsg: .asciz "Failed to open file \n"
.end




