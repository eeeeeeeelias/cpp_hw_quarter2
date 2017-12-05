	.text
	.file	"9_dumb_subsets.bc"
	.globl	_Z15NextCombinationRSt6vectorIiSaIiEEi
	.align	16, 0x90
	.type	_Z15NextCombinationRSt6vectorIiSaIiEEi,@function
_Z15NextCombinationRSt6vectorIiSaIiEEi: # @_Z15NextCombinationRSt6vectorIiSaIiEEi
	.cfi_startproc
# BB#0:
	movl	$4294967295, %eax       # imm = 0xFFFFFFFF
	movq	(%rdi), %r8
	movq	8(%rdi), %r9
	subq	%r8, %r9
	movq	%r9, %rdx
	shrq	$2, %rdx
	leaq	(%rdx,%rax), %rcx
	testl	%ecx, %ecx
	js	.LBB0_7
# BB#1:                                 # %.lr.ph10
	sarq	$2, %r9
	movslq	%ecx, %rcx
	addl	%edx, %eax
	cltq
	leaq	(%r8,%rax,4), %rax
	movslq	%esi, %r8
	subq	%r9, %r8
	.align	16, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	movslq	(%rax), %rdx
	leaq	(%r8,%rcx), %rsi
	cmpq	%rsi, %rdx
	jb	.LBB0_3
# BB#6:                                 #   in Loop: Header=BB0_2 Depth=1
	addq	$-4, %rax
	testq	%rcx, %rcx
	leaq	-1(%rcx), %rcx
	jg	.LBB0_2
.LBB0_7:
	xorl	%eax, %eax
	jmp	.LBB0_8
.LBB0_3:
	incl	%edx
	movl	%edx, (%rax)
	leal	1(%rcx), %eax
	movslq	%eax, %rdx
	movb	$1, %al
	cmpq	%r9, %rdx
	jae	.LBB0_8
# BB#4:                                 # %.lr.ph
	movq	(%rdi), %r9
	movq	8(%rdi), %r8
	subq	%r9, %r8
	sarq	$2, %r8
	leal	2(%rcx), %esi
	movslq	%esi, %rdi
	decq	%rdi
	movq	%rdx, %rsi
	.align	16, 0x90
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	movslq	%ecx, %rcx
	movl	(%r9,%rcx,4), %ecx
	incl	%ecx
	movl	%ecx, (%r9,%rsi,4)
	movq	%rdx, %rcx
	incq	%rdx
	movslq	%edx, %rsi
	incq	%rdi
	cmpq	%r8, %rdi
	jb	.LBB0_5
.LBB0_8:                                # %.loopexit
	retq
.Lfunc_end0:
	.size	_Z15NextCombinationRSt6vectorIiSaIiEEi, .Lfunc_end0-_Z15NextCombinationRSt6vectorIiSaIiEEi
	.cfi_endproc

	.globl	_Z7NumOnesm
	.align	16, 0x90
	.type	_Z7NumOnesm,@function
_Z7NumOnesm:                            # @_Z7NumOnesm
	.cfi_startproc
# BB#0:
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	.LBB1_2
	.align	16, 0x90
.LBB1_1:                                # %.lr.ph
                                        # =>This Inner Loop Header: Depth=1
	movl	%edi, %ecx
	andl	$1, %ecx
	addq	%rcx, %rax
	shrq	%rdi
	jne	.LBB1_1
.LBB1_2:                                # %._crit_edge
	retq
.Lfunc_end1:
	.size	_Z7NumOnesm, .Lfunc_end1-_Z7NumOnesm
	.cfi_endproc

	.globl	_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
	.align	16, 0x90
	.type	_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE,@function
_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE: # @_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
	.cfi_startproc
# BB#0:
	pushq	%r15
.Ltmp0:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp1:
	.cfi_def_cfa_offset 24
	pushq	%r12
.Ltmp2:
	.cfi_def_cfa_offset 32
	pushq	%rbx
.Ltmp3:
	.cfi_def_cfa_offset 40
	pushq	%rax
.Ltmp4:
	.cfi_def_cfa_offset 48
