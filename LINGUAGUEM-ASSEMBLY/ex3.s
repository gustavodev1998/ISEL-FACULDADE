	.section .startup
	b	_start
	b	.
_start:
	ldr	sp, addr_stack_top
	ldr	r0, addr_main
	mov	r1, pc
	add	lr, r1, 4
	mov	pc, r0
	b	.

addr_stack_top:
	.word	stack_top
addr_main:
	.word	main

	.section .stack
stack:
	.space	1024
stack_top:


	.data
m:
	.byte	20
n:
	.byte	3
p:
	.word	0x345
q:
	.word	0xFFFF



main:
	ldr 	r0, addr_m
	ldrb 	r1, [r0]	/* r1 = 20 */
	push 	r1
	ldr 	r0, addr_n
	ldrb 	r1, [r0]	/* r1 = 3 */
	push 	r1
	ldr 	r0, addr_p
	ldr 	r1, [r0]	/* r1 = 0x345 */
	push 	r1
	ldr 	r0, addr_q
	ldr 	r1, [r0]	/* r1 = 0xFFFF */
	push 	r1
	pop		r0
	pop		r0
	pop		r0
	pop		r0
	b	.
	
	
addr_m:
	.word	m
addr_n:
	.word	n
addr_p:
	.word	p
addr_q:
	.word	q

