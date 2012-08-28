	.file	"2_7.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "i=%d\12\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	call	__alloca
	call	___main
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
L2:
	cmpl	$4, -8(%ebp)
	jg	L3
	movl	-4(%ebp), %edx
	leal	-4(%ebp), %eax
	incl	(%eax)
	movl	%edx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	leal	-8(%ebp), %eax
	incl	(%eax)
	jmp	L2
L3:
	leave
	ret
	.def	_printf;	.scl	3;	.type	32;	.endef
