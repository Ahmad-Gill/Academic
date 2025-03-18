[org 0x0100]
jmp start
l3:
	add ax,di
	sub di,1
	jnz l3
	jmp l1
l2:
	add ax,si
	sub si,1
	jnz l2
	jmp l3
start:
	mov cl,0
l1:
	mov bx,ax
	add cx,1
	add ax,cx
	cmp cx,12
	jz end
	mov si,cx
	mov di,cx
	sub si,1
	sub di,1
	jz l1
	jmp l2
end:	
	mov ax, 0x4c00 
	int 0x21