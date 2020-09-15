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

	buf1:
		.byte -10, 10, 0, 20

	buf2: 	
		.word 5000, 10000, 15

	buf3:
		.word 0x0000,0x000A, 0x8000,0x0000, 0xFFFF,0xFFFF


main: 
	push lr

/* byte: */
	ldr r0, addr_buf1
	mov r1, 4
	mov r2, 1
	bl bubble_sort

/* word: */
	ldr r0, addr_buf2
	mov r1, 3
	mov r2, 2
	bl bubble_sort

/* dword: */
	ldr r0, addr_buf3
	mov r1, 3
	mov r2, 4
	bl bubble_sort

	b .

addr_buf1:
	.word buf1

addr_buf2:
	.word buf2

addr_buf3:
	.word buf3

bubble_sort:
	push lr
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6
 	push r7
	push r10
/* Os registos a utilizar na funcao foram guardados na pilha*/
	mov r3, r1 
	sub r3, r3, 1 /* r3 (i) -> len (r1) - 1 */
	mov r4, 0 /* r4 (j) -> 0 */
	mov r5, 0 /* Utilizado quando necessário comparar com 0*/
	mov r10, 2 /* Utilizado para escolher a função de comparação certa*/
	mov r7, r0 /* Guarda o endereço de início do array (elems) */

return_i:   /* For da variavel i */
	cmp r5, r3  /* Compara 0 com a variavel i */
	bhs end 
	add r1, r0, r2 /* coloca o enderço do segundo elemento do array em "b" */
	mov r6, 0	/* Swapped = 0 */	

return_j:  /* For da variavel j */
	cmp r4, r3	/* compara a variavel j com a variavel i */
	bhs for_end
	cmp r2, r10 /* Compara o valor de size com 2 (r10) para escolher a funcao compare a realizar */
	push r0 /* Guarda o valor de "a" que vai ser estragado com o retorno da funcao compare */
	beq if_compare_word
	bhs if_compare_dword
		
if_compare_byte:
	bl compare_byte /* compara dois numeros de 8 bits */
	b if_swap
	
if_compare_word:
	bl compare_uword /* Compara dois numeros de 16 bits */	
	b if_swap 

if_compare_dword:
	bl compare_dword /* Compara dois numeros de 32 bits */

if_swap:
	cmp r0, r5 /* Compara retorno das funcoes compare com 0 */ 
	pop r0 /* devolve o valor de "a" para r0 */
	bge swap_condition
	b if_end

swap_condition:
	bl swap		
	add r6, r6, 1 /* Swapped = 1 */
	b if_end

if_end: /* Realiza os comandos seguintes for da variavel j */
	add r0, r0, r2 /* a+=size */
	add r1, r1, r2 /* b+=size */
	add r4, r4, 1  /* j++ */
	b return_j

for_end:
	cmp r6, r5 /* Compara Swapped com 0 */
	beq end /* swapped == 0, return */
	sub r3, r3, 1 /* i-- */
	mov r0, r7 /* Retorna o valor do endereço do primeiro valor do array (elems) para r0 */
	mov r4, 0 /* Retorna o valor de j a 0 */
	b return_i

end:
	pop r10
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
 	pop r1
	pop r0
	pop lr  
/* Os registos utilizados na funcao voltam a ter os valores anteriormente guardado na pilha */
	mov pc, lr /* Fim da funcao */

/* FUNCOES CHAMADAS PELA BUBBLE_SORT */

swap:
	push r3
	push r4
	push r5
/* Os registos a utilizar na funcao foram guardados na pilha */
	mov r3, 0  /* Fora do swap_next para nao reniciar a 0 */

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

	pop r5
	pop r4
	pop r3
/* Os registos utilizados na funcao voltam a ter os valores anteriormente guardado na pilha */
	mov pc, lr

compare_byte:

	push r2
	push r3
/* Os registos a utilizar na funcao foram guardados na pilha */

	ldrb r2, [r0]
	lsl r2, r2, 8 /* Expansão do sinal */
	ldrb r3, [r1]
	lsl r3, r3, 8
	cmp r2,  r3
	beq condicao_1
	blt condicao_2
	b condicao_3

compare_uword:

	push r2
	push r3
/* Os registos a utilizar na funcao foram guardados na pilha*/
	ldr r2, [r0]
	ldr r3, [r1]
	cmp r2,  r3
	beq condicao_1
	blt condicao_2
	b condicao_3
	
compare_dword:

	push r2
	push r3
/* Os registos a utilizar na funcao foram guardados na pilha*/
	ldr r2, [r0]	
	ldr r3, [r1]
	cmp r2,  r3
	beq condicao_equal
	blt condicao_2
	b condicao_3
	
condicao_equal:	
	ldr r2, [r0,2]
	ldr r3, [r1,2]
	cmp r2, r3
	beq condicao_1
	blo condicao_2
	b condicao_3

condicao_1:
	mov r0, 0 /* Retorna 0 */
	pop r3
	pop r2
	mov pc, lr
	
condicao_2:
	mov r0, 0
	sub r0, r0, 1 /* Retorna -1 */
	pop r3
	pop r2
	mov pc, lr

condicao_3:
	mov r0, 1 /* Retorna 1 */
	pop r3
	pop r2
	mov pc, lr	

/* Exercicio 2 */
	/* A função compare_dword ao comparar os numeros a = 0x80000000 */ 
	/*	b = 0xFFFFFFFF gastou 51 ciclos de relogio */

/* Exercicio 4 B) */
	/* ( 0x4C0 - 0x44C ) = 0x074 */