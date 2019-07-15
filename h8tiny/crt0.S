	.h8300h
	.text
	.global _start
_start:
	mov.l	#_stack,er7
	jsr	@_main
	bra	.-2

	.global _usleep
_usleep:
	mov.l	er6,@-er7
	mov.l	er7,er6
l2:	or.w	r0,r0
	or.w	r0,r0
	dec.w	#1,r0
	bne	l2
	mov.l	@er7+,er6
	mov.w	@er7+,r0
	xor.w	e0,e0
	jmp	@er0
