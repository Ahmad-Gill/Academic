[org 0x0100]

jmp start

message1: db 'Urwa Ihtesham', 0
message2: db 'Eisha Amir', 0
message3: db '21L-5404', 0
message4: db '21L-5255', 0
message5: db 'Catch & Score', 0
message6: db 'PRESS ANY KEY TO START', 0
message7: db 'WELCOME TO THE GAME', 0
message8: db '      ', 0
message9: db ' obj1 ', 0
message10:db ' obj2 ', 0
message11:db ' TNT  ', 0
message12:db 'TIMER: ', 0
message13:db 'Score: ',0 
message14:db 'YOUR SCORE IS: ', 0
message15:db '<<GAME OVER!!!!!>>', 0
b: dd 2950
r1: dd 335
r2: dd 375
r3: dd 415
s: dd 00
s1: dd 5
s2: dd 10
s3: dd 0
time: dd 20
tickcount: dw 0
second: dw 0

;clear screen with a blue background
clrscr: 
push es
push ax
push cx
push di
mov ax, 0xb800
mov es, ax 
xor di, di 
mov ax, 0x1020 
mov cx, 2000
cld 
rep stosw 
pop di
pop cx
pop ax
pop es
ret

;clear screen with normal background
clrnormal:
push es
push ax
push cx
push di
mov ax, 0xb800
mov es, ax 
xor di, di 
mov ax, 0x0720 
mov cx, 2000
cld 
rep stosw 
pop di
pop cx
pop ax
pop es
ret

;delay function
delay:
push cx
mov cx, 0xFFFF
loop1:
loop loop1
mov cx, 0xFFFF
loop2: 
loop loop2
pop cx
ret

;print a string
printstr:
push bp
mov bp, sp
push es
push ax
push cx
push si
push di
push ds
pop es 
mov di, [bp+4] 
mov cx, 0xffff 
xor al, al 
repne scasb
mov ax, 0xffff 
sub ax, cx 
dec ax 
jz exit 
mov cx, ax 
mov ax, 0xb800
mov es, ax 
mov al, 80 
mul byte [bp+8] 
add ax, [bp+10] 
shl ax, 1 
mov di,ax 
mov si, [bp+4] 
mov ah, [bp+6] 
cld
next_char: 
lodsb 
stosw
loop next_char 
exit1: pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 8



;print an object
print:
push bp
mov bp, sp
push es
push ax
push cx
push si
push di
push ds
pop es 
mov di, [bp+4] 
mov cx, 0xffff 
xor al, al 
repne scasb
mov ax, 0xffff 
sub ax, cx 
dec ax 
jz exit 
mov cx, ax 
mov ax, 0xb800
mov es, ax 
mov al, 80 
mul byte [bp+8] 
add ax, [bp+10] 
shl ax, 1 
mov di,ax 
mov si, [bp+4] 
mov ah, [bp+6] 
cld
nextchar: 
lodsb 
stosw
call delay 
loop nextchar 
exit: pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 8

;checking key for input
check_key:
mov ah, 0x1	;check for no key
int 16h
jnz helo
;;;;;;;;;
xor ah,ah		
int 0x16
cmp ah, 0x4B	;check for left key
jz left
;;;;;;;;;
;;;;;;;;;
cmp ah, 0x4D		; check for rigth key
add word[b],2
jmp helo
left:
sub word[b],2
jmp helo
helo:
ret

;when random object 1 touch the ground, 
;it will go to its initial position
initial1:		
mov ax, 335
mov [r1], ax
;;;;;;;;;;;
mov ax, [r1]
push ax
call randomobj1
ret

;when random object 2 touch the ground,
;it will go to its initial position
initial2:
mov ax, 375
mov [r2], ax
ret

;when random object 3 touch the ground, 
;it will go to its initial position
initial3:
mov ax, 415
mov [r3], ax
ret

