[org 0x0100]
jmp start
calculate:
	jmp l1
l2:
	add cx,2
	ret 
l1:
	div bx
	add cx,dx
	cmp dx,0
	jnz l1
	shr cx,2
	jmp l2
	ret
start:
	mov cx,0
	mov ax,0x5617
	mov bx,16
	call calculate
	
	mov ax, 0x4c00 
	int 0x21