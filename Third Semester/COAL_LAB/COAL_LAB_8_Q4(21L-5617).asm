[org 0x0100]

	jmp start

clrscr:
	push es
	push ax
	push di

	mov ax , 0xb800
	mov es , ax
	mov di , 0
 
 nextloc:
	mov word [es:di] , 0x0720
	add di , 2
	cmp di , 4000
	jne nextloc

	pop di
	pop ax
	pop es
	ret

printstr:
	push bp
	mov bp , sp
	push es
	push ax
	push si 
	push di
	push cx

	mov ax , 0xb800
	mov es , ax
	mov di , 0
	mov ah , 0x40
	mov si , [bp + 4]
	mov cx , 40
row1:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop row1

	mov di,80
	mov ah , 0x20
	mov cx , 40
 ro11:
	mov [es:di] , ax
	add di , 2
	loop ro11



row2:
	mov di , 160
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l1:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l1
     mov di,240
	mov ah , 0x20
	mov cx , 40
 ro12:
	mov [es:di] , ax
	add di , 2
	loop ro12


row3:
	mov di , 320
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l2:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l2
mov di,400
	mov ah , 0x20
	mov cx , 40
 ro13:
	mov [es:di] , ax
	add di , 2
	loop ro13

row4:
	mov di , 480
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l3:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l3

mov di , 560
	mov ah , 0x20
	mov cx , 40
 ro14:
	mov [es:di] , ax
	add di , 2
	loop ro14

row5:
	mov di , 640
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l4:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l4

mov di,720
	mov ah , 0x20
	mov cx , 40
 ro15:
	mov [es:di] , ax
	add di , 2
	loop ro15

row6:
	mov di , 800
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l5:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l5

mov di,880
	mov ah , 0x20
	mov cx , 40
 ro16:
	mov [es:di] , ax
	add di , 2
	loop ro16

row7:
	mov di , 960
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l6:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l6
mov di,1040
	mov ah , 0x20
	mov cx , 40
 ro17:
	mov [es:di] , ax
	add di , 2
	loop ro17

row8:
	mov di , 1120
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l7:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l7
mov di,1200
	mov ah , 0x20
	mov cx , 40
 ro18:
	mov [es:di] , ax
	add di , 2
	loop ro18

row9:
	mov di , 1280
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l8:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l8

mov di,1360
	mov ah , 0x20
	mov cx , 40
 ro19:
	mov [es:di] , ax
	add di , 2
	loop ro19

row10:
	mov di , 1440
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l9:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l9
mov di,1520
	mov ah , 0x20
	mov cx , 40
 ro20:
	mov [es:di] , ax
	add di , 2
	loop ro20

row11:
	mov di , 1600
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l10:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l10
mov di,1680
	mov ah , 0x20
	mov cx , 40
 ro21:
	mov [es:di] , ax
	add di , 2
	loop ro21

row12:
	mov di , 1760
	mov ah , 0x40
	mov si ,[bp+4]
	mov cx , 40
	mov dx , 0
  l11:
	mov [es:di] , ax
	mov ah , 0x40
	add di , 2
	loop l11

mov di,1840
	mov ah , 0x20
	mov cx , 40
 ro22:
	mov [es:di] , ax
	add di , 2
	loop ro22

popp:	
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 4
start:
      call clrscr
	mov ax , 0x20
	push ax
	call printstr
	mov ax , 0x4c00
	int 0x21