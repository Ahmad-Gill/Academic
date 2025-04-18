[org 0x100]

start:
  mov ax, 0101011000010111b
  mov di, 1100110011001100b
  and di, ax
  shr di,2
  mov si, 0011001100110011b
  and si, ax
  shl si,2
  or di,si

end:
mov ax, 0x4c00
int 0x21