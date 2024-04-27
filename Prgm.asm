sys_exit	equ	1
sys_read	equ	3
sys_write	equ	4
stdin	equ	0
stdout	equ	1
stder	equ	3
section	.data
	userMsg	db	'Enter an Integer:'
	lenUserMsg	equ	$-userMsg
	displayMsg	db	'You entered: '
	lenDisplayMsg	equ	$-displayMsg
	newline	db	0xA
	Ten	DW	10
	Result	db	'Ans = '
	ResultValue	db	'aaaaa'
	db	0xA
	ResultEnd	equ	$-Result
	num	times	6	db	'ABCDEF'
	numEnd	equ	$-num
section	.bss
	TempChar	RESB	1
	testchar	RESB	1
	ReadInt	RESW	1
	Tempint	RESW	1
	negflag	RESB	1
	A	RESW	1
	B	RESW	1
	C	RESW	1
	Y	RESW	1
	X	RESW	1
	Z	RESW	1
	M	RESW	1
	N	RESW	1
	Temp1	RESW	1
	Temp2	RESW	1
	Temp3	RESW	1
	Temp4	RESW	1
	Temp5	RESW	1
	Temp6	RESW	1
	Temp7	RESW	1
	Temp8	RESW	1
	Temp9	RESW	1
	Temp10	RESW	1
	global	_start
section	.text
_start:
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[A],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[B],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[C],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[Y],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[X],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[Z],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[M],ax
	call	PrintString
	call	GetAnInteger
	move	ax,[ReadInt]
	move	[N],ax
	mov	ax,[A] 
	cmp	ax,[B]
	JLE L1
	mov	ax,[C] 
	cmp	ax,[D]
	JNE L2
	mov	ax,[X] 
	mov	[Y],ax
	L3
	mov	ax,[Z] 
	mov	[Y],ax
	L4
	mov	ax,[N] 
	mov	[M],ax
	mov	ax,[A] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[B] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[C] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[Y] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[X] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[Z] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[M] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
	mov	ax,[N] 
	call	ConvertIntegerToString
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, Result
	edx, ResultEnd
	int	80h
fini:
	mov	eax,sys_exit
	xor	ebx,ebx
	int	80h
PringString:
	push	ax
	push	dx
	mov	eax, 4
	mov	ebx, 1
	mov	ecx,	userMsg
	mov	edx,	lenUserMsg
	int	80h
	pop	dx
	pop	ax
	ret
GetAnInteger
	mov	eax, 3
	mov	ebx, 2
	mov	ecx,num
	mov	edx, 6
	int	0x80
	mov	edx,eax
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, num
	int	80h
ConvertStringToInteger:
	mov	ax, 0
	mov	[ReadInt], ax
	mov	ecx,num
	mov	bx, 0
	mov	bl, byte [ecx]
Next:	sub	bl,'0'
	mov	ax,[ReadInt]
	mov	dx, 10
	mul	dx
	add	ax,bx
	mov	[ReadInt],ax
	mov	bx,0
	add	ecx,1
	mov	bl, byte[ecx]
	cmp	bl,0xA
	jne	Next
	ret
ConvertIntegerToString:
	mov	ebx, ResultValue + 4
ConvertLoop:
	sub	dx, dx
	mov	cx, 10
	div	cx
	add	dl, '0'
	move	[ebx], dl
	dec	ebx
	cmp	ebx, ResultValue
	jge	ConvertLoop
	ret
