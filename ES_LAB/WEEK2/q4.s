	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x40001000  
	DCD Reset_Handler 
 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =N1 
	LDR R1, =N2
	LDR R4, =DST
	MOV R5,#4
	LDR R6, =0xffffffff
	MSR xpsr,R6
	MOV R8,#0
	LDR R2,[R0],#4
	LDR R3,[R1],#4
LOOP	sbcs R7,R2,R3
		ADC R8,#0
		STR R7,[R4],#4
		LDR R2,[R0],#4
		LDR R3,[R1],#4
		CMP R8,#0
		BEQ RES
		SUBS R5,#1
		MRS R9,xpsr
		ORR R9,#0x20000000
		MSR xpsr,R9
		BNE LOOP
		b STOP
		
RES	    SUBS R5,#1
		MRS R9,xpsr
		AND R9,#0xdfffffff
		MSR xpsr,R9
		BNE LOOP
STOP
	B STOP
N1 DCD 8,7,6,5 
N2 DCD 1,1,1,1 
	AREA data, DATA, READWRITE
DST DCD 0
	END