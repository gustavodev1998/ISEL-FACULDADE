.section .startup
	b	_start
	b	.
_start:
	ldr	sp, addr_stack_top
	ldr	r0, addr_main
	mov	pc, r0
	b	.
	
addr_stack_top:
	.word	stack_top
addr_main:
	.word	main

	.section	.stack
	.space	1024
stack_top:

x:
       .word  0
	   
	   .text
main:
       mov    r0, 4        /* passagem do multiplicando em R0 */
       mov    r1, 10       /* passagem do multiplicador em R1 */
	   ldr    r4, addr_x
       bl     multiply     /* chamada da funcao */       
       str    r0, [r4]     /* Retorno em R0. Guardado em memoria */
       mov    r0, 8        /* passagem do multiplicando em R0 */
       mov    r1, 10       /* passagem do multiplicador em R1 */
       bl     multiply     /* chamada da funcao */
       str    r0, [r4, 2]  /* Retorno em R0. Guardado em memoria */
       b      .            /* fim do programa */

addr_x:
       .word  x

multiply:                /* multiplicando em R0 e multiplicador em R1 */
      push  r4           /* preserva registo R4 */
	mov	r4, 0
while:
	sub	r1, r1, 0
	beq	while_end
	add	r4, r4, r0
	sub	r1, r1, 1
	b	while
while_end:
	mov	r0, r4
      pop   r4           /* recupera valor de R4 */
	mov	pc, lr
