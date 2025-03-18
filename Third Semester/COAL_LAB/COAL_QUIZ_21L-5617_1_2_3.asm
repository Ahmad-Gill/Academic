[org 0x0100]
jmp start
name: db 'Mr. Ali, Usman, & Anwar! Doing what???? want to travel????',0
name1: db 'msdffg',0
helo:db"HELO.MR"
helo1:db"HELO.MR"
clrsc: push bp
       mov bp,sp
       push es
       push di
       push ax
       mov ax,0xb800
       mov es,ax
       mov di,0
       mov cx,2000
       mov ax,0x0720
       cld
       rep stosw
       pop ax
       pop di
       pop es
       pop bp
       ret


printscr: push bp
          mov bp,sp
          push es
          push di
          push si
          push cx
          push dx
          mov ax,0xb800
          mov es,ax
          mov si,[bp+4]
          mov di,[bp+6]
          mov dx,[bp+4]
          push dx
          mov ah,07
          call stringlength
          cld
ll1:      lodsb
          stosw
          loop ll1
          pop dx
          pop cx
          pop si
          pop di
          pop es
          pop bp
          ret 4


stringlength: push bp
              mov bp,sp
             
              push ax
              push es
              push si
              push di
              push ds
              pop es
              mov di,[bp+4]
              mov cx,0xffff
              xor al,al
              repne scasb
              mov ax,0xffff
              sub ax,cx
              dec ax
              mov cx,ax
             
              pop di
              pop si
              pop es
           
               pop ax
               pop bp
              ret 2
removeSpaces:
	mov ds,[name]

	mov es,[name1]
	xor si,si
	xor di,di
	mov cx,50
	mov al,' '
	
	repne scasb
	

	jmp l1

	
	
start:  call clrsc
  	mov ax,496
        push ax
        mov ax,name
        push ax
        call printscr
	;jmp removeSpaces
l1:
       
       mov ax,696
        push ax
        mov ax,name
        push ax
       ; call printsc
;to reverse the secreen 
	mov si,helo
	mov di,helo1
	mov cx,7
	add di,cx
	sub di,1
	push ds
	pop es
	cld
n:
	movsb
	sub di,2
	loop n

  	mov ax,3062
        push ax
        mov ax,helo
        push ax
        call printscr
mov ax,3220

        push ax
        mov ax,helo1
        push ax
        call printscr
	
        mov ax,0x4c00
        int 21h        

        
      