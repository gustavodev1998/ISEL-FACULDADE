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
	
	.equ STACK_SIZE, 128
	.space STACK_SIZE

stack_top:

	.equ	I_POSITION, 1

	.text
main:
	mov r0, 0
	movt r0, 0xFF   ; endereco sw, leds
	mov r1, 0x40
	movt r1, 0xFF    ; endereco timer
	mov r2, 10       
	strb r2, [r1]    ; configura timer com 10. freq=10 Hz = 1s
	mov r3, 1
	movt r3, 1		 ; inicializa registo com valor dos leds
	strb r3, [r0]    ; escreve nos leds
	mov r2, 16
	msr cpsr, r2     ; ativa interrupcoes
readIn:
	ldrb r2, [r0]    ; le porto de entrada
	b readIn


isr:
	lsr r2, r2, I_POSITION
	bcc left
	ror r3, r3, 1
	b end
left:
	ror r3, r3, 15
end:
	strb r3, [r0]
	ldrb r4, [r1]
	movs pc, lr
	