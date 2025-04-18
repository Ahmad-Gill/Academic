[org 0x0100]
jmp start
; coordinates of a circle of radius 24
x24: dw 48,47,44,40,36,30,24,17,12,7,3,0,0,0,3,7,11,17,23,30,36,40,44,47,48
y24: dw 24,30,36,40,44,47,48,47,44,40,36,30,24,17,11,7,3,0,0,0,3,7,11,17,23
; coordinates of a circle of radius 45
x45: dw 90,89,88,86,83,79,75,70,64,58,52,46,40,34,28,22,17,12,8,5,2,0,0,0,0,2,5,8,12,17,22,28,34,40,46,52,58,64,70,75,79,83,86,88,89,90
y45: dw 45,51,57,63,68,73,78,82,85,87,89,89,89,88,86,83,80,76,71,66,60,54,48,41,35,29,23,18,13,9,6,3,1,0,0,0,24,7,11,16,21,26,32,38,44
; coordinates of a circle of radius 72
x72: dw 144,143,142,141,139,137,134,130,127,122,118,113,108,102,96,90,84,78,72,65,59,53,47,41,36,30,25,21,16,13,9,6,4,2,1,0,0,0,1,2,4,6,9,13,16,21,25,30,35,41,47,53,59,65,71,78,84,90,96,102,108,113,118,122,127,130,134,137,139,141,142,143,144
y72: dw 72,78,84,90,96,102,108,113,118,122,127,130,134,137,139,141,142,143,144,143,142,141,139,137,134,130,127,122,118,113,108,102,96,90,84,78,72,65,59,53,47,41,35,30,25,21,16,13,9,6,4,2,1,0,0,0,1,2,4,6,9,13,16,21,25,30,35,41,47,53,59,65,71
; coordinates of a circle of radius 120
x120: dw 240,239,239,238,237,235,234,232,229,226,223,220,217,213,209,204,200,195,190,185,180,174,168,163,157,151,144,138,132,126,120,113,107,101,95,88,82,76,71,65,60,54,49,44,39,35,30,26,22,19,16,13,10,7,5,4,2,1,0,0,0,0,0,1,2,4,5,7,10,13,16,19,22,26,30,35,39,44,49,54,59,65,71,76,82,88,95,101,107,113,119,126,132,138,144,151,157,163,168,174,180,185,190,195,200,204,209,213,217,220,223,226,229,232,234,235,237,238,239,239,240
y120: dw 120,126,132,138,144,151,157,163,168,174,180,185,190,195,200,204,209,213,217,220,223,226,229,232,234,235,237,238,239,239,240,239,239,238,237,235,234,232,229,226,223,220,217,213,209,204,200,195,190,185,180,174,168,163,157,151,144,138,132,126,120,113,107,101,95,88,82,76,71,65,59,54,49,44,39,35,30,26,22,19,16,13,10,7,5,4,2,1,0,0,0,0,0,1,2,4,5,7,10,13,16,19,22,26,30,35,39,44,49,54,59,65,71,76,82,88,95,101,107,113,119
w1 equ 50
x1 equ 200
x2 equ 35
y1 equ 100
c1 equ 100
x3 equ 40
x4 equ 635
y2 equ 49
y3 equ 60
x5 equ 30
x6 equ 125
x7 equ 110
x8 equ 1800
x9 equ 1785
w equ 50
x equ 50
y equ 170
c equ 70

ww equ 50
xx equ 50
yy equ 165
cc equ 70

x24x: dw 48,47,44,40,36,30,24,17,12,7,3,0,0,0,3,7,11,17,23,30,36,40,44,47,48
y24x: dw 24,30,36,40,44,47,48,47,44,40,36,30,24,17,11,7,3,0,0,0,3,7,11,17,23
x24x1: dw 48,47,44,40,36,30,24,17,12,7,3,0,0,0,3,7,11,17,23,30,36,40,44,47,48
y24x1: dw 24,30,36,40,44,47,48,47,44,40,36,30,24,17,11,7,3,0,0,0,3,7,11,17,23

