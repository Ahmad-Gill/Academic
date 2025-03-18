[org 0x0100]
value:dw 0
jmp start
delay:

	mov ax,3
	
oloop:
	mov cx,0xffff

	sub ax,1
	cmp ax,0
	je ret
iloop:
	sub cx,1
	cmp cx,0
	jne iloop
	jmp oloop
ret:
	ret
	
	
clearSecreen:
	mov ax, 0xb800 		; load video base in ax
	mov es, ax 			; point es to video base
	mov di, 0 			; point di to top left column
nextchar: 
	mov word [es:di], 0x0720 ; clear next char on screen
	add di, 2 			; move to next screen location
	cmp di, 4000 		; has the whole screen cleared
	jne nextchar 
	ret		; if no clear next position
start:
	call clearSecreen
	mov di,0
	mov cx,4000
	mov ax, 0xb800 		; load video base in ax
	mov es, ax 	
	mov bl,0
	

l1:

	
		mov ax, 0xb800 	
	; load video base in ax
	mov di,[value]
	mov es, ax 	
	mov ah,[value]
	mov al,bl
	
	
	mov word [es:di],ax
	add word [value],2
	add bl,2
call delay
call clearSecreen
	
	loop l1
	mov ax, 0x4c00 		; terminate program
	int 0x21
	