main_window:
;;;;;;
call check_key
mov ax, [b]
push ax
call bucket	;function: print bucket on the screen
;;;;;;;;;;;;;
mov ax, [r1]
push ax
call randomobj1	;function: print random object 1 on the screen
call delay		;function: delay
call delay
call delay
call delay
call delay
mov ax, [r1]	;moving the random obj 1 to the next line
add ax, 160
;add ax, 2
mov [r1], ax	;checking if the random obj 1 touches the ground
cmp ax, 2895
je initial1	;function: initial position of random object 1
;;;;;;;;;;;;;
mov ax, [r2]	
push ax
call randomobj2	;function: print random object 2 on the screen
call delay		;function delay
call delay
call delay
call delay
call delay
mov ax, [r2]	;moving random object 2 to the next line
add ax, 160
mov [r2], ax	;checking if random obj 2 touches the ground
cmp ax, 2935
je initial2	;function: initial position of random object 2
;;;;;;;;;;;;;
mov ax, [r3]
push ax
call randomobj3	;function: print TNT on the screen
call delay		;function: delay
call delay
call delay
mov ax, [r3]	;moving TNT to the next line
add ax, 160
mov [r3], ax	;checking if TNT touches the ground
cmp ax, 2975
je initial3	;function: initial position of TNT
;;;;;;;;;;;;;
mov ax, 0
push ax
mov ax, 1
push ax
mov ax, 0x30
push ax
mov ax, message12
push ax
call printstr	;function: print 'TIMER: ' on the screen
;mov ax, [timer]
;push ax
;call timer		;function: print the number on the screen of timer
call delay		;function: delay
call delay
call untimer	;function: removes the digits of timer from the screen
;;;;;;;;;;;;;
mov ax, 70
push ax
mov ax, 1
push ax
mov ax, 0x30
push ax
mov ax, message13
push ax
call printstr	;function: print 'SCORE: ' on the screen
mov ax, [s]
push ax
call score		;function: print the digits of score on the screen
;;;;;;;;;;;;;
mov ax, [r1]
sub ax, 160
push ax
call clrobject1	;function: clear object 1 from the screen
;;;;;;;;;;;;;
mov ax, [r2]
sub ax, 160
push ax
call clrobject2	;function: clear object 2 from the sceen
;;;;;;;;;;;;;
mov ax, [r3]
sub ax,160
push ax
call clrobject3	;function: clear object 3 from screen
;;;;;;;;;;;;
ret

untimer:
push es
push ax
push di
;;;;;;;;;;;;
mov ax, 0xb800
mov es,ax
mov di, 172
;;;;;;;;;;;;
n20:
mov word[es:di], 0x3020
add di, 2
cmp di, 178
jne n20
;;;;;;;;;;;
pop di
pop ax
pop es
ret

clrobject1:
push bp
mov bp, sp
push es
push ax
push di
mov ax, 0xb800
mov es,ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n10:
mov word[es:di], 0x2030
add di,2
cmp di,dx
jne n10

add di,160
sub di,2
mov dx, di
sub dx, 12

n11:
mov word[es:di], 0x2030
sub di, 2
cmp di,dx
jne n11

add di,160
add di,2
mov dx, di
add dx, 12

n12:
mov word[es:di], 0x2030
add di,2
cmp di,dx
jne n12

pop di
pop ax
pop es
pop bp

ret 2


clrobject3:
push bp
mov bp, sp
push es
push ax
push di
mov ax,0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n17:
mov word[es:di], 0x2030
add di,2
cmp di, dx
jne n17

add di, 160
sub di, 2
mov dx, di
sub dx, 12
n18:
mov word[es:di], 0x2030
sub di,2
cmp di,dx
jne n18

add di,160
add di,2
mov dx, di
add dx, 12
n19:
mov word[es:di], 0x2030
add di,2
cmp di,dx
jne n19

pop di
pop ax
pop es
pop bp

ret 2

clrobject2:
push bp
mov bp, sp
push es
push ax
push di
mov ax,0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n13:
mov word[es:di], 0x2030
add di,2
cmp di, dx
jne n13

