;Add two 32 bit numbers in code memory and store in data memory
	
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
		LDR R0, =A
		LDR R1, =RESULT
		MOV R2, #10
		MOV R3, #0
LOOP	LDR R4,[R0],#4
		ADDS R3,R4
		SUBS R2, #1
		BNE LOOP
		STR R3,[R1]
STOP
	B STOP
A DCD 1,2,3,4,5,6,7,8,9,10
	AREA data,DATA,READWRITE
RESULT DCD 0
	END