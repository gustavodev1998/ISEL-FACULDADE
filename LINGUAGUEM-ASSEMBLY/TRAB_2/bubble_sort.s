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

	elems:
		.byte 1, 4, 3, 2

	len:
		.word 4

	size:
		.word 1


main:
	push lr
	ldr r0, addr_elems
	ldr r1, addr_len
	ldr r2, addr_size

	ldr  r1, [r1]
	ldr  r2, [r2]
	

	bl	bubble_sort
	b .




addr_elems:
	.word elems

addr_len:
	.word len

addr_size:
	.word size




bubble_sort:

	mov r3, r1 /* r3 - i */
	sub r3, r3, 1

	mov r4, 0 /* r4 - j */

	mov r5, 0 /* Comparador para com 0 */
	mov r11, lr /* Guarda o endereço de retorno do bubble_sort */

return_i:

	cmp r5, r3
	bhs end

	mov r9, r0 /* Guarda os valores de elems */ 
	/*mov r10, r1*/ /* Guarda os valores de len */ 

	add r1, r0, r2
	
	mov r7, r1
	ldrb r0, [r0]
	ldrb r1, [r1]

	mov r6, 0	/* Swapped = 0 */
	

return_j:

	cmp r4, r3	/* For de Indice J */
	bhs for_end

	blo if_state
	

if_end:
	
	ldrb r0, [r7]
	add r7, r7, 1
	ldrb r1, [r7]
	
	add r4, r4, 1

	b return_j

if_state:
	push r0

	bl compare_byte /* Argumentos por Ordem */
	
	cmp r0, r5  
	
	pop r0

	bge swap_condition

	
	b if_end

swap_condition:

	push r0
	push r1
	push r3
	push r4
	push r5


	mov r1, r7
	sub r7, r7, r2
	mov r0, r7
	add r7, r7, r2
	
	bl swap
		
	pop r5
	pop r4
	pop r3	
	pop r1
	pop r0
	
	

	add r6, r6, 1 /* Swapped = 1 */
	
	b if_end

end:

	mov pc, r11


swap:
	mov r3, 0

swap_next:

	cmp r3, r2 /* i - array_size */
	beq 	size_equal

	ldrb r4, [r0,r3]
	ldrb r5, [r1,r3]

	eor r4, r4, r5 
	eor r5, r5, r4
	eor r4, r4, r5
	
	strb r4, [r0,r3]
	strb r5, [r1,r3]
	

	add r3, r3, 1 /* ++i */
	b swap_next


size_equal:
	
	mov pc, lr

compare_byte:

	lsl r0, r0, 8
	lsl r1, r1, 8

	cmp r0,  r1

	beq condicao_1

	blt condicao_2

	b condicao_3
	
condicao_1:

	mov r0, 0
	mov pc, lr
	

condicao_2:

	mov r0, 0
	sub r0, r0, 1
	mov pc, lr

condicao_3:

	add r0, r0, 1
	mov r0, 1
	mov pc, lr


for_end:

	cmp r6, r5
	beq end		/* swapped == 0, return */
	sub r3, r3, 1

	mov r0, r9
	mov r4, 0 /* r4 - j */
	b return_i
	



