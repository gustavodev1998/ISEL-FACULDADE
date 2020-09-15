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


.equ	B_POSITION, 1 /* Mask para verificar o bit de menor peso */



.text

main:	
	mov	r0,0
	movt	r0,0xFF 	/* Poem endereço do porto de saida */

	ldrb	r3, [r0]	/* Busca o valor no porto de saida */ 
	strb	r3, [r0]	/* Guarda o valor no porto de pre-existente*/
	
main_1:
	mov r1,  0xC0 
	movt r1, 0xFF		/* Poem endereço do porto de entrada */

	ldr r4,  [r1]		/* Busca o valor no porto de entrada */ 

	lsr r4, r4, B_POSITION	/* Busca o bit de menor peso e poem no carry */
	bcs cond2

cond1:
	movt r3, 0
	b end

cond2:
	lsl r3, r3, 8 	/* Shifta o valor 8 bits */
	asr r3, r3, 8	/* Estende o sinal do bit de maior peso 8 bits */
	
end:
	str r3, [r1]
	b .