add di, 160
sub di, 2
mov dx, di
sub dx, 12
n14:
mov word[es:di], 0x2030
sub di,2
cmp di,dx
jne n14

add di,160
add di,2
mov dx, di
add dx, 12
n15:
mov word[es:di], 0x2030
add di,2
cmp di,dx
jne n15

pop di
pop ax
pop es
pop bp

ret 2

randomobj2:
push bp
mov bp, sp
push es
push ax
push di
mov ax,0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n4:
mov word[es:di], 0x2010
add di,2
cmp di, dx
jne n4

add di, 160
sub di, 2
mov dx, di
sub dx, 12
n5:
mov word[es:di], 0x2010
sub di,2
cmp di,dx
jne n5

add di,160
add di,2
mov dx, di
add dx, 12
n6:
mov word[es:di], 0x2010
add di,2
cmp di,dx
jne n6

pop di
pop ax
pop es
pop bp

ret 2

randomobj1:
push bp
mov bp, sp
push es
push ax
push di
mov ax,0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n1:
mov word[es:di], 0x2070
add di,2
cmp di, dx
jne n1

add di, 160
sub di, 2
mov dx, di
sub dx, 12
n2:
mov word[es:di], 0x2070
sub di,2
cmp di,dx
jne n2

add di,160
add di,2
mov dx, di
add dx, 12
n3:
mov word[es:di], 0x2070
add di,2
cmp di,dx
jne n3

pop di
pop ax
pop es
pop bp

ret 2

randomobj3:
push bp
mov bp, sp
push es
push ax
push di
mov ax,0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x7020
mov dx, di
add dx, 12

n7:
mov word[es:di], 0x2050
add di,2
cmp di, dx
jne n7

add di, 160
sub di, 2
mov dx, di
sub dx, 12
n8:
mov word[es:di], 0x5450
sub di,2
cmp di,dx
jne n8

add di,160
add di,2
mov dx, di
add dx, 12
n9:
mov word[es:di], 0x2050
add di,2
cmp di,dx
jne n9

pop di
pop ax
pop es
pop bp

ret 2

clear:
push bp
mov bp, sp
push es
push ax
push di
mov ax, 0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x1020
mov dx, di
add dx, 14

nee:
mov word[es:di], 0x3020
add di,2
cmp di, dx
jne nee

add di,160
sub di,2
mov dx, di
sub dx, 14
nee1:
mov word[es:di], 0x3020
sub di, 2
cmp di,dx
jne nee1

add di, 160
add di,2
mov dx, di
add dx, 14
nee2:
mov word[es:di], 0x6020
add di,2
cmp di, dx
jne nee2

pop di
pop ax
pop es
pop bp
ret 2

bucket:
push bp
mov bp, sp
push es
push ax
push di
mov ax, 0xB800
mov es, ax
mov di, [bp+4]
mov cx, 0x1020
mov dx, di
add dx, 14

ne:
mov word[es:di], 0x0120
add di,2
cmp di, dx
jne ne

add di,160
sub di,2
mov dx, di
sub dx, 14
ne2:
mov word[es:di], 0x7020
sub di, 2
cmp di,dx
jne ne2

add di, 160
add di,2
mov dx, di
add dx, 14
ne3:
mov word[es:di], 0x0120
add di,2
cmp di, dx
jne ne3

pop di
pop ax
pop es
pop bp
ret 2

upper:
push es
push ax
push di
mov ax, 0xB800
mov es, ax
mov di, 0
mov cx, 0x3020

nextloc:
mov word[es:di], 0x3020
add di,2
cmp di, 3200
jne nextloc

next_loc:
mov word[es:di], 0x6020
add di,2
cmp di, 4000
jne next_loc

pop di
pop ax
pop es
ret

timer:
push ax
inc word[cs: tickcount]
cmp word[cs:tickcount], 15
jne endtimer
mov word[cs:tickcount], 0
inc word[cs:second]
;push word[cs:tickcount]

