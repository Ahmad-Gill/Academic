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
message12:db 'TIMER: 00:00', 0
message13:db 'Score: ',0 


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

;checking key for s
check_key:
mov ah, 0
int 16
ret

main_window:
call upper
call bucket
call randomobj1
call randomobj2
call randomobj3
call timer

mov ax, 80
push ax
call score
ret

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
mov ax, 0
push ax
mov ax, 1
push ax
mov ax, 0x30
push ax
mov ax, message12
push ax
call printstr

ret

score:
mov ax, 70
push ax
mov ax, 1
push ax
mov ax, 0x30
push ax
mov ax, message13
push ax
call printstr

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

mov di, 77

nextpos:
pop dx
mov dh, 0x07
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

randomobj1:
mov ax, 10
push ax
mov ax, 5
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 10
push ax
mov ax, 6
push ax
mov ax, 0x70
push ax
mov ax, message9
push ax
call printstr

mov ax, 10
push ax
mov ax, 7
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

ret

randomobj2:
mov ax, 25
push ax
mov ax, 10
push ax
mov ax, 0x10
push ax
mov ax, message8
push ax
call printstr

mov ax, 25
push ax
mov ax,11
push ax
mov ax, 0x10
push ax
mov ax, message10
push ax
call printstr

mov ax, 25
push ax
mov ax, 12
push ax
mov ax, 0x10
push ax
mov ax, message8
push ax
call printstr

ret

randomobj3:
mov ax, 40
push ax
mov ax, 14
push ax
mov ax, 0x50
push ax
mov ax, message8
push ax
call printstr

mov ax, 40
push ax
mov ax, 15
push ax
mov ax, 0x50
push ax
mov ax, message11
push ax
call printstr

mov ax, 40
push ax
mov ax, 16
push ax
mov ax, 0x50
push ax
mov ax, message8
push ax
call printstr

ret

bucket:
mov ax, 38
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr


mov ax, 39
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 40
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 41
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 42
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 43
push ax
mov ax, 18
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 38
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 39
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 40
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 41
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 42
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 43
push ax
mov ax, 19
push ax
mov ax, 0x70
push ax
mov ax, message8
push ax
call printstr

mov ax, 38
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 39
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 40
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 41
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 42
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 43
push ax
mov ax, 20
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 38
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr


mov ax, 39
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 40
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 41
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 42
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

mov ax, 43
push ax
mov ax, 21
push ax
mov ax, 0x07
push ax
mov ax, message8
push ax
call printstr

ret

;main function
start:
call clrscr

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

call clrnormal
call delay

call main_window

mov ax, 0x4c00
int 21h