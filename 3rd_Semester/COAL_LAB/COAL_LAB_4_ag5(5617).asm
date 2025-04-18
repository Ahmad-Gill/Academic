[org 0x0100]
jmp start
m_cand: dd 5617
m_lier: dw 5617 
r: dd 0 
addd: dd 0

start: 
       mov cl, 16  
       mov dx, [m_lier] 
checking: 
       shr dx, 1 
       jnc omit 
       mov ax, [m_cand]
       add [r], ax 
       mov ax, [m_cand+2]
       adc [r+2], ax 
omit:  
       shl word [m_cand], 1
       rcl word [m_cand+2], 1 
       dec cl 
       jnz checking
       mov ax, [r+2]
       mov bx, [r]
       mov [addd+2], ax
       mov [addd+0], bx
       
       mov ax, [r+2]
       add [addd+2], ax 
       mov bx, [r]
       adc [addd], bx
       
       mov di, [addd+2]  
       mov si, [addd]

mov ax, 0x4c00 
int 0x21