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
string1:
	.asciz "arquitetura"
string1_end:

.text

main:
	push lr
	ldr r0, addr_string1
	mov r1, 0
count:
	ldrb r2, [r0, r1]
	add r2, r2, 0
	beq done
	add r1, r1, 1
	b count
done:
	mov r0, r1
	pop pc

addr_string1:
	.word string1


