[org 0x0100]

	mov ax ,5617
	mov cx,1010101010101010b
	mov bx ,0101010101010101b

	and cx,ax
	and bx,ax

	shr cx,1
	shl bx,1
	or cx,bx
	mov ax,cx

mov ax, 0x4c00 
int 0x21