push word[cs:second]
call printt
call delay
call delay
mov ax, [cs:tickcount]
cmp ax, 2184
jne endtimer

endtimer:
mov al, 0x20
out 0x20, al
pop ax
iret

printt:
push bp
mov bp,sp 
push es
push ax
push bx
push cx
push dx
push di

mov ax, 0xB800
mov es, ax
mov ax, [bp+4]
mov bx, 10
mov cx, 0

nextd:
mov dx, 0
div bx
add dl, 0x30
push dx
inc cx
cmp ax, 0
jnz nextd

mov di, 171

nextp:
pop dx
mov dh, 0x30
mov [es:di], dx
add di, 2
loop nextp

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2

score:
push bp
mov bp,sp 
push es
push ax
push bx
push cx
push dx
push di

mov ax, 0xB800
mov es, ax
mov ax, [bp+4]
mov bx, 10
mov cx, 0

nextdigit:
mov dx, 0
div bx
add dl, 0x30
push dx
inc cx
cmp ax, 0
jnz nextdigit

mov di, 314

nextpos:
pop dx
mov dh, 0x30
mov [es:di], dx
add di, 2
loop nextpos

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2



starting_screen:
mov ax, 1
push ax
mov ax, 1
push ax
mov ax, 0x02
push ax
mov ax, message1
push ax
call print
call delay

mov ax, 16
push ax
mov ax, 1
push ax
mov ax, 0x02
push ax
mov ax, message3
push ax
call print
call delay

mov ax, 30
push ax
mov ax, 1
push ax
mov ax, 0x02
push ax
mov ax, message2
push ax
call print
call delay

mov ax, 43
push ax
mov ax, 1
push ax
mov ax, 0x02
push ax
mov ax, message4
push ax
call print
call delay

mov ax, 20
push ax
mov ax, 2
push ax
mov ax, 0x02
push ax
mov ax, message5
push ax
call print
call delay

mov ax, 20
push ax
mov ax, 5
push ax
mov ax, 0x02
push ax
mov ax, message7
push ax
call print
call delay

mov ax, 20
push ax
mov ax, 10
push ax
mov ax, 0x05
push ax
mov ax, message6
push ax
call print
call delay

call delay
call delay
call delay
call delay
call delay
call delay

mov ah, 0
int 16h

ret

endscore:
push bp
mov bp,sp 
push es
push ax
push bx
push cx
push dx
push di

mov ax, 0xB800
mov es, ax
mov ax, [bp+4]
mov bx, 10
mov cx, 0

nextdi:
mov dx, 0
div bx
add dl, 0x30
push dx
inc cx
cmp ax, 0
jnz nextdi

mov di, 2490

nextpo:
pop dx
mov dh, 0x05
mov [es:di], dx
add di, 2
loop nextpo

pop di
pop dx
pop cx
pop bx
pop ax
pop es
pop bp
ret 2

end_screen:
call clrscr

mov ax, 30
push ax
mov ax, 7
push ax
mov ax, 0x05
push ax
mov ax, message15
push ax
call print
call delay

mov ax, 30
push ax
mov ax, 15
push ax
mov ax, 0x05
push ax
mov ax, message14
push ax
call print
call delay

mov ax, [s]
push ax
call endscore

ret

;main function
start:
call clrscr

;call starting_screen
;call delay

call clrnormal
call delay

xor ax,ax
mov es, ax
cli
mov word[es:8*4], timer
mov [es:8*4+2], cs
sti
mov dx, start
add dx, 15
mov cl, 4
shr dx, cl

mov bx, word[timer]
call upper		;function: background of the game
mov ax, [b]
push ax
call bucket	;function: print bucket on the screen
loooop:
call main_window
mov ax, [b]
push ax
call clear
push word[cs:second]
call printt
mov bx, word[second]
cmp bx, 120
je end
jmp loooop

end:
call clrnormal
call end_screen
mov ax, 0x4c00
int 21h
