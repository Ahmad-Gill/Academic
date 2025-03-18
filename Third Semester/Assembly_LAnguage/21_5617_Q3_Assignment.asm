[org 0x0100]
jmp start


start:
 	mov ax, [input1]
	push ax 			; place the first value on stack
	mov ax, [input2]
	push ax 			; place second element on stack
	mov ax, [input3]
	push ax 			; place third element on stack
	mov ax, [input4]
	push ax 			; place fourth element on stack
	call extra_function
	mov ax,[return1]
	mov bx,[return2]
	mov cx,[return3]

	mov ax, 0x4c00 		; terminate program
	int 0x21

input1:dw 1
input2:dw 2
input3:dw 3
input4:dw 4
return1:dw 0
return2:dw 0
return3:dw 0


extra_function:
	
	push bp
	mov bp,sp
	sub sp,10			;create a space of 5 words
	push ax
	push bx
	push cx
	push si
	push di
	
	mov ax,[bp+10]
	mov bx,[bp+8]
	mov cx,[bp+6]
	mov si,[bp+4]
			; Use local variables to store
	mov [bp-2],ax
	mov [bp-4],bx
	mov [bp-6],cx
	mov [bp-8],si
			; retore values from local variables
	mov ax,[bp-2]
	mov bx,[bp-4]
	mov cx,[bp-6]
	mov si,[bp-8]
			; Basic function
	add ax,bx
	mov [return1],ax
	add ax,cx
	mov [return2],ax
	add ax,si
	mov [return3],ax

	pop di
	pop si
	pop cx
	pop bx
	pop ax
	add sp,10
	mov sp,bp
	pop bp
	ret 8
			
	ret   			; go back and remove two params
	