.Ltmp5:
	.cfi_offset %rbx, -40
.Ltmp6:
	.cfi_offset %r12, -32
.Ltmp7:
	.cfi_offset %r14, -24
.Ltmp8:
	.cfi_offset %r15, -16
	movq	%rdi, %r12
	leaq	(%rsp), %rsi
	movl	$_ZSt3cin, %edi
	callq	_ZNSi10_M_extractImEERSiRT_
	movq	(%rsp), %rax
	movq	(%r12), %r14
	movq	8(%r12), %r15
	movq	%r15, %rcx
	subq	%r14, %rcx
	sarq	$5, %rcx
	movq	%rax, %rsi
	subq	%rcx, %rsi
	jbe	.LBB2_2
# BB#1:
	movq	%r12, %rdi
	callq	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm
	jmp	.LBB2_9
.LBB2_2:
	jae	.LBB2_9
# BB#3:
	shlq	$5, %rax
	addq	%rax, %r14
	cmpq	%r14, %r15
	je	.LBB2_8
# BB#4:
	movq	%r14, %rbx
	.align	16, 0x90
.LBB2_5:                                # %.lr.ph.i.i.i.i.i
                                        # =>This Inner Loop Header: Depth=1
	movq	(%rbx), %rdi
	addq	$16, %rbx
	cmpq	%rbx, %rdi
	je	.LBB2_7
# BB#6:                                 #   in Loop: Header=BB2_5 Depth=1
	callq	_ZdlPv
.LBB2_7:                                # %_ZSt8_DestroyINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvPT_.exit.i.i.i.i.i
                                        #   in Loop: Header=BB2_5 Depth=1
	addq	$16, %rbx
	cmpq	%r15, %rbx
	jne	.LBB2_5
.LBB2_8:                                # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE15_M_erase_at_endEPS5_.exit.i
	movq	%r14, 8(%r12)
.LBB2_9:                                # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE6resizeEm.exit.preheader
	cmpq	$0, (%rsp)
	je	.LBB2_12
# BB#10:                                # %.lr.ph
	xorl	%r14d, %r14d
	xorl	%ebx, %ebx
	.align	16, 0x90
.LBB2_11:                               # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE6resizeEm.exit
                                        # =>This Inner Loop Header: Depth=1
	movq	(%r12), %rsi
	addq	%r14, %rsi
	movl	$_ZSt3cin, %edi
	callq	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	incq	%rbx
	addq	$32, %r14
	cmpq	(%rsp), %rbx
	jb	.LBB2_11
.LBB2_12:                               # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE6resizeEm.exit._crit_edge
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	retq
.Lfunc_end2:
	.size	_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE, .Lfunc_end2-_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# BB#0:
	pushq	%r15
.Ltmp19:
	.cfi_def_cfa_offset 16
	pushq	%r14
.Ltmp20:
	.cfi_def_cfa_offset 24
	pushq	%r13
.Ltmp21:
	.cfi_def_cfa_offset 32
	pushq	%r12
.Ltmp22:
	.cfi_def_cfa_offset 40
	pushq	%rbx
.Ltmp23:
	.cfi_def_cfa_offset 48
	subq	$32, %rsp
.Ltmp24:
	.cfi_def_cfa_offset 80
.Ltmp25:
	.cfi_offset %rbx, -48
.Ltmp26:
	.cfi_offset %r12, -40
.Ltmp27:
	.cfi_offset %r13, -32
.Ltmp28:
	.cfi_offset %r14, -24
.Ltmp29:
	.cfi_offset %r15, -16
	movq	stdout(%rip), %rdx
	movl	$.L.str, %edi
	movl	$.L.str.1, %esi
	callq	freopen
	xorps	%xmm0, %xmm0
	movaps	%xmm0, (%rsp)
	movq	$0, 16(%rsp)
.Ltmp9:
	leaq	(%rsp), %rdi
	callq	_Z10ReadVectorRSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE
.Ltmp10:
# BB#1:
	xorl	%ebx, %ebx
	leaq	31(%rsp), %r14
	leaq	(%rsp), %r15
	.align	16, 0x90
