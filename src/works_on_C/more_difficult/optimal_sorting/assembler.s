	.file	"work.c"
	.text
	.globl	compare
	.type	compare, @function
compare:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movq	%rdx, -56(%rbp)
	movl	%ecx, -48(%rbp)
	movl	-48(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	cmovge	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L2
.L4:
	addl	$1, -28(%rbp)
.L2:
	movl	-28(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jge	.L5
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	.L4
	jmp	.L5
.L7:
	addl	$1, -24(%rbp)
.L5:
	movl	-24(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jge	.L6
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-56(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	.L7
.L6:
	movl	-44(%rbp), %eax
	subl	-28(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-48(%rbp), %eax
	subl	-24(%rbp), %eax
	movl	%eax, -8(%rbp)
	cmpl	$0, -12(%rbp)
	jne	.L8
	cmpl	$0, -8(%rbp)
	jne	.L8
	movl	$0, %eax
	jmp	.L9
.L8:
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L10
	movl	$1, %eax
	jmp	.L9
.L10:
	movl	-12(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L11
	movl	$-1, %eax
	jmp	.L9
.L11:
	movl	-28(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L12
.L16:
	movl	-20(%rbp), %eax
	subl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	-56(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L13
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L14
	movl	$1, %eax
	jmp	.L9
.L14:
	movl	$-1, %eax
	jmp	.L9
.L13:
	addl	$1, -20(%rbp)
.L12:
	movl	-20(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L16
	movl	$0, %eax
.L9:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	compare, .-compare
	.section	.rodata
	.align 8
.LC0:
	.string	"\320\237\320\265\321\200\320\262\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 \320\261\320\276\320\273\321\214\321\210\320\265"
	.align 8
.LC1:
	.string	"\320\222\321\202\320\276\321\200\320\276\320\265 \321\207\320\270\321\201\320\273\320\276 \320\261\320\276\320\273\321\214\321\210\320\265"
.LC2:
	.string	"\320\247\320\270\321\201\320\273\320\260 \321\200\320\260\320\262\320\275\321\213"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$1, -15(%rbp)
	movb	$1, -14(%rbp)
	movb	$0, -13(%rbp)
	movl	$3, -28(%rbp)
	movb	$0, -12(%rbp)
	movb	$1, -11(%rbp)
	movb	$0, -10(%rbp)
	movb	$1, -9(%rbp)
	movl	$4, -24(%rbp)
	movl	-24(%rbp), %ecx
	leaq	-12(%rbp), %rdx
	movl	-28(%rbp), %esi
	leaq	-15(%rbp), %rax
	movq	%rax, %rdi
	call	compare
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jle	.L18
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L19
.L18:
	cmpl	$0, -20(%rbp)
	jns	.L20
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L19
.L20:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L19:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L22
	call	__stack_chk_fail@PLT
.L22:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
