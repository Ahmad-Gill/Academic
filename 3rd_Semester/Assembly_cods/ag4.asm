[org 0x0100]

mov bx,0101011000010111b
mov dx,bx
or dx,bx

xor bx,0x1BCD

and bx,dx
mov word[f],bx
mov bx,[f]

mov ax,0x4c00
int 0x21

f: dw 0