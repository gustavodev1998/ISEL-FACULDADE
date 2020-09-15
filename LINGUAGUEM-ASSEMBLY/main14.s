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

	values1:
			.word 0, 1, 2, 3, 4, 5
	
	values2:	
			.word -1, 2, -3, 4, 5, -6

	sum:	
			.word 0



main: 

	ldr r0, addr_values1
	ldr r1, addr_values2
	ldr r2, addr_sum

	mov r2, 0
	mov r3, 0 /* Indice I */
	mov r4, 12 /* Tamanho dos arrays em word */


		
	
for:
	cmp r3, r4
	bhs for_end

	bl mov1

	
	add r2, r2, r0 /* Sum += Retorno da Funcao */
	add r3, r3, 2 /* 2i++ - WORD */

	

	b for

	

for_end:
	mov r0, 0
	b .

mov1:
	push r5
	push r6

	ldr r5, [r0, r3]
	ldr r6, [r1, r3]
	

	eor r5, r5, r6 
	eor r6, r6, r5
	eor r5, r5, r6

	
	str r5, [r0, r3]
	str r6, [r1, r3]
	
	pop r6
	pop r5
	mov pc, lr

addr_values1:
	.word values1

addr_values2:
	.word values2

addr_sum:
	.word sum



