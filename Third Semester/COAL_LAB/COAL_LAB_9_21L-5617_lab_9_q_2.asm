[org 0x0100]
jmp start
x:dw 0
value:dw 0
y:dw 0
location:dw 0
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
	ret
GenRandNum:
push bp
mov bp,sp;
push cx
push ax
push dx;

MOV AH, 00h ; interrupts to get system time 
INT 1AH ; CX:DX now hold number of clock ticks since midnight 
mov ax, dx
xor dx, dx
mov cx, 80; 
div cx ; here dx contains the remainder of the division - from 0 to 9

add dl, '0' ; to ascii from '0' to '9'

mov word[x],dx;
mov word[y],ax
mov ax,80
mul byte[y]
add ax,[x]
mov di,ax
l2:
cmp di,0xbb8
jb l1
sub di,1000
jmp l2

l1:
mov [location],di


pop cx;
pop ax;
pop dx;
pop bp;
ret
start:
	call clearSecreen
call GenRandNum
l4:
	mov ax, 0xb800 	
	; load video base in ax
	mov di,[location]
	mov es, ax 	
	mov ah,[location]
	mov al,bl
	
	
	mov word [es:di],ax
	add word [location],2
	add bl,2
call delay
call clearSecreen
	cmp word[location],4000
	jnz l4

	mov ax, 0x4c00 		; terminate program
	int 0x21
	