	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000 
	DCD Reset_Handler 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	ldr R6,=RES
	mov R1,#0
	ldr R0,=val1
	ldr R2,[R0]
	ldr R0,=val2
	ldr R3,[R0]   ;r2/r3
up  cmp R2,R3     
	bcc store     ;branch if r2<r3
	sub R2,R3
	add R1,#1
	b up
store str R1,[R6],#4  ;quotient
	  str R2,[R6]     ;remainder
STOP
	B STOP
val1 DCD 7
val2 DCD 3
	AREA mydata,DATA,READWRITE
RES DCD 0
	END
	  
	