x24x2: dw 48,47,44,40,36,30,24,17,12,7,3,0,0,0,3,7,11,17,23,30,36,40,44,47,48
y24x2: dw 24,30,36,40,44,47,48,47,44,40,36,30,24,17,11,7,3,0,0,0,3,7,11,17,23

x24x3: dw 48,47,44,40,36,30,24,17,12,7,3,0,0,0,3,7,11,17,23,30,36,40,44,47,48
y24x3: dw 24,30,36,40,44,47,48,47,44,40,36,30,24,17,11,7,3,0,0,0,3,7,11,17,23


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
; setting up the parameters
counter : db 0;
counter1 : db 0;
counter2 : db 0;
counter3 : db 0;
counter4 : db 0;
radius : equ 24 ; choose radius (24, 45, 72, 120)
xoffset: equ 100 ; change to move circle along x axis
yoffset: equ 100 ; change to move circle along y axis

radius1 : equ 24 ; choose radius (24, 45, 72, 120)

xoffset1: equ 120 ; change to move circle along x axis
yoffset1: equ 120 ; change to move circle along y axis

radius4 : equ 24 ; choose radius (24, 45, 72, 120)

xoffset4: equ 1200 ; change to move circle along x axis
yoffset4: equ 20 ; change to move circle along y axis


radius2 : equ 24 ; choose radius (24, 45, 72, 120)

xoffset2: equ 70; change to move circle along x axis
yoffset2: equ 120 ; change to move circle along y

radius3 : equ 24 ; choose radius (24, 45, 72, 120)
xoffset3: equ 30 ; change to move circle along x axis
yoffset3: equ 270 ; change to move circle along y axis

circle:
;circle1
mov si, x24 ; change x array as radius
mov di, y24 ; change y array as radius
mov ax, 0x0010 ; set 640 x 350 graphics mode
int 0x10 ; bios video services
mov ax, 0x0C07 ; put pixel in white color
xor bx, bx ; page number 0
mov cx, [si] ; first x position
add cx, xoffset ; moving point along x axis
mov dx, [di] ; first y position
add dx, yoffset ; moving point along y axis
l1:
int 0x10 ; bios video services
add si, 2 ; next location address
add di, 2 ; next location address
mov cx, [si]
add cx, xoffset
mov dx, [di]
add dx, yoffset
inc byte[counter]
cmp byte[counter], radius ; stopping condition
jle l1 ; jump if less
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services

;circle2
mov si, x24x ; change x array as radius
mov di, y24x ; change y array as radius
mov ax, 0x0010 ; set 640 x 350 graphics mode
mov ax, 0x0C07 ; put pixel in white color
xor bx, bx ; page number 0
mov cx, [si] ; first x position
add cx, xoffset1 ; moving point along x axis
mov dx, [di] ; first y position
add dx, yoffset1 ; moving point along y axis
l2:
int 0x10 ; bios video services
add si, 2 ; next location address
add di, 2 ; next location address
mov cx, [si]
add cx, xoffset1
mov dx, [di]
add dx, yoffset1
inc byte[counter1]
cmp byte[counter1], radius1 ; stopping condition
jbe l2 ; jump if less
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services
;circle3
mov si, x24x1 ; change x array as radius
mov di, y24x1 ; change y array as radius
mov ax, 0x0010 ; set 640 x 350 graphics mode
mov ax, 0x0C07 ; put pixel in white color
xor bx, bx ; page number 0
mov cx, [si] ; first x position
add cx, xoffset2 ; moving point along x axis
mov dx, [di] ; first y position
add dx, yoffset2 ; moving point along y axis
l3:
int 0x10 ; bios video services
add si, 2 ; next location address
add di, 2 ; next location address
mov cx, [si]
add cx, xoffset2
mov dx, [di]
add dx, yoffset2
inc byte[counter2]
cmp byte[counter2], radius2 ; stopping condition
jbe l3 ; jump if less
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services

circle4:

