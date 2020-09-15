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
.equ TABLE1_SIZE, (table1_end - table1)

table1:
	.byte 10, 20, 5, 6, 34, 9
table1_end:

table2:
	.byte 11, 22, 33
table2_end:

.align 1

p:
	.byte 0
q:
	.byte 0

main:
	push lr
	ldr r0, addr_table1
	mov r1, TABLE1_SIZE
	mov r2, 6
	bl search
	ldr r1, addr_p
	str r0, [r1]
	ldr r0, addr_table2
	mov r1, (table2_end - table2)
	mov r2, 44
	bl search
	ldr r1, addr_q
	str r0, [r1]
	mov r0, 0
	pop pc

addr_table1:
	.word table1
addr_table2:
	.word table2
addr_p:
	.word p
addr_q:
	.word q

	.text

search:
	push r4
	mov r3, 0 /* r3 - i */
search_for:
	cmp r3, r1 /* i - array_size */
	bhs search_for_end
	ldrb r4, [r0, r3] /* array[i] != value */
	cmp r4, r2
	beq search_for_end
	add r3, r3, 1 /* ++i */
	b search_for
search_for_end:
	cmp r3, r1 /* if (i < array_size) */
	bhs search_if_end
	mov r0, r3 /* return i */
	b search_end
search_if_end:
	mov r0, 0 /* return -1 */
	sub r0, r0, 1
search_end:
	pop r4
	mov pc, lr 
