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
	ldr r0,=src
	ldr r1,=dst
	ldr r2,[r0]
	mov r3,#0
	mla r3,r2,r2,r2
	lsr r3,#1
	str r3,[r1]
stop
	b stop
src DCD 6
	AREA mydata,DATA,READWRITE
dst DCD 0
	END
	  
	