mov si, x24x2 ; change x array as radius
mov di, y24x2 ; change y array as radius
mov ax, 0x0010 ; set 640 x 350 graphics mode
mov ax, 0x0C07 ; put pixel in white color
xor bx, bx ; page number 0
mov cx, [si] ; first x position
add cx, xoffset3 ; moving point along x axis
mov dx, [di] ; first y position
add dx, yoffset3 ; moving point along y axis
l4:
int 0x10 ; bios video services
add si, 2 ; next location address
add di, 2 ; next location address
mov cx, [si]
add cx, xoffset3
mov dx, [di]
add dx, yoffset3
inc byte[counter3]
cmp byte[counter3], radius3 ; stopping condition
jbe l4 ; jump if less
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services
; circle 5

;circle5
mov si, x24x3 ; change x array as radius
mov di, y24x3 ; change y array as radius
;mov ax, 0x0010 ; set 640 x 350 graphics mode
int 0x10 ; bios video services
mov ax, 0x0C07 ; put pixel in white color
xor bx, bx ; page number 0
mov cx, [si] ; first x position
add cx, xoffset4 ; moving point along x axis
mov dx, [di] ; first y position
add dx, yoffset4 ; moving point along y axis
a1:
int 0x10 ; bios video services
add si, 2 ; next location address
add di, 2 ; next location address
mov cx, [si]
add cx, xoffset4
mov dx, [di]
add dx, yoffset4
inc byte[counter4]
cmp byte[counter4], radius4 ; stopping condition
jle a1 ; jump if less
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services



mov cx,x6
mov dx, y3+c1
mov al, c1
loo:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x3+w1+y1+x3
jbe loo

mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services


mov cx,x8
mov dx, y3+c1
mov al, c1
l:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x3+w1+y1+x3
jbe l

mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services



mov cx,x9
mov dx, y3+c1
mov al, c1
a:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x3+w1+y1+x3
jbe a

mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services



mov cx,x7
mov dx, y3+c1
mov al, c1
lo:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x3+w1+y1+x3
jbe lo

mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services

mov cx,x1-x1

mov dx, y1+y1
mov al, c1
loop1:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x1+w1+y1
jbe loop1



mov cx,x1+x1+x1+x2
mov dx, y1+y1
mov al, c1+c1
loop2:
int 0x10 ; bios video services
inc dx
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc dx
cmp dx, x1+w1+y1
jbe loop2






mov cx,x3-x3
mov dx, y1+y1
mov al, c1
loop3:
int 0x10 ; bios video services
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc cx
cmp cx,x4
jbe loop3



mov cx,x3-x3
mov dx, y1+y1+y1+y2
mov al, c1
loop4:
int 0x10 ; bios video services
mov ax, 0x0C07 ; put pixel in white color
int 10h
inc cx
cmp cx,x4
jbe loop4
mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services

mov ax, 0x0010 ; set 640 x 350 graphics mode
mov cx, y+y+y
mov dx, x+x
mov al, c
loo3:
inc dx
mov ah, 0ch
int 10h
dec cx
cmp cx, c+w+x+y+c+x5
jne loo3
mov ah,0
int 16h
mov cx, y+y+y
mov dx, x+x
mov al, c
loo4:
inc dx
mov ah, 0ch
int 10h
inc cx
cmp cx, c+c+w+x+y+y
jbe loo4




mov ax, 0x0010 ; set 640 x 350 graphics mode
mov cx, yy+yy+yy
mov dx, xx+xx
mov al, cc
lo3:
inc dx
mov ah, 0ch
int 10h
dec cx
cmp cx, cc+ww+xx+yy+cc
jne lo3
mov ah,0
int 16h
mov cx, yy+yy+yy
mov dx, xx+xx
mov al, cc
lo4:
inc dx
mov ah, 0ch
int 10h
inc cx
cmp cx, cc+cc+ww+xx+yy+yy
jbe lo4

mov ah, 0 ; service 0 – get keystroke
int 0x16 ; bios keyboard services



mov ax, 0x0003 ; 80x25 text mode
int 0x10 ; bios video services


ret

start:
call circle
;call rectangle
mov ax, 0x4c00 ; terminate program
int 0x21