	.section .startup

	b	main

	.data


table1:
		.byte	10, 20, 5, 6, 34, 9

p:
	.byte	0


	.text

main:
	ldr 	r0, addr_table1    /* r0 = array */
	mov 	r1, 6			   /* r1 = size of array */
	ldr 	r2, addr_p		   
	ldrb 	r2, [r2]		   /* r2 = caracter */
	mov		r3, 0			/* r3 - i */
search_for:
	cmp		r3, r1		/* i - array_size */
	bhs		search_for_end
	ldrb	r4, [r0, r3]	/* array[i] != value */
	cmp		r4, r2			
	beq		search_for_end
	add		r3, r3, 1 		/* ++i */
	b		search_for
search_for_end:
	cmp		r3, r1		/* if (i < array_size) */
	bhs		search_if_end
	mov 	r0, r3		/* return i */
	b		search_end
search_if_end:
	mov		r0, 0			/* return -1 */
	sub		r0, r0, 1
search_end:
	b 		.

addr_table1:
	.word	table1
addr_p:
	.word	p
