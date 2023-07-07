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
		LDR R0, =VALUES
		LDR R1, =DST
		MOV R2,R0
		ADD R2,#36
		MOV R3,#10
UP		LDR R4,[R2],#-4
		STR R4,[R1],#4
		SUBS R3,#1
		BNE UP
STOP
		B STOP
VALUES DCD 1,2,3,4,5,6,7,8,9,10
		AREA mydata,DATA,READWRITE
DST DCD 0
		END