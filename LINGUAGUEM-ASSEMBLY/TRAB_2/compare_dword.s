	.section .startup
	b _start
	b .
_start:
	ldr sp, addr_stack_top
	ldr r0, addr_main
	mov r1, pc
	add lr, r1, 4
	mov pc, r0
	b .

addr_stack_top:
	.word stack_top

addr_main:
	.word main

	.section .stack

stack:
	.space 1024
stack_top:


.data

	aH:
		.word 0x8000, 0x0000

	cH:
		.word 0xFFFF, 0xFFFF

main:
	push lr
	ldr r0, addr_Aalta
	ldr r1, addr_Calta
	bl	compare_dword
	b .

compare_dword:

	push r2
	push r3
	ldr r2, [r0]	
	ldr r3, [r1]
	cmp r2,  r3
	beq condicao_high
	blt condicao_2
	b condicao_3
	

condicao_high:	

	ldr r2, [r0,2]
	ldr r3, [r1,2]
	cmp r2, r3
	beq condicao_1
	blo condicao_2
	b condicao_3

condicao_1:

	mov r0, 0
	pop r3
	pop r2
	mov pc, lr
	
condicao_2:

	mov r0, 0
	sub r0, r0, 1
	pop r3
	pop r2
	mov pc, lr

condicao_3:

	mov r0, 1
	pop r3
	pop r2
	mov pc, lr


addr_Aalta:
	.word aH


addr_Calta:
	.word cH

