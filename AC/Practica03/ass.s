3.
        movl $0, %eax  # i
        movl $0, %ebx  # j
        leal ResFila, %ecx 
        movl $1, (%ecx) # ResFila[0] = 1
        leal Matriz, %esi

for:    cmpl $400, %eax
        jge endfor
        imull $40, %edx
        addl %edx, %esi    # Matriz[i]

while:  movl (%esi, %ebx, 4), %edx
        cmpl $0, %edx 
        je endwhile
if:     cmpl $100, %edx
        jne endif
        movl (%ecx, %eax, 4), %edi 
        imull %edx, %edi 
        movl %edi, (%edi)

endif:
        incl %ebx
        jmp while
endwhile:
        incl %eax
        movl $0, %ebx
        movl $1, (%ecx, %eax, 4) 
        jmp for
endfor:
