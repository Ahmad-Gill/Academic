[org 0x0100]
jmp start


scrolldown:
	 push bp
	mov bp,sp
	push ax
	push cx
	push si
	push di
	push es
	push ds
	mov ax, 80 
	mul byte [bp+4] 
	push ax 
	shl ax, 1 
	mov si, 3998 
	mov  si,0 
	mov cx, 2000 
	sub cx, ax 
	mov ax, 0xb800
	mov es, ax 
	mov ds, ax 
	mov di,2880  
	cld 
	rep movsw 
	mov ax, 0x0720 
	pop cx
	rep stosw 
	pop ds
	pop es
	pop di
	pop si
	pop cx
	pop ax
	pop bp
	ret 2
	start: mov ax,7
	push ax 
	call scrolldown 
	mov ax, 0x4c00 
	int 0x21