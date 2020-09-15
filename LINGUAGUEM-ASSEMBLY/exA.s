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
stringsearch:
	.asciz "leonor"
stringsearch_end:

.text

main:
	push lr
	ldr r0, addr_stringsearch
	mov r1, 0 /* indice i */
	mov r2, 101 /* letra "e" */
	mov r4, 0 /* Null */
count:
	ldrb r3, [r0, r1]
	cmp r3, r2 /* array[i] != value */
	beq finish
	
	cmp r3, r4 /* Verifica se o caracter estava contido na string */
	beq finish_neg


	add r1, r1, 1 /* ++i */
	b count
	


finish:
	mov r0, r1
	pop pc


finish_neg:
	mov r0, 0
	sub r0, r0, 1
	pop pc

addr_stringsearch:
	.word stringsearch


