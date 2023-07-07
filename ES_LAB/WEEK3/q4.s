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
	ldr r0,=num
	ldr r3,=res
	mov r6,#0x0A
	ldrb r1,[r0],#1
	and r2,r1,#0xF0
	lsr r2,#4
	cmp r2,r6
	bcc hexx
	add r2,#7
hexx
	add r2,#0x30
	strb r2,[r3],#1
	and r4,r1,#0x0F
	cmp r4,r6
	bcc hexxx
	add r4,#7
hexxx
	add r4,#0x30
	strb r4,[r3]

stop
	b stop
num DCB 0xA0
	AREA mydata,DATA,READWRITE
res DCB 0
	END
	  
	