	.file	"class_mem_what.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN4BaseC2Ev,"axG",@progbits,_ZN4BaseC5Ev,comdat
	.align 2
	.weak	_ZN4BaseC2Ev
	.type	_ZN4BaseC2Ev, @function
_ZN4BaseC2Ev:
.LFB967:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$_ZTV4Base+8, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE967:
	.size	_ZN4BaseC2Ev, .-_ZN4BaseC2Ev
	.section	.text._ZN4BaseD2Ev,"axG",@progbits,_ZN4BaseD5Ev,comdat
	.align 2
	.weak	_ZN4BaseD2Ev
	.type	_ZN4BaseD2Ev, @function
_ZN4BaseD2Ev:
.LFB970:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$_ZTV4Base+8, (%eax)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE970:
	.size	_ZN4BaseD2Ev, .-_ZN4BaseD2Ev
	.section	.rodata
.LC0:
	.string	"Base::f()"
	.section	.text._ZN4Base1fEv,"axG",@progbits,_ZN4Base1fEv,comdat
	.align 2
	.weak	_ZN4Base1fEv
	.type	_ZN4Base1fEv, @function
_ZN4Base1fEv:
.LFB972:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_ZN4Base1fEv, .-_ZN4Base1fEv
	.section	.rodata
.LC1:
	.string	"Base::g()"
	.section	.text._ZN4Base1gEv,"axG",@progbits,_ZN4Base1gEv,comdat
	.align 2
	.weak	_ZN4Base1gEv
	.type	_ZN4Base1gEv, @function
_ZN4Base1gEv:
.LFB973:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE973:
	.size	_ZN4Base1gEv, .-_ZN4Base1gEv
	.section	.text._ZN6DeriveC2Ev,"axG",@progbits,_ZN6DeriveC5Ev,comdat
	.align 2
	.weak	_ZN6DeriveC2Ev
	.type	_ZN6DeriveC2Ev, @function
_ZN6DeriveC2Ev:
.LFB975:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4BaseC2Ev
	movl	8(%ebp), %eax
	movl	$_ZTV6Derive+8, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE975:
	.size	_ZN6DeriveC2Ev, .-_ZN6DeriveC2Ev
	.section	.text._ZN6DeriveD2Ev,"axG",@progbits,_ZN6DeriveD5Ev,comdat
	.align 2
	.weak	_ZN6DeriveD2Ev
	.type	_ZN6DeriveD2Ev, @function
_ZN6DeriveD2Ev:
.LFB978:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$_ZTV6Derive+8, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4BaseD2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE978:
	.size	_ZN6DeriveD2Ev, .-_ZN6DeriveD2Ev
	.section	.rodata
.LC2:
	.string	"Derive::f()"
	.section	.text._ZN6Derive1fEv,"axG",@progbits,_ZN6Derive1fEv,comdat
	.align 2
	.weak	_ZN6Derive1fEv
	.type	_ZN6Derive1fEv, @function
_ZN6Derive1fEv:
.LFB980:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC2, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE980:
	.size	_ZN6Derive1fEv, .-_ZN6Derive1fEv
	.section	.rodata
.LC3:
	.string	"Derive::g()"
	.section	.text._ZN6Derive1gEv,"axG",@progbits,_ZN6Derive1gEv,comdat
	.align 2
	.weak	_ZN6Derive1gEv
	.type	_ZN6Derive1gEv, @function
_ZN6Derive1gEv:
.LFB981:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC3, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE981:
	.size	_ZN6Derive1gEv, .-_ZN6Derive1gEv
	.section	.rodata
.LC4:
	.string	"Derive::h()"
	.section	.text._ZN6Derive1hEv,"axG",@progbits,_ZN6Derive1hEv,comdat
	.align 2
	.weak	_ZN6Derive1hEv
	.type	_ZN6Derive1hEv, @function
_ZN6Derive1hEv:
.LFB982:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC4, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE982:
	.size	_ZN6Derive1hEv, .-_ZN6Derive1hEv
	.section	.rodata
	.align 4
.LC5:
	.string	"==============Base==============="
.LC6:
	.string	"===="
	.text
	.globl	main
	.type	main, @function
