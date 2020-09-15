.section .startup

	b	main

	.data
x:
	.word	30
y:
	.word	4
z:
	.word	0
	
	.text
main:
	ldr	r0, addr_x
	ldr	r0, [r0]
	ldr	r1, addr_y
	ldr	r1, [r1]
	add	r0, r0, r1
	ldr	r1, addr_z
	str	r0, [r1]
	b      .

	
addr_x:
	.word	x
addr_y:
	.word	y
addr_z:
	.word	z
