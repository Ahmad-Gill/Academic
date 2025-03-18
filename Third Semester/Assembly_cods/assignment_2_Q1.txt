[org 0x0100]
jmp start
num1:dw 1110111100001010b
num1_l:dw 15
num2:dw 111100b
num2_l:dw 6
Snum2_l:dw 0
return:dw -1
match:		;Function_to_match_the_subset	
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	mov cx,0x0000
	mov cx,[num2_l]
	sub cx,1
	mov [Snum2_l],cx
	mov cx,0x0000
	mov ax,0x0000
	mov dx,[bp+10]	;first number
	mov bx,[bp+8]	;second number
	mov si,[bp+6]	;length_numer_1
	mov di,[bp+4]	;length_number_2
	shr dx,1
	rcl ax,1
	sub si,1
ceck_first_bit:
	cmp di,0
	jz found
	cmp si,0
	jz not_found
	
	shr bx,1
	rcl cx,1
	sub di,1q
	cmp cx,ax
	jnz retain_bx
	jz sift_right_bx_1
shift_right_dx:
	cmp di,0
	jz found
	cmp si,0
	jz not_found
	shr dx,1
	rcl ax,1
	sub si,1
	cmp cx,ax
	jnz retain_bx
sift_right_bx_1:
	cmp di,0
	jz found
	cmp si,0
	jz not_found
	mov cx,0x0000
	mov ax,0x0000
	shr bx,1
	rcl cx,1
	sub di,1
	shr dx,1
	rcl ax,1
	sub si,1
	cmp cx,ax
	jnz retain_bx
	jmp sift_right_bx_1
retain_bx:
	cmp di,0
	jz found
	cmp si,0
	jz not_found	
	mov cx,0x0000
	mov ax,0x0000
	cmp di,[Snum2_l]
	jnz l2 
	shr dx,1
	rcl ax,1
	sub si,1
l2:
	mov bx,[bp+8]	;second number
	mov di,[bp+4]	;length_number_2
	jmp ceck_first_bit
found:
	mov si,[bp+6]	;length_numer_1
	mov di,[bp+4]	;length_number_2
	sub si,di
	mov [return],si
	jmp end
not_found:
	mov bx,-1
	jmp end
end:
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 8
	
start:
	mov ax,[num1]
	push ax
	mov ax,[num2]
	push ax
	mov ax,[num1_l]
	push ax
	mov ax,[num2_l]
	push ax
	call match
	mov bx,[return]
	

                                                                                                                                                                                                                                                                                             
mov ax , 0x4c00
int 0x21

n : dw 7