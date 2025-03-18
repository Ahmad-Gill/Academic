[org 0x0100]
jmp start
 message: db 'SNAKE_&_APPLE' ; string to be printed
message1:db  'BY MUHAMMAD AHMAD GILL'
message2: db 'MUHAMMAD AHMAD'
message3: db '21L-5617'
message4:db 'PRESS ANY KEY TO CONTINUE'
message5:db 'YOU LOSS THE GAME'
message6:db 'TOTAL SCORE IS = '
message7:db 'SELECT DIFFICULTY LEVEL 1,2,3'
message8:db '1: low 2: medium 3: hard' 
difficulty: dw 7
count:dw 80
x:dw 0
value:dw 0
y:dw 0
location:dw 0

up:dw 0
down:dw 1
left:dw 2
right:dw 3

playerx: dw 40
playery:dw 12
Applex:dw 16
Appley:dw 8

direction:dw 3
y_axis:dw 2


snakeLength:dw 1
difficulti:
	mov ax, 0xb800
	mov es, ax ;  point es to video base
	mov di, 1970 ; point di to top left column
	mov si, message7 ; point si to string
	mov cx, 29 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
	g: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop g; repeat the operation cx times
	call delay

	mov ax, 0xb800
	mov es, ax ;  point es to video base
	mov di, 2450 ; point di to top left column
	mov si, message8 ; point si to string
	mov cx, 24 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
	d: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop d; repeat the operation cx times
	call delay
	ret

GenRand_location:
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

	mov word[Applex],dx;
	mov word[Appley],ax
q:
	mov dx,[Applex];
	mov ax,[Appley]
	cmp word[Applex],4
	jbe l2
	cmp word[Applex],70
	jae p
	cmp word[Appley],5
	jbe o
	cmp word[Appley],19
	jae r
	jmp t

v:
	add word[Applex],3
	jmp q

	jmp v
p:
	sub word[Applex],10	
	jmp q
o:
	add word[Appley],5
	jmp q
r:
	sub word[Appley],5
	jmp q
t:

	pop cx
	pop ax
	pop dx;
	pop bp;
	ret
game_loos:
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 1664 ; point di to top left column
	mov si, message6 ; point si to string
	mov cx, 17 ; load length of string in cx
	mov ah, 74 ; normal attribute fixed in al
	c: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop c ; repeat the operation cx times
	mov ax,[snakeLength]

	sub ax,1
	push ax
	
	mov ax,1698
	push ax
	mov ax,74
	PUSH AX
	call printnum



mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 1344 ; point di to top left column
	mov si, message5 ; point si to string
	mov cx, 17 ; load length of string in cx
	mov ah, 74 ; normal attribute fixed in al
	w: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop w; repeat the operation cx times
	call delay

	ret


starting_window:
	mov word[count],80
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 0 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
ui: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz ui	

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,320  ; point di to top left column

	MOV CX, [count]
	
uy: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz uy
	



	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di, 640 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
yu: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz yu
	
	
	mov ax, 0xb800
	mov word[count],80
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,960  ; point di to top left column

	MOV CX, [count]
	
yt: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz yt

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di, 1280 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
ty: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz ty
	

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,1600  ; point di to top left column

	MOV CX, [count]
	
tr: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz tr


	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di, 1920 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
rt: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz rt
	

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,2240  ; point di to top left column

	MOV CX, [count]
	
re: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz re


	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di, 2560 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
er: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz er
	

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,2880 ; point di to top left column

	MOV CX, [count]
	
ew: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz ew


	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di, 3200 ; point di to top left column
	mov al,0x20
	MOV CX, [count]
	mov ah,0x30
we: 
	mov word[es:di],0xe020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz we
	

	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,3520  ; point di to top left column

	MOV CX, [count]
	
wq: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz wq


	mov ax, 0xb800
	mov word[count],80
	mov es, ax ; point es to video base
	mov di,3840  ; point di to top left column

	MOV CX, [count]
	
sd: 

	mov word[es:di],0x6020 ; show this char on screen

	add di, 2 ; move to next screen location
	sub word[count],1
	jnz sd

	
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 2822 ; point di to top left column
	mov si, message2 ; point si to string
	mov cx, 14 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
nex: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop nex ; repeat the operation cx times
	call delay

	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 1344 ; point di to top left column
	mov si, message ; point si to string
	mov cx, 13 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
e: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop e; repeat the operation cx times
	call delay

	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 2012 ; point di to top left column
	mov si, message3 ; point si to string
	mov cx, 8 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
a: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop a; repeat the operation cx times

	call delay

	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 3250 ;point di to top left column
	mov si, message4 ; point si to string
	mov cx, 25 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
	b: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop b ; repeat the operation cx times
	call delay

	ret



;delay function
delay:
	mov ax,[difficulty]
oloop:
	
	mov cx, 0xFFFF
	sub ax,1
	cmp ax,0
	
	je return
iloop:

	sub cx,1
	cmp cx,1
	jne iloop
	jmp oloop

	
return:
	ret
;delay function
special_delay:
	mov ax,7
oloo:
	
	mov cx, 0xFFFF
	sub ax,1
	cmp ax,0
	
	je retur
iloo:

	sub cx,1
	cmp cx,1
	jne iloo
	jmp oloo

	
retur:
	ret
printstr: 
mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 0 ; point di to top left column
	mov si, message6 ; point si to string
	mov cx, 17 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
	u: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop u ; repeat the operation cx times
	mov ax,[snakeLength]
	sub ax,1
	push ax
	mov ax,34
	push ax
	MOV AX,0X74
	PUSH AX
	
	call printnum
	

	
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov di, 380 ; point di to top left column
	mov si, message ; point si to string
	mov cx, 13 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
xi: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop xi ; repeat the operation cx times
	

	
	mov di, 3790; point di to top left column
	mov si, message1 ; point si to string
	mov cx, 22 ; load length of string in cx
	mov ah, 0x74 ; normal attribute fixed in al
nx: 
	mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop nx ; repeat the operation cx times
	ret


make_bord:
	mov ax, 0xb800 		; load video base in ax
	mov es, ax 			; point es to video base
	mov di, 3520			; point di to top left column
next: 
	mov word [es:di], 0x1012 ; clear next char on screen
	add di, 2 			; move to next screen location
	cmp di, 4000	; has the whole screen cleared
	jne next
	mov di, 0			; point di to top left column
n: 
	mov word [es:di], 0x1012 ; clear next char on screen
	add di, 2 			; move to next screen location
	cmp di, 640	; has the whole screen cleared
	jne n
	

	
	mov di,480
	mov cx, 20

l:

	mov word [es:di], 0x1012
	add di,160
	loop l
	


	mov di,484
	mov cx, 20
	
l0:

	mov word [es:di], 0x1012
	add di,160
	loop l0
	

	mov di,482
	mov cx, 20
l1:

	mov word [es:di], 0x1012
	add di,160
	loop l1
	


	mov di,318
	mov cx, 22
l2:

	mov word [es:di], 0x1012
	add di,160
	loop l2
	

	
	mov di,316
	mov cx, 22
l3:

	mov word [es:di], 0x1012
	add di,160
	loop l3
	

	

	mov di,314
	mov cx, 22
l4:

	mov word [es:di], 0x1012
	add di,160
	loop l4
	

	ret

clearSecreen:
	mov ax, 0xb800 		; load video base in ax
	mov es, ax 			; point es to video base
	mov di, 0 			; point di to top left column
nextcha: 
	mov word [es:di], 0x4020 ; clear next char on screen
	add di, 2 			; move to next screen location
	cmp di, 4000 		; has the whole screen cleared
	jne nextcha


	ret

start:
call clearSecreen


call starting_window
;call make_bord
	mov ah,0
	int 16h
call clearSecreen
call difficulti
call make_bord
	mov ah,0
	int 16h

	cmp al,0x31
	je low

	cmp al,0x32
	je medium

	cmp al,0x33
	je high
low:
	mov word [difficulty],7
	jmp setup_game
medium:
	mov word [difficulty],5
	jmp setup_game
high:
	mov word [difficulty],3
	jmp setup_game	




setup_game:
;Clear the secreen all the time

game_loop:
	mov ax,0x4020
	xor di,di
	mov cx,4000
	rep stosw
call make_bord
call printstr

;Draw snake 

	xor bx,bx

