[org 0x100]

start:
  mov ax, 0101011000010111b
  mov di, 1111000011110000b
  and di, ax
  shr di,4
  mov si, 0000111100001111b
  and si, ax
  shl si,4
  or di,si

end:
mov ax, 0x4c00
int 0x21