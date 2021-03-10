.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

	movl $0, -4(%ebp)		# res = 0
	movl $0, -8(%ebp)		# i = 0
	movl $0, -12(%ebp)		# j = 0 
	movl 12(%ebp), %ecx		# salto -> ecx
for1:
	cmpl $3, -8(%ebp)
	jge endfor1

for2:
	cmpl $3, -12(%ebp)
	jge endfor2

	movl 8(%ebp), %esi		# @Mat -> esi
	imul $3, -8(%ebp), %edi
	addl -8(%ebp), %edi
	movl (%esi, %edi, 4), %eax
	addl -12(%ebp), %eax
	subl %eax, -4(%ebp)

	incl -12(%ebp)
	jmp for2
endfor2:
	addl %ecx, -8(%ebp)		# i += salto
	movl $0, -12(%ebp)
	jmp for1
endfor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
