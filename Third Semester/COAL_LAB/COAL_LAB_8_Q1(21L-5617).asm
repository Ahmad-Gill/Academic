[org 0x0100]

jmp start


delay:
        push cx
        mov cx, 150

    delay1:
        push cx
        mov cx, 0xFFFF

    delay2:
        loop delay2
        pop cx
        loop delay1
        pop cx  
    ret

start:
   call delay
	mov ax , 0x4c00
	int 0x21



