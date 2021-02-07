	.file	"kernels.c"
	.text
	.p2align 4,,15
	.globl	naive_rotate
	.type	naive_rotate, @function
naive_rotate:
.LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %eax
	movl	36(%esp), %ebx
	testl	%eax, %eax
	jle	.L1
	leal	-1(%eax), %edx
	leal	(%eax,%eax,2), %edi
	imull	%eax, %edx
	leal	(%edx,%edx,2), %ecx
	addl	%eax, %edx
	leal	(%edx,%edx,2), %edx
	leal	(%ebx,%ecx,2), %esi
	movl	32(%esp), %ecx
	leal	(%ebx,%edx,2), %ebp
	leal	0(,%eax,4), %edx
	movl	%eax, %ebx
	imull	$-12, %eax, %eax
	subl	%edx, %ebx
	leal	(%ecx,%edi,2), %ecx
	addl	%ebx, %ebx
	movl	%eax, 4(%esp)
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%esi, (%esp)
	leal	(%ecx,%ebx), %edi
	movl	%esi, %edx
	movl	%edi, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%eax), %esi
	addl	$6, %eax
	movl	%esi, (%edx)
	movzwl	-2(%eax), %esi
	movw	%si, 4(%edx)
	addl	%ebx, %edx
	cmpl	%eax, %ecx
	jne	.L4
	movl	(%esp), %esi
	subl	4(%esp), %edi
	movl	%edi, %ecx
	addl	$6, %esi
	cmpl	%ebp, %esi
	jne	.L3
.L1:
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE22:
	.size	naive_rotate, .-naive_rotate
	.p2align 4,,15
	.globl	rotate
	.type	rotate, @function
rotate:
.LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	movl	28(%esp), %eax
	movl	36(%esp), %ebx
	testl	%eax, %eax
	jle	.L8
	leal	-1(%eax), %edx
	leal	(%eax,%eax,2), %edi
	imull	%eax, %edx
	leal	(%edx,%edx,2), %ecx
	addl	%eax, %edx
	leal	(%edx,%edx,2), %edx
	leal	(%ebx,%ecx,2), %esi
	movl	32(%esp), %ecx
	leal	(%ebx,%edx,2), %ebp
	imull	$-6, %eax, %ebx
	leal	(%ecx,%edi,2), %ecx
	imull	$-12, %eax, %eax
	movl	%eax, 4(%esp)
	.p2align 4,,10
	.p2align 3
.L10:
	movl	%esi, (%esp)
	leal	(%ecx,%ebx), %edi
	movl	%esi, %edx
	movl	%edi, %eax
	.p2align 4,,10
	.p2align 3
.L11:
	movl	(%eax), %esi
	addl	$6, %eax
	movl	%esi, (%edx)
	movzwl	-2(%eax), %esi
	movw	%si, 4(%edx)
	addl	%ebx, %edx
	cmpl	%ecx, %eax
	jne	.L11
	movl	(%esp), %esi
	subl	4(%esp), %edi
	movl	%edi, %ecx
	addl	$6, %esi
	cmpl	%ebp, %esi
	jne	.L10
.L8:
	addl	$8, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE23:
	.size	rotate, .-rotate
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	naive_smooth
	.type	naive_smooth, @function
naive_smooth:
.LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$72, %esp
	.cfi_def_cfa_offset 92
	movl	92(%esp), %eax
	testl	%eax, %eax
	jle	.L14
	movl	92(%esp), %eax
	movl	$0, 60(%esp)
	subl	$1, %eax
	movl	%eax, 44(%esp)
	movl	92(%esp), %eax
	leal	(%eax,%eax,2), %eax
	addl	%eax, %eax
	movl	%eax, 36(%esp)
	movl	100(%esp), %eax
	movl	%eax, 64(%esp)
	.p2align 4,,10
	.p2align 3
.L16:
	movl	60(%esp), %ebx
	movl	$0, %edi
	movl	$0, 32(%esp)
	leal	1(%ebx), %eax
	subl	$1, %ebx
	cmovns	%ebx, %edi
	movl	44(%esp), %ebx
	movl	%eax, 68(%esp)
	cmpl	%eax, %ebx
	movl	%edi, 52(%esp)
	cmovle	%ebx, %eax
	imull	92(%esp), %edi
	movl	%eax, 56(%esp)
	addl	$1, %eax
	movl	%eax, 40(%esp)
	movl	%edi, 48(%esp)
	movl	64(%esp), %edi
	.p2align 4,,10
	.p2align 3
.L21:
	movl	52(%esp), %ecx
	movl	56(%esp), %eax
	cmpl	%eax, %ecx
	jg	.L17
	movl	32(%esp), %eax
	movl	96(%esp), %ebx
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	leal	1(%eax), %esi
	subl	$1, %eax
	movl	$0, 8(%esp)
	movl	%eax, %edx
	movl	$0, %eax
	movl	%esi, 20(%esp)
	cmovs	%eax, %edx
	movl	44(%esp), %eax
	movl	%ecx, (%esp)
	cmpl	%esi, %eax
	cmovle	%eax, %esi
	movl	48(%esp), %eax
	xorl	%ecx, %ecx
	movl	%esi, 4(%esp)
	addl	%edx, %eax
	subl	%edx, %esi
	leal	(%eax,%eax,2), %eax
	addl	$1, %esi
	leal	(%ebx,%eax,2), %ebx
	leal	(%esi,%esi), %eax
	movl	%eax, 28(%esp)
	.p2align 4,,10
	.p2align 3