.LBB3_2:                                # =>This Inner Loop Header: Depth=1
	movb	$91, 31(%rsp)
.Ltmp12:
	movl	$_ZSt4cout, %edi
	movl	$1, %edx
	movq	%r14, %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp13:
# BB#3:                                 # %.noexc
                                        #   in Loop: Header=BB3_2 Depth=1
.Ltmp14:
	movq	%rbx, %rdi
	movq	%r15, %rsi
	callq	_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE
.Ltmp15:
# BB#4:                                 # %.noexc1
                                        #   in Loop: Header=BB3_2 Depth=1
.Ltmp16:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.3, %esi
	movl	$2, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp17:
# BB#5:                                 # %.noexc2
                                        #   in Loop: Header=BB3_2 Depth=1
	incq	%rbx
	movq	(%rsp), %r12
	movq	8(%rsp), %r13
	movl	%r13d, %ecx
	subl	%r12d, %ecx
	shrl	$5, %ecx
	movl	$1, %eax
	shll	%cl, %eax
	cltq
	cmpq	%rax, %rbx
	jb	.LBB3_2
# BB#6:                                 # %_Z12PrintSubsetsINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvRKSt6vectorIT_SaIS7_EE.exit
	cmpq	%r13, %r12
	je	.LBB3_11
# BB#7:
	movq	%r12, %rbx
	.align	16, 0x90
.LBB3_8:                                # %.lr.ph.i.i.i.i4
                                        # =>This Inner Loop Header: Depth=1
	movq	(%rbx), %rdi
	addq	$16, %rbx
	cmpq	%rbx, %rdi
	je	.LBB3_10
# BB#9:                                 #   in Loop: Header=BB3_8 Depth=1
	callq	_ZdlPv
.LBB3_10:                               # %_ZSt8_DestroyINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvPT_.exit.i.i.i.i5
                                        #   in Loop: Header=BB3_8 Depth=1
	addq	$16, %rbx
	cmpq	%r13, %rbx
	jne	.LBB3_8
.LBB3_11:                               # %_ZSt8_DestroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES5_EvT_S7_RSaIT0_E.exit.i8
	testq	%r12, %r12
	je	.LBB3_13
# BB#12:
	movq	%r12, %rdi
	callq	_ZdlPv
.LBB3_13:                               # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev.exit9
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	retq
.LBB3_14:                               # %.loopexit
.Ltmp18:
.LBB3_16:
	movq	%rax, %r14
	movq	(%rsp), %r15
	movq	8(%rsp), %r12
	cmpq	%r12, %r15
	je	.LBB3_21
# BB#17:
	movq	%r15, %rbx
	.align	16, 0x90
.LBB3_18:                               # %.lr.ph.i.i.i.i
                                        # =>This Inner Loop Header: Depth=1
	movq	(%rbx), %rdi
	addq	$16, %rbx
	cmpq	%rbx, %rdi
	je	.LBB3_20
# BB#19:                                #   in Loop: Header=BB3_18 Depth=1
	callq	_ZdlPv
.LBB3_20:                               # %_ZSt8_DestroyINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvPT_.exit.i.i.i.i
                                        #   in Loop: Header=BB3_18 Depth=1
	addq	$16, %rbx
	cmpq	%r12, %rbx
	jne	.LBB3_18
.LBB3_21:                               # %_ZSt8_DestroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES5_EvT_S7_RSaIT0_E.exit.i
	testq	%r15, %r15
	je	.LBB3_23
# BB#22:
	movq	%r15, %rdi
	callq	_ZdlPv
.LBB3_23:                               # %_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EED2Ev.exit
	movq	%r14, %rdi
	callq	_Unwind_Resume
