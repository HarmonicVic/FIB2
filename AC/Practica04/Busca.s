 .text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar:
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	pushl %edi
	pushl %esi
	
	movl $-1, -4(%ebp)		# trobat = -1
	movl $0, -16(%ebp)		# low = 0
	movl $0, -8(%ebp)		# mid = low = 0
	movl 24(%ebp), %ecx		# N -> ecx
	decl %ecx				# N-1
	movl %ecx, -12(%ebp)	# high = N-1

while:
	movl -12(%ebp), %ebx	# high -> ebx
	cmpl %ebx, -16(%ebp)	# cmp high and low
	jg endwhile

	pushl 8(%ebp)			# push @v
	pushl 20(%ebp)			# push X
	pushl 16(%ebp)			# ""
	pushl 12(%ebp)			# ""

	leal -8(%ebp), %edi		# take @ of mid
	pushl %edi				# push @mid
	leal -12(%ebp), %edi	# take @ of high
	pushl %edi				# push @high 
	leal -16(%ebp), %edi	# take @ of low
	pushl %edi				# push @low

	call BuscarElemento

	addl $28, %esp
	movl %eax, -4(%ebp)

if:
	cmpl $0, -4(%esp)
	jl while

endwhile:
	popl %esi
	popl %edi
	popl %ebx
	movl -4(%esp), %eax
	movl %esp, %ebp
	popl %ebp
	ret
	