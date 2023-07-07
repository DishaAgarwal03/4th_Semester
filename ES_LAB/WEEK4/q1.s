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
	ldr r0,=n1
	ldr r10,=dst
	ldr r1,[r0]
	mov r2,#0xa
	mov r3,#0
	mov r4,#1
	mov r5,#0xf
up  mov r6,r1
	and r6,r5
	mla r3,r6,r4,r3
	mul r4,r2
	lsr r1,#4
	cmp r1,#0
	bne up
	str r3,[r10]
stop
	b stop
n1 dcd 0x12
	area mydata,data,readwrite
dst dcd 0
	END
	  