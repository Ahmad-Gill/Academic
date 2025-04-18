[org 0x100]
jmp start
sequence_1: dw 1110111100001010b
sequence_2: dw 111100b
len_1: dw 15
len_2: dw 5
res: dw 0
sequence:
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	mov ax,[bp+10] ;sequence_1
	mov bx,[bp+8] ;sequence_2
	mov di,[bp+6] ;len_1
	mov si,[bp+4] ;len_2
	
	
checking:
	mov cx,0
		mov dx,0
	cmp di,0
	jz end
	cmp si,0
	jz end_2
	shr ax,1
	rcl cx,1
	sub di,1

loopy:
	mov dx,0
	shr bx,1
	

	rcl dx,1
	sub si,1
	cmp cx,dx
	je  checking
compare:
	mov bx,[bp+8]
	cmp si,[bp+4]
	jz loopy
	mov si,[bp+4] ;len_2
	jmp checking
end:
	mov dx,1 ;nai mila
	mov [res],dx
	jmp popps
end_2:
	mov dx,2 ;mil gaya
	mov [res],dx
	jmp popps 	
	
popps:
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 8
start:
	mov ax,[sequence_1]
	push ax
	mov ax,[sequence_2]
	push ax
	mov ax,[len_1]
	push ax
	mov ax,[len_2]
	push ax
	call sequence
	mov bx,[res]
mov ax,0x4c00
int 0x21
	
	
	
