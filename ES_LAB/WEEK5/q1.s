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
	ldr r0,=dst
l2
	mov r1,r0
	mov r3,r0
	add r10,r9,#1
l1
	ldr r4,[r3]
	ldr r7,[r1]
	cmp r4,r7
	bcs up
	mov r1,r3
up
	add r3,#4
	add r10,#1
	cmp r10,#5
	bne l1
	ldr r2,[r0]
	ldr r6,[r1]
	str r2,[r1]
	str r6,[r0]
	add r0,#4
	add r9,#1
	cmp r9,#4
	bne l2
here 
	b here
	area mydata,data,readwrite
dst dcd 0,0,
	END
	  