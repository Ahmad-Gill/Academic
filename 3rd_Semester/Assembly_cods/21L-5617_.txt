
[org 0x0100]
jmp main
oldisr: dd 0
buffer: times 2000 dw 0
clrscr:
push es
push ax
push di
mov ax, 0xb800
mov es, ax
mov di, 0
nextchar:
mov word [es:di], 0x720
add di, 2
cmp di, 4000
jne nextchar
pop di
pop ax
pop es
ret

delay:
push cx
push di
mov cx, 0xFF
delay1:
mov di, 0xFFF
delay2:
dec di
jnz delay2
loop delay1
pop di
pop cx
ret
store_buffer:
push bp
mov bp, sp
push ax
push cx
push si
push di
push es
push ds
mov ax, 0xb800
mov ds, ax
mov si, 0
mov ax, cs
mov es, ax
mov di, buffer
mov cx, 2000
cld
rep movsw
pop ds
pop es
pop di
pop si
pop cx
pop ax
pop bp
ret
load_buffer:
push bp
mov bp, sp
push ax
push cx
push si
push di
push es
push ds
mov ax, 0xb800

mov es, ax
mov di, 0
mov ax, cs
mov ds, ax
mov si, buffer
mov cx, 2000
cld
rep movsw
pop ds
pop es
pop di
pop si
pop cx
pop ax
pop bp
ret
kbISR:
push ax
in al, 0x60
cmp al, 00011101b
JNE nextCmp
CALL store_buffer
CALL clrscr
jmp exit
nextCmp:
cmp al, 10011101b
JNE noMatch
CALL delay
CALL load_buffer
jmp exit
noMatch:
pop ax
jmp far [cs:oldisr]
exit:
mov al, 0x20
out 0x20, al
pop ax
iret

main:
xor ax, ax
mov es, ax
mov ax, [es:9*4]
mov [oldisr], ax
mov ax, [es:9*4+2]
mov [oldisr+2], ax

cli
mov word [es:9*4], kbISR
mov [es:9*4+2], cs
sti
mov dx, main
add dx, 15
mov cl, 4
shr dx, cl
mov ax, 0x3100
INT 0x21
