[org 0x100]

start:
mov ax, 0101011000010111b
mov di, 1010101010101010b
and di, ax
shr di,1
mov si, 0101010101010101b
and si, ax
shl si,1
or di,si

end:
mov ax, 0x4c00
int 0x21