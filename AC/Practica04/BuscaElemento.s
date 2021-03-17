 .text
	.align 4
	.globl BuscarElemento
	.type BuscarElemento,@function
BuscarElemento:
    pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	pushl %edi
	pushl %esi

if:	
	movl 16(%ebp), %ecx		# *mid
	movl (%ecx), %ecx		# mid
	movl 32(%ebp), %edx		# @v[]
	movl %ecx, %edi			# mid copy
	imull $12, %edi			# 
	movl 4(%edx, %edi), %edx # v[mid].k
	
	cmpl 24(%ebp), %edx		# cmpl X.k and v[*mid].k
	jne elseif				
	
	popl %esi
	popl %edi
	popl %ebx
	movl %ecx, %eax			# mid -> %eax 
	movl %ebp, %esp
	popl %ebp
	ret

	# se sigue usando %ecx para mid, los demas registros se 
	# pueden sobreescribir
elseif:
	movl 12(%ebp), %ebx		# *high
	movl (%ebx), %ebx		# high
	cmpl %ebx, %ecx
	jge else
	
	movl 16(%ebp), %edi		# *mid -> edi
	movl %ebx, (%edi)		# high -> *mid
	movl 8(%ebp), %edx
	incl (%edx)
	jmp end

else:
	movl 8(%ebp), %edx
	movl (%edx), %edx
	movl 16(%ebp), %edi		# *mid -> edi
	movl %edx, (%edi)		# low -> *mid
	movl 12(%ebp), %edi
	decl (%edi)

end:
	popl %esi
	popl %edi
	popl %ebx
	movl $-1, %eax
	movl %ebp, %esp
	popl %ebp
	ret
	