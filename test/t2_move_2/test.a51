	org 0x0
start:
	; MOV direct,#data
	MOV 0x30, #0x00
	MOV 0x31, #0x11
	MOV 0x32, #0x22
	MOV 0x33, #0x33
	MOV 0x34, #0x44
	MOV 0x35, #0x55
	MOV 0x36, #0x66
	MOV 0x37, #0x77
	
	; MOV Rn,direct
	MOV R0, 0x30
	MOV R1, 0x31
	MOV R2, 0x32
	MOV R3, 0x33
	MOV R4, 0x34
	MOV R5, 0x35
	MOV R6, 0x36
	MOV R7, 0x37
	
	; MOV direct,direct
	MOV 0x20, 0x30
	MOV 0x21, 0x31
	MOV 0x22, 0x32
	MOV 0x23, 0x33
	MOV 0x24, 0x34
	MOV 0x25, 0x35
	MOV 0x26, 0x36
	MOV 0x27, 0x37
	
	; MOV A,direct
	MOV A, 0x37
	
	sjmp $
	
; for test
REG_SP		EQU	0x1000
REG_A		EQU	0x1001
REG_B		EQU	0x1002
REG_PSW		EQU	0x1003
REG_PC		EQU	0x1004
REG_DPTR	EQU	0x1005
CYCLE		EQU 0x1006
REG_R0		EQU	0x2000
REG_R1		EQU	0x2001
REG_R2		EQU	0x2002
REG_R3		EQU	0x2003
REG_R4		EQU	0x2004
REG_R5		EQU	0x2005
REG_R6		EQU	0x2006
REG_R7		EQU	0x2007
REG_END		EQU	0x2FFF
	org 0x600
	dW  REG_SP,		0x7
	dW  REG_A,		0x77
	dW  REG_B,		0x0
	dW  REG_PC,		0x42
	dw  REG_DPTR,	0x0
	dw 	CYCLE,		51
	dW  REG_R0,		0x00
	dW  REG_R1,		0x11
	dW  REG_R2,		0x22
	dW  REG_R3,		0x33
	dW  REG_R4,		0x44
	dW  REG_R5,		0x55
	dW  REG_R6,		0x66
	dW  REG_R7,		0x77
		
	dW  0x20,		0x00
	dW  0x21,		0x11
	dW  0x22,		0x22
	dW  0x23,		0x33
	dW  0x24,		0x44
	dW  0x25,		0x55
	dW  0x26,		0x66
	dW  0x27,		0x77

	dW  0x30,		0x00
	dW  0x31,		0x11
	dW  0x32,		0x22
	dW  0x33,		0x33
	dW  0x34,		0x44
	dW  0x35,		0x55
	dW  0x36,		0x66
	dW  0x37,		0x77
	dw  REG_END,	0
	end		