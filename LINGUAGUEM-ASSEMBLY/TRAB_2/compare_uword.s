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

	a:
		.word 5

	c: 	
		.word 10

main:
	push lr
	ldr r0, addr_a
	ldr r1, addr_c

	mov r2, 0
	bl	compare_uword
	b .

compare_uword:

	ldr r0, [r0]
	ldr r1, [r1]
	

	cmp r0,  r1


	beq condicao_1

	blo condicao_2

	b condicao_3
	
condicao_1:
	mov r0, r2
	mov pc, lr

condicao_2:
	sub r2, r2, 1
	mov r0, r2
	mov pc, lr

condicao_3:
	add r2, r2, 1
	mov r0, r2
	mov pc, lr

addr_a:
	.word a


addr_c:
	.word c 