.LBB3_15:                               # %.loopexit.split-lp
.Ltmp11:
	jmp	.LBB3_16
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table3:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\266\200\200"          # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	52                      # Call site table length
	.long	.Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.long	.Ltmp9-.Lfunc_begin0    #   Call between .Lfunc_begin0 and .Ltmp9
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp9-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Ltmp10-.Ltmp9          #   Call between .Ltmp9 and .Ltmp10
	.long	.Ltmp11-.Lfunc_begin0   #     jumps to .Ltmp11
	.byte	0                       #   On action: cleanup
	.long	.Ltmp12-.Lfunc_begin0   # >> Call Site 3 <<
	.long	.Ltmp17-.Ltmp12         #   Call between .Ltmp12 and .Ltmp17
	.long	.Ltmp18-.Lfunc_begin0   #     jumps to .Ltmp18
	.byte	0                       #   On action: cleanup
	.long	.Ltmp17-.Lfunc_begin0   # >> Call Site 4 <<
	.long	.Lfunc_end3-.Ltmp17     #   Call between .Ltmp17 and .Lfunc_end3
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.align	4

	.section	.text._ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm,"axG",@progbits,_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm,comdat
	.weak	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm
	.align	16, 0x90
	.type	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm,@function
_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm: # @_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp30:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp31:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp32:
	.cfi_def_cfa_offset 32
	pushq	%r13
.Ltmp33:
	.cfi_def_cfa_offset 40
	pushq	%r12
.Ltmp34:
	.cfi_def_cfa_offset 48
	pushq	%rbx
.Ltmp35:
	.cfi_def_cfa_offset 56
	pushq	%rax
.Ltmp36:
	.cfi_def_cfa_offset 64
.Ltmp37:
	.cfi_offset %rbx, -56
.Ltmp38:
	.cfi_offset %r12, -48
.Ltmp39:
	.cfi_offset %r13, -40
.Ltmp40:
	.cfi_offset %r14, -32
.Ltmp41:
	.cfi_offset %r15, -24
.Ltmp42:
	.cfi_offset %rbp, -16
	movq	%rsi, %r15
	movq	%rdi, %r14
	testq	%r15, %r15
	je	.LBB4_37
# BB#1:
	movq	8(%r14), %rax
	movq	16(%r14), %rcx
	subq	%rax, %rcx
	sarq	$5, %rcx
	cmpq	%r15, %rcx
	jae	.LBB4_2
# BB#10:
	movabsq	$576460752303423487, %rdx # imm = 0x7FFFFFFFFFFFFFF
	movq	(%r14), %rcx
	movq	%rax, %rsi
	subq	%rcx, %rsi
	sarq	$5, %rsi
	movq	%rdx, %rdi
	subq	%rsi, %rdi
	cmpq	%r15, %rdi
	jb	.LBB4_38
# BB#11:                                # %_ZNKSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE12_M_check_lenEmPKc.exit
	cmpq	%r15, %rsi
	movq	%rsi, %rdi
	cmovbq	%r15, %rdi
	leaq	(%rdi,%rsi), %r13
	cmpq	%rdx, %r13
	cmovaq	%rdx, %r13
	addq	%rsi, %rdi
	cmovbq	%rdx, %r13
	testq	%r13, %r13
	je	.LBB4_12
# BB#13:
	cmpq	%rdx, %r13
	ja	.LBB4_39
# BB#14:                                # %_ZNSt16allocator_traitsISaINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEE8allocateERS6_m.exit.i
	movq	%r13, %rdi
	shlq	$5, %rdi
	callq	_Znwm
	movq	%rax, %r12
	movq	(%r14), %rcx
	movq	8(%r14), %rax
	jmp	.LBB4_15
.LBB4_2:                                # %.lr.ph.i.i.i.preheader
	leaq	-1(%r15), %rsi
	testb	$3, %r15b
	movq	%rax, %rdx
	movq	%r15, %rcx
	je	.LBB4_6
# BB#3:                                 # %.lr.ph.i.i.i.prol.preheader
	leaq	16(%rax), %rbp
	movl	%r15d, %edi
	andl	$3, %edi
	negq	%rdi
	movq	%r15, %rcx
	.align	16, 0x90
.LBB4_4:                                # %.lr.ph.i.i.i.prol
                                        # =>This Inner Loop Header: Depth=1
	movq	%rbp, %rdx
	movq	%rdx, -16(%rdx)
	movq	$0, -8(%rdx)
	movb	$0, (%rdx)
	decq	%rcx
	leaq	32(%rdx), %rbp
	incq	%rdi
	jne	.LBB4_4
