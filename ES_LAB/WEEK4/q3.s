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
	ldr r2,[r0]
	ldr r0,=n2
	ldr r3,[r0]
	ldr r0,=sum
	mov r6,#0
up  mov r7,r2
	mov r8,r3
	and r7,#0xf
	add r7,r6
	mov r6,#0
	and r8,#0xf
	bl addn
	lsr r3,#4
	lsr r2,#4
	cmp r2,#0
	beq down
	b up
down cmp r3,#0
     beq st
	 b up
st  ldr r1,=sum
	ldr r5,=pack
	sub r4,r0,r1
up1 ldrb r9,[r1],#1
	ldrb r10,[r1],#1
	lsl r10,#4
	orr r10,r9
	strb r10,[r5],#1
	sub r4,#2
	cmp r4,#1
	bge up1
	strb r6,[r5]
stop
	b stop
addn adds r7,r8
	 cmp r7,#0xa
	 bcc store
	 sub r7,#0xa
	 add r6,#01
store strb r7,[r0],#1
	  bx lr
	  
n1 dcd 0x15
n2 dcd 0x23	
	area mydata,data,readwrite
sum dcd 0,0,0,0,0
pack dcd 0 
	END
	  