snake_loop:	
	mov cx,[snakeLength]
	mov ax,80
	mul byte [playery] 
	add ax,[playerx]
	add ax,bx
	shl ax,1
	mov di,ax
	mov ah,0x40
	cmp word[direction],0x0
	je qw
	cmp word[direction],0x3
	je qq

	cmp word[direction],0x1
	je qe
	cmp word[direction],0x2
	je qr

qq:
	mov al,0x3e
	jmp snake4
qw:
	mov al,0x5e
	jmp snake2

	

qe:
	mov al,0x76
	jmp snake3
qr:
	mov al,0x3c
	jmp snake1
	
	
snake4:	
	mov [es:di],ax
	sub di,2
	loop snake4	
	jmp helo
snake1:	
	mov [es:di],ax
	add di,2
	loop snake1
	jmp helo

snake2:
	mov [es:di],ax
	add di,160
	loop snake2
	jmp helo
snake3:
	mov [es:di],ax
	sub di,160
	loop snake3

helo:	
;draw apple
	mov ax,80
	mul byte [Appley]
	add ax,[Applex]
	shl ax,1
	mov di,ax
	mov ah,0x00
	mov al,0x7f
	 stosb
;Move snake in current  direction 
	mov al,[direction]
	cmp al,[up]
	je move_up
   
	cmp al,[down]
	je move_down
	
	cmp al,[left]
	je move_left
	
	cmp al,[right]
	je move_right
	
	jmp get_player_input
   
move_up:
	sub word [playery],1
	jmp get_player_input

move_down: 
	add word [playery],1
	jmp get_player_input
move_left: 
	sub word [playerx],1

	jmp get_player_input
	

move_right: 
	add word [playerx],1

	jmp get_player_input

;Update snake position
update_snake:

get_player_input:
 	mov bl,[direction] ;save current direction

	mov ah,0x1
	int 0x16  ;chek the keyboard status

	jz check_apple  ;if no key were pressed
	
	xor ah,ah
	int 0x16    		;GET KEY STROKE ah = SCANE CODE AL=asci code

	cmp ah,0x48
	je press_up

	cmp ah,0x50
	je press_down

	cmp ah,0x4b
	je press_left
	
	cmp ah,0x4d
	je press_right

	jmp check_apple

press_up:

	mov bl ,[up]
	jmp check_apple
press_down:


	mov bl,[down]
	jmp check_apple
press_left:

	mov bl,[left]
	jmp check_apple

press_right:


	mov bl,[right]
	jmp check_apple


;check_player hit Apple
check_apple:
	mov byte [direction],bl
	mov ax,[playerx]
	cmp ax,[Applex]
	jne l9
	mov ax,[playery]
	cmp ax,[Appley]
	jne l9

;eat apple


	add word [snakeLength],1
	
nextApple:
	call GenRand_location

;Hit border of secreen


l9:
;hit border
	cmp word[playery],3  ;Upper border
	je game_lost
	cmp word[playery],22	;lower border
	je game_lost
	
	cmp word[playerx],3 ;left secreen
	je game_lost
	
	
	cmp word[playerx],77
	je game_lost
	

lx:
	cmp word[direction],0
	je ly
	cmp word[direction],1
	je ly
call delay
	jmp oo
ly:
call special_delay
oo:
	jmp game_loop


game_lost:
call clearSecreen
call game_loos
 	mov ax, 0x4c00
	int 21h
printnum:
	push bp
	mov bp, sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov ax, [bp+8] ; load number in ax
	mov bx, 10 ; use base 10 for division
	mov cx, 0 ; initialize count of digits
nextdigit:
	 mov dx, 0 ; zero upper half of dividend
	div bx ; divide by 10
	add dl, 0x30 ; convert digit into ascii value
	push dx ; save ascii value on stack
	inc cx ; increment count of values
	cmp ax, 0 ; is the quotient zero
	jnz nextdigit ; if no divide it again
	mov di,[bp+6]
	nextpos: pop dx ; remove a digit from the stack
	mov dh,[bp+4] ; use normal attribute
	mov [es:di], dx ; print char on screen
	add di, 2 ; move to next screen location
	loop nextpos ; repeat for all digits on stack
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop es
	pop bp
	ret 6