# BB#5:
	addq	$16, %rdx
.LBB4_6:                                # %.lr.ph.i.i.i.preheader.split
	cmpq	$3, %rsi
	jb	.LBB4_9
# BB#7:                                 # %.lr.ph.i.i.i.preheader.split.split
	addq	$80, %rdx
	.align	16, 0x90
.LBB4_8:                                # %.lr.ph.i.i.i
                                        # =>This Inner Loop Header: Depth=1
	leaq	-64(%rdx), %rsi
	movq	%rsi, -80(%rdx)
	movq	$0, -72(%rdx)
	movb	$0, -64(%rdx)
	leaq	-32(%rdx), %rsi
	movq	%rsi, -48(%rdx)
	movq	$0, -40(%rdx)
	movb	$0, -32(%rdx)
	movq	%rdx, -16(%rdx)
	movq	$0, -8(%rdx)
	movb	$0, (%rdx)
	leaq	32(%rdx), %rsi
	movq	%rsi, 16(%rdx)
	movq	$0, 24(%rdx)
	movb	$0, 32(%rdx)
	subq	$-128, %rdx
	addq	$-4, %rcx
	jne	.LBB4_8
.LBB4_9:                                # %_ZSt27__uninitialized_default_n_aIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEmS5_ET_S7_T0_RSaIT1_E.exit
	shlq	$5, %r15
	addq	%r15, %rax
	movq	%rax, 8(%r14)
	jmp	.LBB4_37
.LBB4_12:                               # %_ZNKSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE12_M_check_lenEmPKc.exit._ZNSt12_Vector_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE11_M_allocateEm.exit_crit_edge
	xorl	%r12d, %r12d
.LBB4_15:                               # %_ZNSt12_Vector_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE11_M_allocateEm.exit
	cmpq	%rax, %rcx
	movq	%r12, %rbp
	je	.LBB4_22
# BB#16:                                # %.lr.ph.preheader.i.i.i.i
	leaq	-32(%rax), %rdx
	movl	$16, %esi
	.align	16, 0x90
.LBB4_17:                               # %.lr.ph.i.i.i.i
                                        # =>This Inner Loop Header: Depth=1
	leaq	(%r12,%rsi), %rdi
	movq	%rdi, -16(%r12,%rsi)
	leaq	(%rcx,%rsi), %rdi
	movq	-16(%rcx,%rsi), %rbp
	cmpq	%rdi, %rbp
	je	.LBB4_18
# BB#19:                                #   in Loop: Header=BB4_17 Depth=1
	movq	%rbp, -16(%r12,%rsi)
	movq	(%rcx,%rsi), %rbp
	movq	%rbp, (%r12,%rsi)
	jmp	.LBB4_20
	.align	16, 0x90
.LBB4_18:                               #   in Loop: Header=BB4_17 Depth=1
	movups	(%rbp), %xmm0
	movups	%xmm0, (%r12,%rsi)
.LBB4_20:                               # %_ZSt10_ConstructINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEJS5_EEvPT_DpOT0_.exit.i.i.i.i
                                        #   in Loop: Header=BB4_17 Depth=1
	movq	-8(%rdi), %rbp
	movq	%rbp, -8(%r12,%rsi)
	movq	%rdi, -16(%rdi)
	movq	$0, -8(%rdi)
	movb	$0, (%rdi)
	addq	$32, %rsi
	addq	$16, %rdi
	cmpq	%rax, %rdi
	jne	.LBB4_17
# BB#21:                                # %._crit_edge.loopexit.i.i.i.i
	subq	%rcx, %rdx
	andq	$-32, %rdx
	leaq	32(%rdx,%r12), %rbp
.LBB4_22:                               # %_ZSt34__uninitialized_move_if_noexcept_aIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES6_SaIS5_EET0_T_S9_S8_RT1_.exit
	leaq	-1(%r15), %rdx
	testb	$3, %r15b
	movq	%rbp, %rcx
	movq	%r15, %rax
	je	.LBB4_26
