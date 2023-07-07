	AREA RESET,DATA,READONLY
	EXPORT __Vectors
		
__Vectors
	DCD 0x10001000 
	DCD Reset_Handler 
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
		
Reset_Handler
	ldr r0,=input
	ldr r1,=result
	ldr r2,[r0]
	bl fact
	str r2,[r1]
here 
	b here
fact 
	push {r3,lr}
	mov r3,r2
	cmp r2,#0
	bne down
	mov r2,#1
	b down1
down
	sub r2,#1
	bl fact
	mov r4,r3
	mul r2,r4
down1
	pop {r3,lr}
	bx lr
input  dcd 0x3
	area mydata,data,readwrite
result dcd 0
	END
	  