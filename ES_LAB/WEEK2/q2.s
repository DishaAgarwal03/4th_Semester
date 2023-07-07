;Add two 4*32 bit numbers in code memory and store in data memory
	
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
		
N1 DCD 1,2,0xffffffff,0x11111111
N2 DCD 1,2,3,4
	AREA data,DATA,READWRITE
DST DCD 0
	
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	LDR R0, =N1
	LDR R1, =N2
	LDR R2, [R0]
	LDR R3, [R1]
	LDR R4, =DST
	MOV R5, #4
	MOV R6, #0
LOOP	ADDS R2,R6
		MOV R6,#0
		ADC R6,#0
		ADDS R2,R3
		ADC R6,#0
		STR R2,[R4],#4
		LDR R2,[R0,#4]!
		LDR R3,[R1,#4]!
		SUBS R5,#1
		BNE LOOP
		STR R6,[R4]
STOP
	B STOP
	END