[org 0x0100]
jmp start
ms: dw 0 
count: dw 0, 0, 0, 0, 0 
tCount: dw -1 
iNo : dw 0
location: db 0 
string1:db 0
string2:db 0
string3:db 0
string4:db 0
string5:db 0
string6:db 0
string7:db 0
string8:db 0
jmp start
;Clear Screen
clrscr:
push es
mov ax, 0xb800
mov es, ax
xor di,di
mov ax,0x0720
mov cx,2000
cld
rep stosw
pop es
ret
;Program to print the stars
printStars: pusha
push es
mov ax, 0xb800
mov es, ax
mov al, 80
mul byte [cs:location]
add ax, 159
shl ax, 1
mov di, ax
mov cx, [cs:tCount]
cmp cx, 0
jle return
l1: mov byte [es:di], '*'
inc byte [cs:location]
add di, 160
loop l1
return: pop es
popa
ret
Jmpzuser:
call clrsr
call delay
mov di,string1
call length
mov di,1960
mov si,string1
call print
call delay
mov si,1920
mov di,1760
mov cx,160
call movement
call delay
call delay
mov di,string2
call length
mov di,1960
mov si,string2
call print
call delay
mov si,1760
mov di,1600
mov cx,320
call movement
call delay
call delay
mov di,string3
call length
mov di,1960
mov si,string3
call print
call delay
mov si,1600
mov di,1440
mov cx,480
call movement
call delay
call delay
mov di,string4
call length
mov di,1960
mov si,string4
call print
call delay
mov si,1440
mov di,1280
mov cx,640
call movement
call delay
call delay
mov di,string5
call length
mov di,1960
mov si,string5
call print
call delay
mov si,1280
mov di,1120
mov cx,800
call movement
call delay
call delay
mov di,string6
call length
mov di,1960
mov si,string6
call print
call delay
mov si,1120
mov di,960
mov cx,960
call movement
call delay
call delay
mov di,string7
call length
mov di,1960
mov si,string7
call print
call delay
mov si,960
mov di,800
mov cx,1120
call movement
call delay
call delay
mov di,string8
call length
mov di,1960
mov si,string8
call print
call delay
mov si,800
mov di,640
mov cx,1120
call movement
CTS: pusha
;These lines will execute for the very first five seconds
cmp word [cs:iNo], 10
jz l2
add word [cs:ms], 55
cmp word [cs:ms], 1000
jl EOI2
mov word [cs:ms], 0 ;Resetting the MilliSeconds to zero
call printStars ;Because the count is to be updated


mov ax, [cs:tCount]
mov bx, [cs:iNo]
mov word [cs:count + bx], ax
mov word [cs:tCount], 0
add word [cs:iNo], 2
jmp EOI2
l2: add word [cs:ms], 55
cmp word [cs:ms], 1000
jl EOI2
mov word [cs:ms], 0 ;Resetting the MilliSeconds to zero
;Shifting the counts towards the right, to create a space for this current second
mov dx, 0
mov ax, [cs:count + 2]
add dx, ax
mov [cs:count], ax
mov ax, [cs:count + 4]
add dx, ax
mov [cs:count + 2], ax
mov ax, [cs:count + 6]
add dx, ax
mov [cs:count + 4], ax
mov ax, [cs:count + 8]
add dx, ax
mov [cs:count + 6], ax
mov ax, [cs:tCount]
add dx, ax
mov [cs:count + 8], ax
jmp a1
EOI2: jmp EOI ;Intermediate
;Now dx contains the count of the last five seconds
a1: mov [cs:tCount], dx
call clrscr
mov byte [cs:location], 0
call printStars
mov word [cs:tCount], 0
EOI: mov al, 0x20
out 0x20, al
exit: popa
iret
delay:
push ax
push bx
push cx
push dx
mov ax,10
lo2:
mov cx,0xffff
cmp ax,0
jz exit1
sub ax,1
lo1:
cmp cx,0
jz lo2
sub cx,1
jmp lo1
exit1:
pop dx
pop cx
pop bx
pop ax
ret
length:
push bx
push cx
push dx
push ds ;data segment mov in es
pop es
mov cx,0xffff
mov al,0
repne scasb
mov ax,0xffff
sub ax,cx ;ax has string length
pop dx
pop cx
pop bx
ret
print:
push ax
push bx
push cx
push dx
mov cx,ax
mov ax,0xb800
push ax
pop es
mov ah,0x0f
next1:
stosw
lodsb
loop next1
pop dx
pop cx
pop bx
pop ax
ret
movement:
push ds
push es
pop ds
rep movsw
pop ds
ret
clrsr:
push di
push cx
push ax
push bx
push ax
push dx
mov bx,0xb800
mov es,bx
mov di,0
mov cx,2000
mov ax,0x0720
rep stosw
pop dx
pop ax
pop bx
pop ax
pop cx
pop di
ret
;Keyboard ISR
kbisr: push ax
in al, 0x60
shl al, 1
jnc EOI1
inc word [cs:tCount] ;If a key is released, only then increase the count
EOI1: mov al, 0x20
out 0x20, al
pop ax
iret
start: mov ax, 0
mov es, ax
mov bx, 0
call clrscr
;Hooking the interrupts
cli
mov word [es: 9*4], kbisr
mov [es:9*4+2], cs
mov word [es:8*4], CTS
mov [es:8*4+2], cs
sti
;Code for making it TSR
mov dx, start ;End of resident portion
add dx, 15 ;round up to next
para:
mov cl, 4
shr dx, cl ;number of paras
end: mov ax, 0x3100 ;terminate and stay resident
int 21h