main:
.LFB983:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA983
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -12
	call	_ZN4BaseC1Ev
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN6DeriveC1Ev
	movl	$.LC5, 4(%esp)
	movl	$_ZSt4cout, (%esp)
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leal	28(%esp), %eax
	movl	%eax, 40(%esp)
	leal	28(%esp), %eax
	addl	$4, %eax
	movl	%eax, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEPKv
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEPKv
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	movl	$0, 44(%esp)
	jmp	.L13
.L14:
	movl	40(%esp), %eax
	movl	(%eax), %eax
	movl	44(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 36(%esp)
	movl	40(%esp), %eax
	movl	(%eax), %eax
	movl	44(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEPKv
	movl	$.LC6, 4(%esp)
	movl	%eax, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	36(%esp), %eax
	call	*%eax
.LEHE0:
	addl	$1, 44(%esp)
.L13:
	movl	40(%esp), %eax
	movl	(%eax), %eax
	movl	44(%esp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	jne	.L14
	movl	$0, %ebx
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN6DeriveD1Ev
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN4BaseD1Ev
	movl	%ebx, %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_remember_state
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.cfi_restore 3
	ret
.L16:
	.cfi_restore_state
	movl	%eax, %ebx
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN6DeriveD1Ev
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_ZN4BaseD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE983:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA983:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE983-.LLSDACSB983
.LLSDACSB983:
	.uleb128 .LEHB0-.LFB983
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L16-.LFB983
	.uleb128 0
	.uleb128 .LEHB1-.LFB983
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE983:
	.text
	.size	main, .-main
	.weak	_ZTV6Derive
	.section	.rodata._ZTV6Derive,"aG",@progbits,_ZTV6Derive,comdat
	.align 8
	.type	_ZTV6Derive, @object
	.size	_ZTV6Derive, 20
_ZTV6Derive:
	.long	0
	.long	_ZTI6Derive
	.long	_ZN6Derive1fEv
	.long	_ZN6Derive1gEv
	.long	_ZN6Derive1hEv
	.weak	_ZTV4Base
	.section	.rodata._ZTV4Base,"aG",@progbits,_ZTV4Base,comdat
	.align 8
	.type	_ZTV4Base, @object
	.size	_ZTV4Base, 16
_ZTV4Base:
	.long	0
	.long	_ZTI4Base
	.long	_ZN4Base1fEv
	.long	_ZN4Base1gEv
	.weak	_ZTS6Derive
	.section	.rodata._ZTS6Derive,"aG",@progbits,_ZTS6Derive,comdat
	.type	_ZTS6Derive, @object
	.size	_ZTS6Derive, 8
_ZTS6Derive:
	.string	"6Derive"
	.weak	_ZTI6Derive
	.section	.rodata._ZTI6Derive,"aG",@progbits,_ZTI6Derive,comdat
	.align 4
	.type	_ZTI6Derive, @object
	.size	_ZTI6Derive, 12
_ZTI6Derive:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTS6Derive
	.long	_ZTI4Base
	.weak	_ZTS4Base
	.section	.rodata._ZTS4Base,"aG",@progbits,_ZTS4Base,comdat
	.type	_ZTS4Base, @object
	.size	_ZTS4Base, 6
_ZTS4Base:
	.string	"4Base"
	.weak	_ZTI4Base
	.section	.rodata._ZTI4Base,"aG",@progbits,_ZTI4Base,comdat
	.align 4
	.type	_ZTI4Base, @object
	.size	_ZTI4Base, 8
_ZTI4Base:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS4Base
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB993:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	.L17
	cmpl	$65535, 12(%ebp)
	jne	.L17
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %eax
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	%eax, (%esp)
	call	__cxa_atexit
.L17:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE993:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB994:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE994:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__sub_I_main
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.weak	_ZN4BaseC1Ev
	.set	_ZN4BaseC1Ev,_ZN4BaseC2Ev
	.weak	_ZN4BaseD1Ev
	.set	_ZN4BaseD1Ev,_ZN4BaseD2Ev
	.weak	_ZN6DeriveC1Ev
	.set	_ZN6DeriveC1Ev,_ZN6DeriveC2Ev
	.weak	_ZN6DeriveD1Ev
	.set	_ZN6DeriveD1Ev,_ZN6DeriveD2Ev
	.ident	"GCC: (GNU) 4.6.3 20120306 (Red Hat 4.6.3-2)"
	.section	.note.GNU-stack,"",@progbits
