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
	ldr r0,=num
	ldr r6,=result
	mov r2,#0
	mov r5,#0
	ldr r4,[r0]
up1 cmp r4,#100
	blo L1
	subs r4,#100
	add r2,r2,#1
	bne up1
L1  cmp r4,#10
	blo L2
	subs r4,#10
	add r5,r5,#1
	bne L1
L2  lsl r5,r5,#4
	orr r8,r4,r5
	lsl r9,r2,#8
	orr r9,r8,r9
	str r9,[r6]
	
stop
	b stop
num dcd 0x15
	area mydata,data,readwrite
result dcd 0,0,0,0,0
	END
	  