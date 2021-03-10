.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo

	movl $1, %ebx 				# i -> ebx
	movl 12(%ebp), %ecx			# elementos -> ecx
for:
	cmpl %ecx, %ebx
	jge endfor

	movl 8(%ebp), %edx
	movl (%edx, %ebx, 4), %edi
if:	
	cmpl -4(%ebp), %edi
	jge endif
	
	movl %edi, -4(%ebp)
endif:
	incl %ebx
	jmp for
endfor:


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
