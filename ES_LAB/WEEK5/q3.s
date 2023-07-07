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
	ldr r0,=arr
	ldr r1,=ele
	ldr r3,=result
	mov r5,#0x5
	mov r4,#0
	ldr r6,[r1]
l1
	ldr r2,[r0],#4
	cmp r2,r6
	beq done
	subs r5,#1
	cmp r5,#0
	bne l1
stop
	b stop
done
	mov r4,#1
	str r4,[r3]

arr dcd 1,2,3,4,5
ele dcd 6
	area mydata,data,readwrite
result dcd 0
	END
	  