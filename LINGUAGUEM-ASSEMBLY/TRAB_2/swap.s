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
		.byte 1, 2, 4, 3, 10

	c: 	
		.byte 5, 6, 7, 8, 12
	
	len:
		.word 4

main:
	push lr
	ldr r0, addr_a
	ldr r1, addr_c
	ldr r2, addr_len
	ldr  r2, [r2]
	
	mov r3, 0 /* r3 - i */
	bl	swap
	b .

swap:
	
	cmp r3, r2 /* i - array_size */
	beq 	size_equal

	ldrb r4, [r0, r3]
	ldrb r5, [r1, r3]

	eor r4, r4, r5 
	eor r5, r5, r4
	eor r4, r4, r5
	
	strb r4, [r0, r3]
	strb r5, [r1, r3]
	

	add r3, r3, 1 /* ++i */
	b swap


size_equal:
	
	mov pc, lr

addr_a:
	.word a

addr_c:
	.word c 

addr_len:
	.word len

