	.file	"test.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB7:
	pushl	%ebp
LCFI0:
	movl	%esp, %ebp
LCFI1:
	andl	$-16, %esp
LCFI2:
	subl	$16, %esp
LCFI3:
	call	___main
	movl	$10, 8(%esp)
	leal	8(%esp), %eax
	movl	%eax, 12(%esp)
	movl	12(%esp), %eax
	movl	$20, (%eax)
	movl	$0, %eax
	leave
LCFI4:
	ret
LFE7:
