[org 0x100]

jmp start

string: db 0, 0, 0, 0

calculte:
	push bp
	mov bp, sp
	
	push ax
	push dx
	push bx
	push si
	
	mov bx, 16
	mov ax, [bp + 4]
	mov word[bp + 6], 0
loop1:	
	mov dx, 0
	div bx
	
	add [bp + 6], dx
	
	cmp ax, 0
	jne loop1
	
	shr word[bp + 6], 2
	
	mov ax, [bp + 6]
	add ax, 2
	
	mov word[bp + 8], ax
	
	pop si
	pop bx
	pop dx
	pop ax
	pop bp
	ret 2
	
sum_:
	push bp
	mov bp,sp
	
	push ax
	push bx
	push cx
	push dx
	
	mov bx, [bp + 4]
	mov ax, 1
	mov cx, [bp + 6]
	
	mov word[bp + 8], 0
	mov word[bp + 10], 0
	
	loop2:
	mov dx, 0
	mul bx
	
	add [bp + 8], ax
	adc [bp + 10], dx
	
	loop loop2
	
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4

	
start:
	sub sp, 2
	mov ax, 5617h
	push ax
	call calculate
	pop ax
	pop bx
	sub sp, 4
	push bx
	push ax
	
	call sum_
	
	pop dx
	pop cx

mov ax, 0x4c00
int 0x21