.L20:
	cmpl	4(%esp), %edx
	jg	.L18
	movl	28(%esp), %eax
	addl	%esi, %eax
	leal	(%ebx,%eax,2), %eax
	movl	%eax, 24(%esp)
	movl	%ebx, %eax
	.p2align 4,,10
	.p2align 3
.L19:
	movzwl	(%eax), %ebp
	addl	$6, %eax
	addl	%ebp, 8(%esp)
	movzwl	-4(%eax), %ebp
	addl	%ebp, 12(%esp)
	movzwl	-2(%eax), %ebp
	addl	%ebp, 16(%esp)
	cmpl	%eax, 24(%esp)
	jne	.L19
	movl	4(%esp), %eax
	subl	%edx, %ecx
	leal	1(%ecx,%eax), %ecx
.L18:
	addl	$1, (%esp)
	addl	36(%esp), %ebx
	movl	(%esp), %eax
	cmpl	%eax, 40(%esp)
	jne	.L20
	movl	8(%esp), %eax
	addl	$6, %edi
	cltd
	idivl	%ecx
	movw	%ax, -6(%edi)
	movl	12(%esp), %eax
	cltd
	idivl	%ecx
	movw	%ax, -4(%edi)
	movl	16(%esp), %eax
	cltd
	idivl	%ecx
	movw	%ax, -2(%edi)
	movl	20(%esp), %eax
	cmpl	%eax, 92(%esp)
	je	.L26
	movl	20(%esp), %eax
	movl	%eax, 32(%esp)
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L26:
	movl	36(%esp), %edi
	addl	%edi, 64(%esp)
	movl	32(%esp), %edi
	cmpl	%edi, 60(%esp)
	je	.L14
	movl	68(%esp), %eax
	movl	%eax, 60(%esp)
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L14:
	addl	$72, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.type	naive_smooth.cold.0, @function
naive_smooth.cold.0:
.LFSB31:
.L17:
	.cfi_def_cfa_offset 92
	.cfi_offset 3, -20
	.cfi_offset 5, -8
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	ud2
	.cfi_endproc
.LFE31:
	.text
	.size	naive_smooth, .-naive_smooth
	.section	.text.unlikely
	.size	naive_smooth.cold.0, .-naive_smooth.cold.0
.LCOLDE0:
	.text
.LHOTE0:
	.p2align 4,,15
	.globl	smooth
	.type	smooth, @function
smooth:
.LFB32:
	.cfi_startproc
	jmp	naive_smooth
	.cfi_endproc
.LFE32:
	.size	smooth, .-smooth
	.p2align 4,,15
	.globl	register_rotate_functions
	.type	register_rotate_functions, @function
register_rotate_functions:
.LFB24:
	.cfi_startproc
	subl	$20, %esp
	.cfi_def_cfa_offset 24
	pushl	$naive_rotate_descr
	.cfi_def_cfa_offset 28
	pushl	$naive_rotate
	.cfi_def_cfa_offset 32
	call	add_rotate_function
	popl	%eax
	.cfi_def_cfa_offset 28
	popl	%edx
	.cfi_def_cfa_offset 24
	pushl	$rotate_descr
	.cfi_def_cfa_offset 28
	pushl	$rotate
	.cfi_def_cfa_offset 32
	call	add_rotate_function
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE24:
	.size	register_rotate_functions, .-register_rotate_functions
	.p2align 4,,15
	.globl	register_smooth_functions
	.type	register_smooth_functions, @function
register_smooth_functions:
.LFB33:
	.cfi_startproc
	subl	$20, %esp
	.cfi_def_cfa_offset 24
	pushl	$smooth_descr
	.cfi_def_cfa_offset 28
	pushl	$smooth
	.cfi_def_cfa_offset 32
	call	add_smooth_function
	popl	%eax
	.cfi_def_cfa_offset 28
	popl	%edx
	.cfi_def_cfa_offset 24
	pushl	$naive_smooth_descr
	.cfi_def_cfa_offset 28
	pushl	$naive_smooth
	.cfi_def_cfa_offset 32
	call	add_smooth_function
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE33:
	.size	register_smooth_functions, .-register_smooth_functions
	.globl	smooth_descr
	.data
	.align 32
	.type	smooth_descr, @object
	.size	smooth_descr, 32
smooth_descr:
	.string	"smooth: Current working version"
	.globl	naive_smooth_descr
	.align 32
	.type	naive_smooth_descr, @object
	.size	naive_smooth_descr, 44
naive_smooth_descr:
	.string	"naive_smooth: Naive baseline implementation"
	.globl	rotate_descr
	.align 32
	.type	rotate_descr, @object
	.size	rotate_descr, 32
rotate_descr:
	.string	"rotate: Current working version"
	.globl	naive_rotate_descr
	.align 32
	.type	naive_rotate_descr, @object
	.size	naive_rotate_descr, 44
naive_rotate_descr:
	.string	"naive_rotate: Naive baseline implementation"
	.globl	team
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"jcf"
.LC2:
	.string	"Jean-Claude Franchitti"
.LC3:
	.string	"jcf@cs.nyu.edu"
.LC4:
	.string	"test"
.LC5:
	.string	"test@mail.com"
	.data
	.align 4
	.type	team, @object
	.size	team, 20
team:
	.long	.LC1
	.long	.LC2
	.long	.LC3
	.long	.LC4
	.long	.LC5
	.ident	"GCC: (GNU) 8.3.1 20191121 (Red Hat 8.3.1-5)"
	.section	.note.GNU-stack,"",@progbits
