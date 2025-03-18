[org 0x0100]

jmp start
m1: db 'Name: Muhammad Ahmad', 0
m2: db 'Institute: Fast School of Computing', 0
m3: db 'Batch: BDS-2021', 0
m4: db 'Roll No: 5617', 0
m5: db 'Email: l215617@lhr.nu.edu.pk', 0
m6: db 'Address: Lahore, Pakistan', 0
m7: db 'Features: HardWorking, Honest, Punctual', 0

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
clrscr:
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
    mov di, ax
    mov si, [bp+4]
    mov ah, [bp+6]

    cld

nextchar:
    lodsb
    stosw
    loop nextchar

exit:
    pop di
    pop si
    pop cx
    pop ax
    pop es
    pop bp
    ret 8

scrollup: 
    push bp
    mov bp,sp
    push ax
    push cx
    push si
    push di
    push es
    push ds
    mov ax, 80 
    mul byte [bp+4] 
    mov si, ax 
    push si 
    shl si, 1 
    mov cx, 2000 
    sub cx, ax 
    mov ax, 0xb800
    mov es, ax 
    mov ds, ax 
    xor di, di 
    cld
    rep movsw
    mov ax, 0x0720 
    pop cx 
    rep stosw 
    pop ds
    pop es
    pop di
    pop si
    pop cx
    pop ax
    pop bp
    ret 2

start:
    call clrscr

    mov ax, 20
    push ax
    mov ax, 15
    push ax
    mov ax, 7
    push ax
    mov ax, m1
    push ax

    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 16
    push ax
    mov ax, 7
    push ax
    mov ax, m2
    push ax

    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 17
    push ax
    mov ax, 7
    push ax
    mov ax, m3
    push ax

    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 18
    push ax
    mov ax, 7
    push ax
    mov ax, m4
    push ax
    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 19
    push ax
    mov ax, 7
    push ax
    mov ax, m5
    push ax

    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 20
    push ax
    mov ax, 7
    push ax
    mov ax, m6
    push ax

    call printstr
    call delay

    mov ax, 20
    push ax
    mov ax, 21
    push ax
    mov ax, 7
    push ax
    mov ax, m7
    push ax

    call printstr
    call delay

mov ax, 5
    push ax
    call scrollup
mov ax, 0x4c00
int 0x21




