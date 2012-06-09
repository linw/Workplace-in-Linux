	.file	"test.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%edi
	pushl	%ebx
	subl	$56, %esp
	call	___main
	leal	4(%esp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	leal	4(%esp), %eax
	movl	%eax, 44(%esp)
	addl	$56, %esp
	popl	%ebx
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
