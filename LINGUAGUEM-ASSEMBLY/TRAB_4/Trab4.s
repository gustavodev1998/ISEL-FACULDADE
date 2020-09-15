	.section .startup
	b _start
	ldr pc, addr_isr

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

addr_isr:
	.word isr

	.section .stack
	.equ STACK_SIZE, 64
	.space STACK_SIZE

stack_top:


.data
	Interruptor0:
			.byte 0

	Interruptor1:
			.byte 0

	Interruptor2_3:
			.byte 0

/*---------------------------------------------------------------------*/

	.text

main:
	mov r0, 16
	msr cpsr, r0
	
	ldr r5,	addr_Interruptor0
	ldr r6,	addr_Interruptor1
	ldr r7,	addr_Interruptor2_3
	
	/* Registo R3 Somente para Leitura */
	/* Registo R4 para guardar o bit */

Read:
	mov	r0,0 
	movt	r0,0xFF 	/* Poem endereço do porto de entrada */
	
	mov	r1, 1 /* Inicializar o 1ºLed */
	movt r1, 1 /* Guarda na parte alta o mesmo valor */
I0:
	ldrb	r3, [r0]	/* Busca o valor no porto de entrada */ 
		
	lsl	r4, r3, 15	/* Shifta o bit para retirar todos os valores que não sejam o de menor peso */
	lsr	r4, r4, 15	/* Shifta o bit de volta com o valor desejado */

	strb r4, [r5] /* Guarda o valor no endereço do Interruptor0 */


I1:

	lsl	r4, r3, 14	/* Shifta o bit para retirar todos os valores que não sejam o de menor peso */
	lsr	r4, r4, 15	/* Shifta o bit de volta com o valor desejado */

	strb r4, [r6] /* Guarda o valor no endereço do Interruptor1 */
	

I3:
	 
	lsl	r4, r3, 12	/* Shifta o bit para retirar todos os valores que não sejam o de menor peso */
	lsr	r4, r4, 14	/* Shifta o bit de volta com o valor desejado */

	strb r4, [r7] /* Guarda o valor no endereço do Interruptor2_3*/


Final:
	b I0	/* Volta a reler desde I3-I0 */



addr_Interruptor0:
		.word Interruptor0

addr_Interruptor1:
		.word Interruptor1

addr_Interruptor2_3:
		.word Interruptor2_3

	
/*---------------------------------------------------------------------*/
	.text

isr:
	
	push r2
	push r3
	push r4
	push r5
	push r6
	push r7

	mov r2, 1 /* Compara com 1 */ 

	mov r3, 0x40
	movt r3, 0xFF /* Endereço do External_#0 */ 
	
	ldrb r5,[r5] /* Busca o valor I0 */
	ldrb r6,[r6] /* Busca o valor I1 */
	ldrb r7,[r7] /* Busca o valor I3&I2 */
	
	add r7, r7, 0
	beq Stop	/* Corresponde ao estado parado */

	cmp r5, r2 /* Direita ou Esquerda */
	beq right

left:
	ror r1, r1, 15 /* Anda para a direita 15 bits */
	cmp r6, r2 /* Ligado ou Desligado */
	beq ON
	b OFF

right:
	ror r1, r1, 1 /* Anda para a direita 1 bit */
	cmp r6, r2 /* Ligado ou Desligado */
	beq ON

OFF:
	push r3		
	mov r3, 0xFF	/* Mascara com todos os bits a 1 */
	eor r3, r3, r1	/* Xor de 0 com tudo a 1s */
	strb r3, [r0]	/* Guarda o resultado no porto de saida */
	pop r3

	add r2, r2, 1 /* Valor intermedio de velocidade */
	cmp r7, r2 
	beq Normal
	bhs Fast
	b Slow
ON: 
	strb r1, [r0]
	
	add r2, r2, 1 /* Valor intermedio de velocidade */
	cmp r7, r2 
	beq Normal
	bhs Fast


Slow:
	mov r4, 20
	str r4, [r3]
	b Stop

Normal:
	mov r4, 10
	str r4, [r3]
	b Stop

Fast:
	mov r4, 5
	str r4, [r3]
	
Stop:

	ldrb r8, [r3]
	pop r7
	pop r6
	pop r5
	pop r4
	pop r3
	pop r2
	movs pc, lr








