;Subtract two 32 bit numbers in code memory and store in data memory
	
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
	LDR R0, =AA
	LDR R1, [R0]
	LDR R0, =BB
	LDR R2, [R0]
	SUBS R3, R1, R2
	LDR R4, =RESULT
	STR R3, [R4]
STOP
	B STOP
AA DCD 0x99999999
BB DCD 0x22224444
	AREA data,DATA,READWRITE
RESULT DCD 0
	END