[org 0x0100]
    
   jmp start
 
comparison:
 
loop1:
  div bx
  cmp cx , dx
  ja subtraction
  mov cx , dx
  jmp loop1

subtraction:
  sub cx , 2
  ret


start:
 mov ax ,0x5617
 mov bx , 16
 mov cx , 0
 call comparison
 mov ax , 0x4c00
 int 0x21
