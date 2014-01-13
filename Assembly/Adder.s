.equ SWI_SETSEG8, 0x200 @display on 8 Segment
.equ SWI_CheckBlack, 0x202 @check Black button
.equ SWI_CheckBlue, 0x203 @check press Blue button
.equ SWI_DRAW_INT, 0x205 @display an int on LCD
.equ SWI_CLEAR_DISPLAY,0x206 @clear LCD
.equ SWI_CLEAR_LINE, 0x208 @clear a line on LCD
.equ SEG_A, 0x80 @ patterns for 8 segment display
.equ SEG_B, 0x40 @byte values for each segment
.equ SEG_C, 0x20 @of the 8 segment display
.equ SEG_D, 0x08
.equ SEG_E, 0x04
.equ SEG_F, 0x02
.equ SEG_G, 0x01
.equ SEG_P, 0x10
.equ LEFT_BLACK_BUTTON,0x02 
.equ RIGHT_BLACK_BUTTON,0x01 
.equ BLUE_KEY_00, 0x01 @button(0)
.equ BLUE_KEY_01, 0x02 @button(1)
.equ BLUE_KEY_02, 0x04 @button(2)
.equ BLUE_KEY_03, 0x08 @button(3)
.equ BLUE_KEY_04, 0x10 @button(4)
.equ BLUE_KEY_05, 0x20 @button(5)
.equ BLUE_KEY_06, 0x40 @button(6)
.equ BLUE_KEY_07, 0x80 @button(7)
.equ BLUE_KEY_08, 1<<8 @button(8) 
.equ BLUE_KEY_09, 1<<9 @button(9)
.equ BLUE_KEY_10, 1<<10 @button(10)
.equ BLUE_KEY_11, 1<<11 @button(11)
.equ BLUE_KEY_12, 1<<12 @button(12)
.equ BLUE_KEY_13, 1<<13 @button(13)
.equ BLUE_KEY_14, 1<<14 @button(14)
.equ BLUE_KEY_15, 1<<15 @button(15)

RESET:
swi SWI_CLEAR_DISPLAY
mov r0,#0 @column
mov r1,#0 @row
mov r2,#0 @start with zero displayed
swi SWI_DRAW_INT
mov r3,#0

mov r0,#0
swi SWI_SETSEG8

BLUELOOP:
@wait for user to press a button
mov r0,#0

BB1:
swi SWI_CheckBlack @get button press into R0
cmp r0,#0
bne RESET

swi SWI_CheckBlue @get button press into R0
cmp r0,#0
beq BB1 @ if zero, no button pressed

cmp r0,#BLUE_KEY_15
beq FIFTEEN
cmp r0,#BLUE_KEY_14
beq FOURTEEN
cmp r0,#BLUE_KEY_13
beq THIRTEEN
cmp r0,#BLUE_KEY_12
beq TWELVE
cmp r0,#BLUE_KEY_11
beq ELEVEN
cmp r0,#BLUE_KEY_10
beq TEN
cmp r0,#BLUE_KEY_09
beq NINE
cmp r0,#BLUE_KEY_08
beq EIGHT
cmp r0,#BLUE_KEY_07
beq SEVEN
cmp r0,#BLUE_KEY_06
beq SIX
cmp r0,#BLUE_KEY_05
beq FIVE
cmp r0,#BLUE_KEY_04
beq FOUR
cmp r0,#BLUE_KEY_03
beq THREE
cmp r0,#BLUE_KEY_02
beq TWO
cmp r0,#BLUE_KEY_01
beq ONE
mov r1,#0 @A button is pressed, but it doesn't compare with
mov r0,#0 @ the rest, so it must be zero.
BL Display8Segment
bal BLUELOOP

ONE:
mov r0,#-1
BL ADD
BL Display8Segment
bal BLUELOOP

TWO:
mov r0,#2
BL ADD
BL Display8Segment
bal BLUELOOP

THREE:
mov r0,#3
BL ADD
BL Display8Segment
bal BLUELOOP

FOUR:
mov r0,#4
BL ADD
BL Display8Segment
bal BLUELOOP

FIVE:
mov r0,#5
BL ADD
BL Display8Segment
bal BLUELOOP

SIX:
mov r0,#6
BL ADD
BL Display8Segment
bal BLUELOOP

SEVEN:
mov r0,#7
BL ADD
BL Display8Segment
bal BLUELOOP

EIGHT:
mov r0,#8
BL ADD
BL Display8Segment
bal BLUELOOP

NINE:
mov r0,#9
BL ADD
BL Display8Segment
bal BLUELOOP

TEN:
mov r0,#10
BL ADD
BL Display8Segment
bal BLUELOOP

ELEVEN:
mov r0,#11
BL ADD
BL Display8Segment
bal BLUELOOP

TWELVE:
mov r0,#12
BL ADD
BL Display8Segment
bal BLUELOOP

THIRTEEN:
mov r0,#13
BL ADD
BL Display8Segment
bal BLUELOOP

FOURTEEN:
mov r0,#14
BL ADD
BL Display8Segment
bal BLUELOOP

FIFTEEN:
mov r0,#15
BL ADD
BL Display8Segment
bal BLUELOOP

ADD:
stmfd sp!,{r0-r2,lr}
add r3,r3,r0
mov r0,#0
mov r1,#0
mov r2,r3
swi SWI_DRAW_INT
ldmfd sp!,{r0-r2,pc}

@ ===== Display8Segment (Number:R0; Point:R1)
@ Displays the number 0-F in R0 on the 8-segment display
@ If R1 = 1, the point is also shown
Display8Segment:
stmfd sp!,{r0-r2,lr}
ldr r2,=Digits
ldr r0,[r2,r0,lsl#2]
swi SWI_SETSEG8
ldmfd sp!,{r0-r2,pc}
@ ================================================
.data
Digits:
.word SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G @0
.word SEG_B|SEG_C @1
.word SEG_A|SEG_B|SEG_F|SEG_E|SEG_D @2
.word SEG_A|SEG_B|SEG_F|SEG_C|SEG_D @3
.word SEG_G|SEG_F|SEG_B|SEG_C @4
.word SEG_A|SEG_G|SEG_F|SEG_C|SEG_D @5
.word SEG_A|SEG_G|SEG_F|SEG_E|SEG_D|SEG_C @6
.word SEG_A|SEG_B|SEG_C @7
.word SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G @8
.word SEG_A|SEG_B|SEG_F|SEG_G|SEG_C @9
.word SEG_A|SEG_G|SEG_B|SEG_C|SEG_E|SEG_F|SEG_P @A
.word SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_F|SEG_G|SEG_P @B
.word SEG_A|SEG_G|SEG_D|SEG_E|SEG_P @C
.word SEG_A|SEG_B|SEG_C|SEG_D|SEG_E|SEG_G|SEG_P @D
.word SEG_A|SEG_G|SEG_F|SEG_E|SEG_D|SEG_P @E
.word SEG_A|SEG_G|SEG_F|SEG_E|SEG_P @F
.word 0 @Blank display
.end