# BB#23:                                # %.lr.ph.i.i.i7.prol.preheader
	leaq	16(%rbp), %rdi
	movl	%r15d, %esi
	andl	$3, %esi
	negq	%rsi
	movq	%r15, %rax
	.align	16, 0x90
.LBB4_24:                               # %.lr.ph.i.i.i7.prol
                                        # =>This Inner Loop Header: Depth=1
	movq	%rdi, %rcx
	movq	%rcx, -16(%rcx)
	movq	$0, -8(%rcx)
	movb	$0, (%rcx)
	decq	%rax
	leaq	32(%rcx), %rdi
	incq	%rsi
	jne	.LBB4_24
# BB#25:
	addq	$16, %rcx
.LBB4_26:                               # %_ZSt34__uninitialized_move_if_noexcept_aIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES6_SaIS5_EET0_T_S9_S8_RT1_.exit.split
	movq	%rbp, (%rsp)            # 8-byte Spill
	cmpq	$3, %rdx
	jb	.LBB4_29
# BB#27:                                # %_ZSt34__uninitialized_move_if_noexcept_aIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES6_SaIS5_EET0_T_S9_S8_RT1_.exit.split.split
	addq	$80, %rcx
	.align	16, 0x90
.LBB4_28:                               # %.lr.ph.i.i.i7
                                        # =>This Inner Loop Header: Depth=1
	leaq	-64(%rcx), %rdx
	movq	%rdx, -80(%rcx)
	movq	$0, -72(%rcx)
	movb	$0, -64(%rcx)
	leaq	-32(%rcx), %rdx
	movq	%rdx, -48(%rcx)
	movq	$0, -40(%rcx)
	movb	$0, -32(%rcx)
	movq	%rcx, -16(%rcx)
	movq	$0, -8(%rcx)
	movb	$0, (%rcx)
	leaq	32(%rcx), %rdx
	movq	%rdx, 16(%rcx)
	movq	$0, 24(%rcx)
	movb	$0, 32(%rcx)
	subq	$-128, %rcx
	addq	$-4, %rax
	jne	.LBB4_28
.LBB4_29:
	shlq	$5, %r15
	movq	(%r14), %rbx
	movq	8(%r14), %rbp
	cmpq	%rbp, %rbx
	je	.LBB4_34
	.align	16, 0x90
.LBB4_30:                               # %.lr.ph.i.i.i3
                                        # =>This Inner Loop Header: Depth=1
	movq	(%rbx), %rdi
	addq	$16, %rbx
	cmpq	%rbx, %rdi
	je	.LBB4_32
# BB#31:                                #   in Loop: Header=BB4_30 Depth=1
	callq	_ZdlPv
.LBB4_32:                               # %_ZSt8_DestroyINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvPT_.exit.i.i.i
                                        #   in Loop: Header=BB4_30 Depth=1
	addq	$16, %rbx
	cmpq	%rbp, %rbx
	jne	.LBB4_30
# BB#33:                                # %_ZSt8_DestroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES5_EvT_S7_RSaIT0_E.exitthread-pre-split
	movq	(%r14), %rbx
.LBB4_34:                               # %_ZSt8_DestroyIPNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES5_EvT_S7_RSaIT0_E.exit
	movq	(%rsp), %rbp            # 8-byte Reload
	addq	%r15, %rbp
	testq	%rbx, %rbx
	je	.LBB4_36
# BB#35:
	movq	%rbx, %rdi
	callq	_ZdlPv
.LBB4_36:                               # %_ZNSt12_Vector_baseINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE13_M_deallocateEPS5_m.exit1
	movq	%r12, (%r14)
	movq	%rbp, 8(%r14)
	shlq	$5, %r13
	addq	%r12, %r13
	movq	%r13, 16(%r14)
.LBB4_37:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.LBB4_38:
	movl	$.L.str.2, %edi
	callq	_ZSt20__throw_length_errorPKc
.LBB4_39:
	callq	_ZSt17__throw_bad_allocv
.Lfunc_end4:
	.size	_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm, .Lfunc_end4-_ZNSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE17_M_default_appendEm
	.cfi_endproc

	.section	.text._Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE,"axG",@progbits,_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE,comdat
	.weak	_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE
	.align	16, 0x90
	.type	_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE,@function
_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE: # @_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp43:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp44:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp45:
	.cfi_def_cfa_offset 32
	pushq	%r13
.Ltmp46:
	.cfi_def_cfa_offset 40
	pushq	%r12
.Ltmp47:
	.cfi_def_cfa_offset 48
	pushq	%rbx
.Ltmp48:
	.cfi_def_cfa_offset 56
	pushq	%rax
.Ltmp49:
	.cfi_def_cfa_offset 64
.Ltmp50:
	.cfi_offset %rbx, -56
.Ltmp51:
	.cfi_offset %r12, -48
.Ltmp52:
	.cfi_offset %r13, -40
.Ltmp53:
	.cfi_offset %r14, -32
.Ltmp54:
	.cfi_offset %r15, -24
.Ltmp55:
	.cfi_offset %rbp, -16
	movq	%rsi, %r14
	movq	%rdi, %r12
	movq	(%r14), %rax
	movq	8(%r14), %rcx
	subq	%rax, %rcx
	xorl	%ebx, %ebx
	sarq	$5, %rcx
	je	.LBB5_7
# BB#1:
	movq	$-1, %r13
	leaq	7(%rsp), %r15
	xorl	%ebp, %ebp
	.align	16, 0x90
.LBB5_2:                                # %.lr.ph
                                        # =>This Inner Loop Header: Depth=1
	testb	$1, %r12b
	je	.LBB5_6
# BB#3:                                 #   in Loop: Header=BB5_2 Depth=1
	testb	$1, %bpl
	jne	.LBB5_4
# BB#5:                                 #   in Loop: Header=BB5_2 Depth=1
	addq	%r13, %rcx
	shlq	$5, %rcx
	movq	(%rax,%rcx), %rsi
	movq	8(%rax,%rcx), %rdx
	movl	$_ZSt4cout, %edi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movb	$1, %bpl
	jmp	.LBB5_6
	.align	16, 0x90
.LBB5_4:                                #   in Loop: Header=BB5_2 Depth=1
	movb	$44, 7(%rsp)
	movl	$_ZSt4cout, %edi
	movl	$1, %edx
	movq	%r15, %rsi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	(%r14), %rcx
	movq	8(%r14), %rdx
	subq	%rcx, %rdx
	shrq	$5, %rdx
	addq	%r13, %rdx
	shlq	$5, %rdx
	movq	(%rcx,%rdx), %rsi
	movq	8(%rcx,%rdx), %rdx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.LBB5_6:                                #   in Loop: Header=BB5_2 Depth=1
	shrq	%r12
	incq	%rbx
	movq	(%r14), %rax
	movq	8(%r14), %rcx
	subq	%rax, %rcx
	sarq	$5, %rcx
	decq	%r13
	cmpq	%rbx, %rcx
	ja	.LBB5_2
.LBB5_7:                                # %._crit_edge
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end5:
	.size	_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE, .Lfunc_end5-_Z16PrintCombinationINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEvmRKSt6vectorIT_SaIS7_EE
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_9_dumb_subsets.ii,@function
_GLOBAL__sub_I_9_dumb_subsets.ii:       # @_GLOBAL__sub_I_9_dumb_subsets.ii
	.cfi_startproc
# BB#0:
	pushq	%rax
.Ltmp56:
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	callq	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	movl	$_ZStL8__ioinit, %esi
	movl	$__dso_handle, %edx
	popq	%rax
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end6:
	.size	_GLOBAL__sub_I_9_dumb_subsets.ii, .Lfunc_end6-_GLOBAL__sub_I_9_dumb_subsets.ii
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"output.txt"
	.size	.L.str, 11

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"wt"
	.size	.L.str.1, 3

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"vector::_M_default_append"
	.size	.L.str.2, 26

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"]\n"
	.size	.L.str.3, 3

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_9_dumb_subsets.ii

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
