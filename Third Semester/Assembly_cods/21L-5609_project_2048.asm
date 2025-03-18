[org 0x0100]

jmp start

row1: dw 0 , 0 , 0 , 2
row2: dw 0 , 0 , 0 , 0
row3: dw 0 , 0 , 0 , 0
row4: dw 0 , 0 , 0 , 0
row1_l: dw 496
row2_l: dw 976
row3_l: dw 1456
row4_l: dw 1936
line: dw 2036
m1:db '<< 2 0 4 8 >>'
m2 :db 'BY:'
m3:db 'NIMRA AMER'
message4:db 'PRESS ANY KEY TO CONTINUE'
m4:db 'GAME___OVER :('
counter:dw 0
win_condition: dw 32
loose_condotion_counter: dw 20
extra: dw 0





Game_lost:
call clrscr
mov word [extra],1
call lost_message

call boundary

mov ax,0xb800
mov es,ax


robot_hrad:
mov di,492
mov cx,10
sd:
mov word[es:di] , 0x3020
add di,2
loop sd

mov di,492
mov cx,5
sdd:
mov word[es:di] , 0x3020
add di,160
loop sdd

mov di,512
mov cx,5
sf:
mov word[es:di] , 0x3020
add di,160
loop sf


mov di,1292
mov cx,11
sw:
mov word[es:di] , 0x3020
add di,2
loop sw


mov di,818
mov word[es:di],0x0a30

mov di,826
mov word[es:di],0x0a30
mov di,982

mov word[es:di],0x045e
mov cx,3
mov di,1140
k:
mov word[es:di],0x8576
add di,2
loop k
call delay
call delay
call clrscr
call boundary

call lost_message
head2_:

mov di,2170
mov cx,5
dd_:
mov word[es:di] , 0x3020
add di,164
loop dd_


mov di,2172
mov cx,5
ddd:
mov word[es:di] , 0x3020
add di,164
loop ddd


mov di,2170
mov cx,5
aa:
mov word[es:di] , 0x3020
add di,156
loop aa

mov di,2172
mov cx,5
ddb:
mov word[es:di] , 0x3020
add di,156
loop ddb

mov di,2988
mov cx,5
dv:
mov word[es:di] , 0x3020
add di,156
loop dv

mov di,2986
mov cx,5
dvv:
mov word[es:di] , 0x3020
add di,156
loop dvv


mov di,2950
mov cx,5
aaa_:
mov word[es:di] , 0x3020
add di,164
loop aaa_


mov di,2952
mov cx,5
aaaa:
mov word[es:di] , 0x3020
add di,164
loop aaaa


mov di,2650
mov word[es:di],0x0a30


mov di,2818
mov word[es:di],0x0a30


mov di,2970
mov word[es:di],0x043e


mov di,2964
mov word[es:di],0x057c
mov di,3124
mov word[es:di],0x057c

call delay
call delay
call clrscr
call boundary

head3_:
call lost_message


mov di,2520
mov cx,11
sds:
mov word[es:di] , 0x3020
add di,2
loop sds

mov di,2520
mov cx,6
sdds:
mov word[es:di] , 0x3020
add di,160
loop sdds

mov di,2542
mov cx,6
sfs:
mov word[es:di] , 0x3020
add di,160
loop sfs


mov di,3322
mov cx,11
sws:
mov word[es:di] , 0x3020
add di,2
loop sws


mov di,2858
mov word[es:di],0x0a30

mov di,3178
mov word[es:di],0x0a30
mov di,3014

mov word[es:di],0x043e
mov cx,1
mov di,3008
kk:
mov word[es:di],0x057c
add di,160
loop kk


ret



lost_message:


mov ax, 0xb800
        mov es, ax ; point es to video base
        mov di, 1332 ;point di to top left column
        mov si, m4 ; point si to string
        mov cx, 14 ; load length of string in cx
        mov ah, 0x8b ; normal attribute fixed in al
        x:
        mov al, [si] ; load next char of string
        mov [es:di], ax ; show this char on screen
        add di, 2 ; move to next screen location
        add si, 1 ; move to next char in string
        loop x ; repeat the operation cx times

ret




game_win:
call clrscr
mov word [extra],1
call boundary

mov ax,0xb800
mov es,ax


make_w:
mov di,662
mov cx,6
c:
mov word[es:di] , 0x3020
add di,160
loop c

call delay
mov di,1622
mov cx,5
cc:
mov word[es:di] , 0x3020
sub di,158
loop cc
mov di,1624
mov cx,5
ccc:
mov word[es:di] , 0x3020
sub di,158
loop ccc
call delay


mov di,834
mov cx,6
zz:
mov word[es:di] , 0x3020
add di,162
loop zz
mov di,832
mov cx,6
zzz:
mov word[es:di] , 0x3020
add di,162
loop zzz
call delay
mov di,684
mov cx,6
bb:
mov word[es:di] , 0x3020
add di,160
loop bb
call delay
;end 0f_w




make_i:

mov di,704
mov word[es:di] , 0x3020

mov di,1024
mov cx,5
vv:
mov word[es:di] , 0x3020
add di,160
loop vv
call delay
;end of i

make_n:

mov di,730
mov cx,7
vvm:
mov word[es:di] , 0x3020
add di,160
loop vvm
call delay
mov di,730
mov cx,7
vvmn:
mov word[es:di] , 0x3020
add di,162
loop vvmn

mov di,732
mov cx,7
vvmnx:
mov word[es:di] , 0x3020
add di,162
loop vvmnx

call delay

mov di,746
mov cx,7
nm:
mov word[es:di] , 0x3020
add di,160
loop nm
call delay
;end of n

mov cx, 50
mov di,1774
ui:
mov word[es:di] , 0x3020

add di,2
loop ui

mov cx, 50
mov di,1934
uiq:
mov word[es:di] , 0x3020

add di,2
loop uiq



robotics:






mov di,2450
mov cx,11
sdsw:
mov word[es:di] , 0x3020
add di,2
loop sdsw

mov di,2450
mov cx,6
sddsw:
mov word[es:di] , 0x3020
add di,160
loop sddsw

mov di,2472
mov cx,6
sfsw:
mov word[es:di] , 0x3020
add di,160
loop sfsw


mov di,3252
mov cx,11
swsw:
mov word[es:di] , 0x3020
add di,2
loop swsw


mov di,2776
mov word[es:di],0x0a30

mov di,2784
mov word[es:di],0x0a30
mov di,2940

mov word[es:di],0x043e
mov cx,1
mov di,3100
kkw:
mov word[es:di],0x857e
add di,160
loop kkw




;;;;;;;;;;;;;;
mov di,2930
mov cx,8
sdgw:
mov word[es:di] , 0x3020
sub di,2
loop sdgw




mov di,2916
mov cx,3
sdgwy:
mov word[es:di] , 0x3020
sub di,160
loop sdgwy



mov di,2436
mov cx,3
sdgwt:
mov word[es:di] , 0x3020
sub di,2
loop sdgwt

mov di,2274
mov word[es:di] , 0xb55e


mov di,2952
mov cx,8
sfswf:
mov word[es:di] , 0x3020
add di,2
loop sfswf


mov di,2966
mov cx,3
sfswr:
mov word[es:di] , 0x3020
sub di,160
loop sfswr


mov di,2486
mov cx,3
sfsl:
mov word[es:di] , 0x3020
add di,2
loop sfsl



mov di,2328
mov word[es:di] , 0xb55e

ret




check_win:

mov ax,[loose_condotion_counter]
cmp word[counter],ax
jz lo__
jnz loo
lo__:
jmp looos
loo:
add word[counter],1
mov ax,0xb800
mov es,ax
xor bx,bx
mov cx,4
popp:

cmp cx,4
jz check_first_row
cmp cx,3
jz check_second_row
cmp cx,2
jz check_third_row
cmp cx,1
jz check_forth_row


check_forth_row:
xor bx,bx
hellll:
mov ax,[row4+bx]
cmp ax,[win_condition]
jae win
add bx,2
cmp bx,8
jb helll;

jmp again




 check_third_row:
xor bx,bx
helll:
mov ax,[row3+bx]
cmp ax,[win_condition]
jae win
add bx,2
cmp bx,8
jb hell;

jmp again

check_second_row:
xor bx,bx
hell:
mov ax,[row2+bx]
cmp ax,[win_condition]
jae win
add bx,2
cmp bx,8
jb hell

jmp again
check_first_row:
xor bx,bx
hel:
mov ax,[row1+bx]
cmp ax,[win_condition]
jae win
add bx,2
cmp bx,8
jb hel
jmp again

 again:
loop popp

jmp bye

win:
call game_win
jmp bye

looos:
call Game_lost
jmp bye


bye:
ret



GenRan_right:
        cmp word [row1] , 0
        jz storage

        cmp word [row2] , 0
        jz _storage_

        cmp word [row3] , 0
        jz storage__

        cmp word [row4] , 0
        jz _storage

        ret

storage:
        mov word [row1] , 2
        call print
        ret

_storage_:
        mov word [row2] , 2
        call print
        ret

storage__:
        mov word [row3] , 2
        call print
        ret

_storage:
        mov word [row4] , 2
        call print
        ret

GenRan_left:

        cmp word [row1+3] , 0
        jz Storage

        cmp word [row2+3] , 0
        jz _Storage_

        cmp word [row3+3] , 0
        jz Storage__

        cmp word [row4+3] , 0
        jz _Storage

        ret

Storage:
        mov word [row1] , 2
        call print
        ret

_Storage_:
        mov word [row2] , 2
        call print
        ret

Storage__:
        mov word [row3] , 2
        call print
        ret

_Storage:
        mov word [row4] , 2
        call print
        ret

GenRan_up:

        cmp word [row1] , 0
        jz _8storage

        cmp word [row1+2] , 0
        jz _8_storage_

        cmp word [row1+4] , 0
        jz storage__8

        cmp word [row1+6] , 0
        jz _storage

        ret

_8storage:
        mov word [row1] , 2
        call print
        ret

_8_storage_:
        mov word [row1+2] , 2
        call print
        ret

storage__8:
        mov word [row1+4] , 2
        call print
        ret
_storage__:
        mov word [row1+6] , 2
        call print
        ret

GenRan_down:

        cmp word [row1] , 0
        jz storage___

        cmp word [row2] , 0
        jz _storage_____

        cmp word [row3] , 0
        jz ___storage___

        cmp word [row4] , 0
        jz _storage___

        ret

storage___:
        mov word [row4+0] , 2
        call print
        ret

_storage_____:
        mov word [row4+2] , 2
        call print
        ret

___storage___:
        mov word [row4+4] , 2
        call print
        ret

_storage___:
        mov word [row4+6] , 2
        call print
        ret

printnum:
        push bp
        mov bp, sp
        push es
        push ax
        push bx
        push cx
        push dx
        push di
        mov ax, 0xb800
        mov es, ax
        mov ax, [bp+6]
        mov bx, 10
        mov cx, 0
nextdigit:
         mov dx, 0
        div bx
        add dl, 0x30
        push dx
        inc cx
        cmp ax, 0
        jnz nextdigit
        mov di, [bp+4]
        nextpos:
          pop dx
        mov dh, 0x07
        mov [es:di], dx
        add di, 2 
        loop nextpos
        pop di
        pop dx
        pop cx
        pop bx
        pop ax
        pop es
        pop bp
        ret 4

delay:
        mov ax,10
oloop:
        mov cx, 0xFFFF
        sub ax,1
        cmp ax,0

        je return
iloop:

        sub cx,1
        cmp cx,1
        jne iloop
        jmp oloop


return:
        ret


main_window:
call boundary
mov ax,0xb800
mov es,ax

mov cx,14
mov di,650
w1:
mov word[es:di] , 0x3020
add di,2
loop w1


call delay
mov cx,4
mov di,838
w2:
mov word[es:di] , 0x3020
add  di,160
loop w2

call delay
mov cx,13
mov di,1476
w3:
mov word[es:di] , 0x3020
sub di,2
loop w3
call delay
mov cx,4
mov di,1610
w4:
mov word[es:di] , 0x3020
add  di,160
loop w4
call delay

mov cx,14
mov di,2252
w5:
mov word[es:di] , 0x3020
add  di,2
loop w5
call delay


mov cx,9
mov di,850
w7:
mov word[es:di] , 0x3020
add  di,160
loop w7

call delay

mov cx,9
mov di,872
w771:
mov word[es:di] , 0x3020
add  di,160
loop w771
call delay
mov cx,10
mov di,692
w712:
mov word[es:di] , 0x3020
add  di,2
loop w712
call delay

mov cx,10
mov di,2292
w713:
mov word[es:di] , 0x3020
add  di,2
loop w713
call delay


mov cx,13
mov di,1544
ww3:
mov word[es:di] , 0x3020
sub di,2
loop ww3
call delay

mov cx,5
mov di,746
ww33:
mov word[es:di] , 0x3020
add di,160
loop ww33
call delay

mov cx,5
mov di,1706
ww31:
mov word[es:di] , 0x3020
add di,160
loop ww31
call delay
mov cx,5
mov di,1358
ww32:
mov word[es:di] , 0x3020
sub di,160
loop ww32

call delay


;make 8

mov cx,13
mov di,1580
ww312:
mov word[es:di] , 0x3020
sub di,2
loop ww312
call delay
mov cx,4
mov di,1422
ww321:
mov word[es:di] , 0x3020
sub di,160
loop ww321

call delay

mov cx,4
mov di,914
ww331:
mov word[es:di] , 0x3020
add di,160
loop ww331
call delay
mov cx,13
mov di,780
ww3121:
mov word[es:di] , 0x3020
sub di,2
loop ww3121

call delay
mov cx,4
mov di,1714
ww3312:
mov word[es:di] , 0x3020
add di,160
loop ww3312

call delay
mov cx,4
mov di,1742
ww3x:
mov word[es:di] , 0x3020
add di,160
loop ww3x

call delay

mov cx,13
mov di,2380
wwx:
mov word[es:di] , 0x3020
sub di,2
loop wwx
call delay




;print

mov ax, 0xb800
        mov es, ax ; point es to video base
        mov di, 3250 ;point di to top left column
        mov si, message4 ; point si to string
        mov cx, 25 ; load length of string in cx
        mov ah, 0x8b ; normal attribute fixed in al
        b:
        mov al, [si] ; load next char of string
        mov [es:di], ax ; show this char on screen
        add di, 2 ; move to next screen location
        add si, 1 ; move to next char in string
        loop b ; repeat the operation cx times
        call delay




ret

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


printMessage:

mov ax,0xb800
mov es,ax
mov si,0
mov cx,13
mov ah,0x07
mov di,546
m:

mov al,[m1+si]
mov [es:di],ax
add di,2
add si,1
loop m

mov si,0
mov cx,3
mov ah,0x07
mov di,706
mm:
mov al,[m2+si]
mov [es:di],ax
add di,2
add si,1
loop mm


mov si,0
mov cx,10
mov ah,0x07
mov di,872
mmm:
mov al,[m3+si]
mov [es:di],ax
add di,2
add si,1
loop mmm


mov di ,696
 mov word [es:di],0x873c
mov di ,698
mov word [es:di],0x073c

ret


boundary:

mov ax,0xb800
mov es,ax

mov cx,80
mov di,3680
pp:
mov word[es:di] , 0xa020
add di,2
loop pp
mov cx,80
mov di,3840
p:
mov word[es:di] , 0xa020
add di,2
loop p

mov cx,80
mov di,160
o:
mov word[es:di] , 0xa020
add di,160
loop o

mov cx,80
mov di,162

o0:
mov word[es:di] , 0xa020
add di,160
loop o0

mov cx,80
mov di,158

o0op:
mov word[es:di] , 0xa020
add di,160
loop o0op

mov cx,80
mov di,156

o0o:
mov word[es:di] , 0xa020
add di,160
loop o0o

mov cx,80
mov di,0

o0oo0:
mov word[es:di] , 0xa020
add di,2
loop o0oo0

mov cx,80
mov di,160

o0oo:
mov word[es:di] , 0xa020
add di,2
loop o0oo

ret

print:

mov cx , 4
xor si , si
mov word[row1_l],496

l2:

MOV ax,[row1+si]

push ax
mov ax,[row1_l]
push ax

call printnum
add si,2
add word[row1_l],10
loop l2


mov cx , 4

xor si , si
mov word[row2_l],976

l3:
MOV ax,[row2+si]

push ax
mov ax,[row2_l]
push ax

call printnum
add si,2
add word[row2_l],10

loop l3
mov cx , 4
xor si , si
mov word[row3_l],1456

l4:
MOV ax,[row3+si]

push ax
mov ax,[row3_l]
push ax

call printnum
add si,2
add word[row3_l],10
loop l4

mov cx , 4

xor si , si
mov word[row4_l],1936

l5:
MOV ax,[row4+si]

push ax
mov ax,[row4_l]
push ax

call printnum
add si,2
add word[row4_l],10
loop l5
ret

grid:


call boundary

mov ax , 0xb800
mov es , ax
mov ah , 0x07
mov di , 336
mov cx , 4
xor si , si
mov di , 496

mov cx , 21
mov di,332

top:
mov ah,0x30
mov al,0x20
;mov di,[location]
mov word[es:di] ,ax
mov ah , 0x30
add di , 2

loop top

mov di,1408
mov word[es:di],0x073c

mov di ,814
mov cx , 20

top_first:
mov [es:di] , ax
mov ah , 0x30
add di , 2

loop top_first

mov di , 1294
mov cx , 20

top_second:

mov [es:di] , ax
mov ah , 0x30
add di , 2
loop top_second

mov di , 1774
mov cx , 20

top_third:
mov [es:di] , ax
mov ah , 0x30
add di , 2
loop top_third

mov di , 2254
mov cx , 20

top_fourth:
mov [es:di] , ax
mov ah , 0x30
add di , 2

loop top_fourth

mov di , 332
mov cx , 13

right:
mov [es:di] , ax
mov ah , 0x30
add di , 160
loop right

mov di , 372
mov cx , 13

left:
mov [es:di] , ax
mov ah , 0x30
add di , 160
loop left

mov di , 332
mov cx , 10

vertical_1:
mov word[es:di] , 0x3020
add di , 160
loop vertical_1

mov di , 502
mov cx , 12

verticall_2:
mov word[es:di] , 0x3020
add di , 160
loop verticall_2

mov di , 512
mov cx , 11

vertical_3:
mov word[es:di] , 0x3020
mov ah , 0x40
add di , 160
loop vertical_3

mov di , 522
mov cx , 11

vertical_4:
mov word[es:di] , 0x3020
mov ah , 0x40
add di , 160
loop vertical_4

mov cx, 10
mov di,762
mov ah,0x60

head:
mov word[es:di] , 0x3020
add di,2
loop head
mov cx, 5
mov di,762

head1:
mov word[es:di] , 0x3020
add di,160
loop head1


mov cx, 10
mov di,1562

head2:
mov word[es:di] , 0x3020
add di,2
loop head2

mov cx, 6
mov di,782

head3:
mov word[es:di] , 0x3020
add di,160
loop head3

mov di,1088
mov word[es:di],0x8230

mov di,1096
mov word[es:di],0x8230

mov cx, 2
mov di,1572

head5:
mov word[es:di] , 0x3020
add di,160
loop head5

mov cx, 2
mov di,1570

head6:
mov word[es:di] , 0x3020
add di,160
loop head6


mov di,1252
mov word[es:di],0x0C5e
mov di,1410
mov word[es:di],0x8C2d
mov di,1412
mov word[es:di],0x0C2d
mov di,1414
mov word[es:di],0x0C2d



mov cx,18
mov di,1056

uq:
mov word[es:di] , 0x3020
sub di,2
loop uq

mov cx,4
mov di,1056

uqw:
mov word[es:di] , 0x3020
sub di,160
loop uqw



mov cx,5
mov di,380
w:
mov word[es:di] , 0x3020
add di,160
loop w


mov cx,18
mov di,416

uw:
mov word[es:di] , 0x3020
sub di,2
loop uw


mov cx,4
mov di,1380

u:
mov word[es:di] , 0x3020
sub di,2
loop u



mov cx, 4
mov di,2020

head22:
mov word[es:di] , 0x3020
sub  di,160
loop head22


mov cx, 4
mov di,1536

head33:
mov word[es:di] , 0x3020
sub  di,160
loop head33

mov cx, 8
mov di,2034

head223:
mov word[es:di] , 0x3020
sub  di,2
loop head223



mov cx, 18
mov di,1874

head7:
mov word[es:di] , 0x3020
add di,2
loop head7

mov cx, 19
mov di,3154

head8:
mov word[es:di] , 0x3020
add di,2
loop head8

mov cx, 8
mov di,1874

head77:
mov word[es:di] , 0x3020
add di,160
loop head77

mov cx, 8
mov di,1910

head777:
mov word[es:di] , 0x3020
add di,160
loop head777


colour:

mov cx, 17
mov bx,7
ll:
mov di,[line]
mov cx, 17
head9:
mov word[es:di] , 0x6020
add di,2
loop head9

add  word[line],160
dec bx
cmp bx,0
jnz ll

mov cx, 4
mov di,3340

head99:
mov word[es:di] , 0x3020
add di,160
loop head99

mov cx, 4
mov di,3324
head999:
mov word[es:di] , 0x3020
add di,160
loop head999

mov cx, 2
mov di,3964

head0:
mov word[es:di] , 0x0a3c
sub di,2
loop head0

mov cx, 2
mov di,3980

head00:
mov word[es:di] ,0x0a3e
add di,2
loop head00


ret


shifting_cols_right:

        mov bx , row1
        mov si , 0
row_1:

        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz addition_first_two

        jnz not_     ; when first two cells are not equal

not_:
        jmp not_equal


addition_first_two:    ;first two cells


        add ax , cx

addition_next:


        cmp dx , di ; comparing the next two elements
        jne storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz store__
        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx

        jmp printing


store__:

        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp printing


storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp printing


zero:

        cmp dx , 0
        jz zero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        jmp printing


zero_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp printing



next_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        jmp printing




not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  equality
        jnz not_equality


equality:
        jmp middle_equal

not_equality:

        cmp dx , di    ;last two cells are equal
        jnz no_sum

sum:

        add dx , di

        cmp dx , 0
        jz result_0

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp printing


result_0:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp printing

no_sum:
        cmp dx , 0
        jnz next_value

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp printing


next_value:

        cmp di , 0
        jnz next_value__

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp printing


next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp printing


middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz first_not_zero



first_zero:

        cmp di , 0
        jz both_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp printing


both_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        jmp printing



first_not_zero:

        cmp di , 0
        jnz both_not_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp printing


both_not_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp printing


middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz is_zero

      cmp di , 0  ;last element is zero
        jz is_zero_

bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp printing

is_zero:         
        cmp di , 0 ;last element
        jz bothzero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si], cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp printing

bothzero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp printing

is_zero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp printing



printing:
        call print



     mov bx , row2 ;second row (second array)
     mov si , 0

row_2:


        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz _2_addition_first_two

        jnz _2_not_     ; when first two cells are not equal

_2_not_:
        jmp _2_not_equal


_2_addition_first_two:    ;first two cells


        add ax , cx
        ;mov si , 0
        ;mov word [bx+si] , 0
        ;add si , 2
        ;mov [bx+si] , ax

_2_addition_next:


        cmp dx , di ; comparing the next two elements
        jne _2_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz _2_store__
        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx

        jmp _2_printing


_2_store__:

        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _2_printing


_2_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz _2_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz _2_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing


_2_zero:

        cmp dx , 0
        jz _2_zero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        jmp _2_printing


_2_zero_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _2_printing



_2_next_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        jmp _2_printing




_2_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  _2_equality
        jnz _2_not_equality


_2_equality:
        jmp _2_middle_equal

_2_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz _2_no_sum

_2_sum:

        add dx , di

        cmp dx , 0
        jz _2_result_0

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _2_printing


_2_result_0:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _2_printing

_2_no_sum:
        cmp dx , 0
        jnz _2_next_value

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing


_2_next_value:

        cmp di , 0
        jnz _2_next_value__

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _2_printing


_2_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing


_2_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz _2_first_not_zero



_2_first_zero:

        cmp di , 0
        jz _2_both_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing


_2_both_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        jmp _2_printing



_2_first_not_zero:

        cmp di , 0
        jnz _2_both_not_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _2_printing


_2_both_not_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing


_2_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz _2_is_zero

      cmp di , 0  ;last element is zero
        jz _2_is_zero_

_2_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing

_2_is_zero:         
        cmp di , 0      ;last element
        jz _2_bothzero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si], cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _2_printing

_2_bothzero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _2_printing

_2_is_zero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _2_printing



_2_printing:
        call print

        mov bx , row3
        mov si , 0

row_3:

        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz _3_addition_first_two

        jnz _3_not_     ; when first two cells are not equal

_3_not_:
        jmp _3_not_equal


_3_addition_first_two:    ;first two cells


        add ax , cx
        ;mov si , 0
        ;mov word [bx+si] , 0
        ;add si , 2
        ;mov [bx+si] , ax

_3_addition_next:


        cmp dx , di ; comparing the next two elements
        jne _3_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz _3_store__
        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx

        jmp _3_printing


_3_store__:

        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _3_printing


_3_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz _3_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz _3_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing


_3_zero:

        cmp dx , 0
        jz _3_zero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        jmp _3_printing


_3_zero_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _3_printing



_3_next_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        jmp _3_printing




_3_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  _3_equality
        jnz _3_not_equality


_3_equality:
        jmp _3_middle_equal

_3_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz _3_no_sum

_3_sum:

        add dx , di

        cmp dx , 0
        jz _3_result_0

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _3_printing


_3_result_0:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _3_printing

_3_no_sum:
        cmp dx , 0
        jnz _3_next_value

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing


_3_next_value:

        cmp di , 0
        jnz _3_next_value__

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _3_printing


_3_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing


_3_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz _3_first_not_zero



_3_first_zero:

        cmp di , 0
        jz _3_both_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing


_3_both_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        jmp _3_printing



_3_first_not_zero:

        cmp di , 0
        jnz _3_both_not_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _3_printing


_3_both_not_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing


_3_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz _3_is_zero

      cmp di , 0  ;last element is zero
        jz _3_is_zero_

_3_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing

_3_is_zero:         
        cmp di , 0      ;last element
        jz _3_bothzero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si], cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _3_printing

_3_bothzero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _3_printing

_3_is_zero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _3_printing



_3_printing:
        call print


        mov bx , row4
        mov si , 0

row_4:
        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz _4_addition_first_two

        jnz _4_not_     ; when first two cells are not equal

_4_not_:
        jmp _4_not_equal


_4_addition_first_two:    ;first two cells


        add ax , cx
        ;mov si , 0
        ;mov word [bx+si] , 0
        ;add si , 2
        ;mov [bx+si] , ax

_4_addition_next:


        cmp dx , di ; comparing the next two elements
        jne _4_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz _4_store__
        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx

        jmp _4_printing


_4_store__:

        mov si , 0
        mov word [bx+si] , 0
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _4_printing


_4_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz _4_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz _4_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing


_4_zero:

        cmp dx , 0
        jz _4_zero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        jmp _4_printing


_4_zero_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        jmp _4_printing



_4_next_:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        jmp _4_printing




_4_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  _4_equality
        jnz _4_not_equality


_4_equality:
        jmp _4_middle_equal

_4_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz _4_no_sum

_4_sum:

        add dx , di

        cmp dx , 0
        jz _4_result_0

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _4_printing


_4_result_0:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _4_printing

_4_no_sum:
        cmp dx , 0
        jnz _4_next_value

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing


_4_next_value:

        cmp di , 0
        jnz _4_next_value__

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _4_printing


_4_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing


_4_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz _4_first_not_zero



_4_first_zero:

        cmp di , 0
        jz _4_both_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing


_4_both_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        jmp _4_printing



_4_first_not_zero:

        cmp di , 0
        jnz _4_both_not_zero

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        jmp _4_printing


_4_both_not_zero:

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing


_4_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz _4_is_zero

      cmp di , 0  ;last element is zero
        jz _4_is_zero_

_4_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing

_4_is_zero:         
        cmp di , 0      ;last element
        jz _4_bothzero_

        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si], cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp _4_printing

_4_bothzero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _4_printing

_4_is_zero_:
        mov si , 0
        mov word [bx+si] , 0
        add si , 2
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        jmp _4_printing



_4_printing:
        call print

        call GenRan_right
        jmp interrupt


shift_rows_up:

        mov si , 0

col1:
        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz NO
        jmp SUM

NO :
        jmp NO_SUM


SUM:
        add ax , bx

        cmp cx , dx
        jz SUM_Again

        cmp cx , 0
        jz NEXT

NOT_ZERO_:
        cmp dx , 0
        jnz BOTH_NOT_ZERO

        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT

BOTH_NOT_ZERO:
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp PRINT

NEXT:
        cmp dx , 0
        jz NEXT_

        mov [row1+si] , ax
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT


NEXT_:
        mov [row1+si] , ax
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        call PRINT


SUM_Again:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT



NO_SUM: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz JUMPPP

        jnz NO_EQUALL

JUMPPP:
        jmp AGAINNNN


NO_EQUALL:

        cmp cx , dx  ;comparing last two elements
        jnz NO_SUMMITION

SUMMITION:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp PRINT

NO_SUMMITION:
        cmp cx , 0
        jz NEXT_CAL

NOT_0: ; 2nd last element != 0
        cmp dx , 0
        jz NEXT__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT

NEXT__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp PRINT

NEXT_CAL:  ;2nd last element = 0
        cmp dx , 0  ;
        jz LAST_0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp PRINT

LAST_0: ;last element = 0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT

AGAINNNN:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz CHECK

NOT_ZERO_FIRST:

        cmp dx , 0
        jz ZERO__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp PRINT

ZERO__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT

CHECK:
        cmp dx , 0
        jz CHECK_AGAIN

        mov [row1+si] , bx
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT

CHECK_AGAIN:
        mov [row1+si] , bx
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp PRINT



PRINT:
        call print

col2:

        mov si , 2

        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz _NO
        jmp _SUM

_NO :
        jmp _NO_SUM


_SUM:
        add ax , bx

        cmp cx , dx
        jz _SUM_Again

        cmp cx , 0
        jz _NEXT

_NOT_ZERO_:
        cmp dx , 0
        jnz _BOTH_NOT_ZERO

        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT

_BOTH_NOT_ZERO:
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _PRINT

_NEXT:
        cmp dx , 0
        jz _NEXT_

        mov [row1+si] , ax
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT


_NEXT_:
        mov [row1+si] , ax
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        call _PRINT


_SUM_Again:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT



_NO_SUM: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz _JUMPPP

        jnz _NO_EQUALL

_JUMPPP:
        jmp _AGAINNNN


_NO_EQUALL:

        cmp cx , dx  ;comparing last two elements
        jnz _NO_SUMMITION

_SUMMITION:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp _PRINT

_NO_SUMMITION:
        cmp cx , 0
        jz _NEXT_CAL

_NOT_0: ; 2nd last element != 0
        cmp dx , 0
        jz _NEXT__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp _PRINT

_NEXT__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp _PRINT

_NEXT_CAL:  ;2nd last element = 0
        cmp dx , 0  ;
        jz _LAST_0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _PRINT

_LAST_0: ;last element = 0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT

_AGAINNNN:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz _CHECK

_NOT_ZERO_FIRST:

        cmp dx , 0
        jz _ZERO__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _PRINT

_ZERO__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT

_CHECK:
        cmp dx , 0
        jz _CHECK_AGAIN

        mov [row1+si] , bx
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT

_CHECK_AGAIN:
        mov [row1+si] , bx
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _PRINT


_PRINT:
        call print


col3:
        mov ax , [row1+4]
        mov bx , [row2+4]
        mov cx , [row3+4]
        mov dx , [row4+4]


        cmp ax , bx
        jnz __NO
        jmp __SUM

__NO :
        jmp __NO_SUM


__SUM:
        add ax , bx

        cmp cx , dx
        jz __SUM_Again

        cmp cx , 0
        jz __NEXT

__NOT_ZERO_:
        cmp dx , 0
        jnz __BOTH_NOT_ZERO

        mov [row1+4] , ax
        mov [row2+4] , cx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT

__BOTH_NOT_ZERO:
        mov [row1+4] , ax
        mov [row2+4] , cx
        mov [row3+4] , dx
        mov word [row4+4] , 0
        jmp __PRINT

__NEXT:
        cmp dx , 0
        jz __NEXT_

        mov [row1+4] , ax
        mov [row2+4] , dx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT


__NEXT_:
        mov [row1+4] , ax
        mov word [row2+4] , 0
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        call __PRINT


__SUM_Again:
        add cx , dx
        mov [row1+4] , ax
        mov [row2+4] , cx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT



__NO_SUM: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz __JUMPPP

        jnz __NO_EQUALL

__JUMPPP:
        jmp __AGAINNNN


__NO_EQUALL:

        cmp cx , dx  ;comparing last two elements
        jnz __NO_SUMMITION

__SUMMITION:
        add cx , dx
        mov [row1+4] , ax
        mov [row2+4] , bx
        mov [row3+4] , cx
        mov word [row4+4] , 0
        jmp __PRINT

__NO_SUMMITION:
        cmp cx , 0
        jz __NEXT_CAL

__NOT_0: ; 2nd last element != 0
        cmp dx , 0
        jz __NEXT__

        mov [row1+4] , ax
        mov [row2+4] , bx
        mov [row3+4] , cx
        mov [row4+4] , dx
        jmp __PRINT

__NEXT__:
        mov [row1+4] , ax
        mov [row2+4] , bx
        mov [row3+4] , cx
        mov word [row4+4] , 0
        jmp __PRINT

__NEXT_CAL:  ;2nd last element = 0
        cmp dx , 0  ;
        jz __LAST_0

        mov [row1+4] , ax
        mov [row2+4] , bx
        mov [row3+4] , dx
        mov word [row4+4] , 0
        jmp __PRINT

__LAST_0: ;last element = 0

        mov [row1+4] , ax
        mov [row2+4] , bx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT

__AGAINNNN:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz __CHECK

__NOT_ZERO_FIRST:

        cmp dx , 0
        jz __ZERO__

        mov [row1+4] , ax
        mov [row2+4] , bx
        mov [row3+4] , dx
        mov word [row4+4] , 0
        jmp __PRINT

__ZERO__:
        mov [row1+4] , ax
        mov [row2+4] , bx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT

__CHECK:
        cmp dx , 0
        jz __CHECK_AGAIN

        mov [row1+4] , bx
        mov [row2+4] , dx
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT

__CHECK_AGAIN:
        mov [row1+4] , bx
        mov word [row2+4] , 0
        mov word [row3+4] , 0
        mov word [row4+4] , 0
        jmp __PRINT


__PRINT:
        call print




col4:
        mov si , 6

      mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz _4NO
        jmp _4SUM

_4NO :
        jmp _4NO_SUM


_4SUM:
        add ax , bx

        cmp cx , dx
        jz _4SUM_Again

        cmp cx , 0
        jz _4NEXT

_4NOT_ZERO_:
        cmp dx , 0
        jnz _4BOTH_NOT_ZERO

        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT

_4BOTH_NOT_ZERO:
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _4PRINT

_4NEXT:
        cmp dx , 0
        jz _4NEXT_

        mov [row1+si] , ax
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT


_4NEXT_:
        mov [row1+si] , ax
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        call _4PRINT


_4SUM_Again:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , cx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT



_4NO_SUM: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz _4JUMPPP

        jnz _4NO_EQUALL

_4JUMPPP:
        jmp _4AGAINNNN


_4NO_EQUALL:

        cmp cx , dx  ;comparing last two elements
        jnz _4NO_SUMMITION

_4SUMMITION:
        add cx , dx
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp _4PRINT

_4NO_SUMMITION:
        cmp cx , 0
        jz _4NEXT_CAL

_4NOT_0: ; 2nd last element != 0
        cmp dx , 0
        jz _4NEXT__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp _4PRINT

_4NEXT__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov word [row4+si] , 0
        jmp _4PRINT

_4NEXT_CAL:  ;2nd last element = 0
        cmp dx , 0  ;
        jz _4LAST_0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _4PRINT

_4LAST_0: ;last element = 0

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT

_4AGAINNNN:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz _4CHECK

_4NOT_ZERO_FIRST:

        cmp dx , 0
        jz _4ZERO__

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , dx
        mov word [row4+si] , 0
        jmp _4PRINT

_4ZERO__:
        mov [row1+si] , ax
        mov [row2+si] , bx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT

_4CHECK:
        cmp dx , 0
        jz _4CHECK_AGAIN

        mov [row1+si] , bx
        mov [row2+si] , dx
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT

_4CHECK_AGAIN:
        mov [row1+si] , bx
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov word [row4+si] , 0
        jmp _4PRINT



_4PRINT:
        call print
        call GenRan_down

        jmp interrupt


shift_rows_down:

        mov si , 0

column1:
        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz NO_D
        jmp SUM_D

NO_D :
        jmp NO_SUM_D


SUM_D:
        add ax , bx

        cmp cx , dx
        jz SUM_Again_D

        cmp cx , 0
        jz D_NEXT

NOT_ZERO_D:
        cmp dx , 0
        jnz BOTH_NOT_ZERO_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D

BOTH_NOT_ZERO_D:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D

D_NEXT:
        cmp dx , 0
        jz NEXT_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , dx
        jmp PRINT_D


NEXT_D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , ax
        call PRINT_D


SUM_Again_D:
        add cx , dx
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D



NO_SUM_D: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz JUMPPP_D

        jnz NO_EQUALL_D

JUMPPP_D:
        jmp AGAINNNN_D


NO_EQUALL_D:

        cmp cx , dx  ;comparing last two elements
        jnz NO_SUMMITION_D

SUMMITION_D:
        add cx , dx
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D

NO_SUMMITION_D:
        cmp cx , 0
        jz NEXT_CAL_D

NOT_0_D: ; 2nd last element != 0
        cmp dx , 0
        jz NEXT__D

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D

NEXT__D:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D

NEXT_CAL_D:  ;2nd last element = 0
        cmp dx , 0  ;
        jz LAST_0_D

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D

LAST_0_D: ;last element = 0

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D

AGAINNNN_D:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz CHECK_D

NOT_ZERO_FIRST_D:

        cmp dx , 0
        jz ZERO__D

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D

ZERO__D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D

CHECK_D:
        cmp dx , 0
        jz CHECK_AGAIN_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D

CHECK_AGAIN_D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , bx
        jmp PRINT_D



PRINT_D:
        call print


column2:
        mov si , 2
        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz NO_D_
        jmp SUM_D_

NO_D_ :
        jmp NO_SUM_D_


SUM_D_:
        add ax , bx

        cmp cx , dx
        jz SUM_Again_D_

        cmp cx , 0
        jz D_NEXT_

NOT_ZERO_D_:
        cmp dx , 0
        jnz BOTH_NOT_ZERO_D_

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D_

BOTH_NOT_ZERO_D_:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D_

D_NEXT_:
        cmp dx , 0
        jz NEXT_D_

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , dx
        jmp PRINT_D_


NEXT_D_:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , ax
        call PRINT_D_


SUM_Again_D_:
        add cx , dx
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D_



NO_SUM_D_: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz JUMPPP_D_

        jnz NO_EQUALL_D_

JUMPPP_D_:
        jmp AGAINNNN_D_


NO_EQUALL_D_:

        cmp cx , dx  ;comparing last two elements
        jnz NO_SUMMITION_D_

SUMMITION_D_:
        add cx , dx
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D_

NO_SUMMITION_D_:
        cmp cx , 0
        jz NEXT_CAL_D_

NOT_0_D_: ; 2nd last element != 0
        cmp dx , 0
        jz NEXT__D_

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D_

NEXT__D_:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D_

NEXT_CAL_D_:  ;2nd last element = 0
        cmp dx , 0  ;
        jz LAST_0_D_

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D_

LAST_0_D_: ;last element = 0

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D_

AGAINNNN_D_:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz CHECK_D_

NOT_ZERO_FIRST_D_:

        cmp dx , 0
        jz ZERO__D_

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D_

ZERO__D_:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D_

CHECK_D_:
        cmp dx , 0
        jz CHECK_AGAIN_D_

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D_

CHECK_AGAIN_D_:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , bx
        jmp PRINT_D_



PRINT_D_:
        call print

column3:
        mov si , 4
        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz _NO_D
        jmp _SUM_D

_NO_D :
        jmp _NO_SUM_D


_SUM_D:
        add ax , bx

        cmp cx , dx
        jz _SUM_Again_D

        cmp cx , 0
        jz _D_NEXT

_NOT_ZERO_D:
        cmp dx , 0
        jnz _BOTH_NOT_ZERO_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp _PRINT_D

_BOTH_NOT_ZERO_D:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp _PRINT_D

_D_NEXT:
        cmp dx , 0
        jz _NEXT_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , dx
        jmp _PRINT_D


_NEXT_D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , ax
        call _PRINT_D


_SUM_Again_D:
        add cx , dx
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp _PRINT_D



_NO_SUM_D: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz _JUMPPP_D

        jnz _NO_EQUALL_D

_JUMPPP_D:
        jmp _AGAINNNN_D


_NO_EQUALL_D:

        cmp cx , dx  ;comparing last two elements
        jnz _NO_SUMMITION_D

_SUMMITION_D:
        add cx , dx
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp _PRINT_D

_NO_SUMMITION_D:
        cmp cx , 0
        jz _NEXT_CAL_D

_NOT_0_D: ; 2nd last element != 0
        cmp dx , 0
        jz _NEXT__D

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp _PRINT_D

_NEXT__D:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp _PRINT_D

_NEXT_CAL_D:  ;2nd last element = 0
        cmp dx , 0  ;
        jz _LAST_0_D

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp _PRINT_D

_LAST_0_D: ;last element = 0

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp _PRINT_D

_AGAINNNN_D:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz _CHECK_D

_NOT_ZERO_FIRST_D:

        cmp dx , 0
        jz _ZERO__D

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp _PRINT_D

_ZERO__D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp _PRINT_D

_CHECK_D:
        cmp dx , 0
        jz _CHECK_AGAIN_D

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp _PRINT_D

_CHECK_AGAIN_D:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , bx
        jmp _PRINT_D



_PRINT_D:
        call print

column4:
        mov si , 6

        mov ax , [row1+si]
        mov bx , [row2+si]
        mov cx , [row3+si]
        mov dx , [row4+si]


        cmp ax , bx
        jnz NO_D4
        jmp SUM_D4

NO_D4 :
        jmp NO_SUM_D4


SUM_D4:
        add ax , bx

        cmp cx , dx
        jz SUM_Again_D4

        cmp cx , 0
        jz D_NEXT4

NOT_ZERO_D4:
        cmp dx , 0
        jnz BOTH_NOT_ZERO_D4

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D4

BOTH_NOT_ZERO_D4:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D4

D_NEXT4:
        cmp dx , 0
        jz NEXT_D4

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , dx
        jmp PRINT_D4


NEXT_D4:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , ax
        call PRINT_D4


SUM_Again_D4:
        add cx , dx
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , cx
        jmp PRINT_D4



NO_SUM_D4: ;first two elements are not equal

        cmp bx , cx   ;checking 2nd and 3rd element
        jz JUMPPP_D4

        jnz NO_EQUALL_D4

JUMPPP_D4:
        jmp AGAINNNN_D4


NO_EQUALL_D4:

        cmp cx , dx  ;comparing last two elements
        jnz NO_SUMMITION_D4

SUMMITION_D4:
        add cx , dx
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D4

NO_SUMMITION_D4:
        cmp cx , 0
        jz NEXT_CAL_D4

NOT_0_D4: ; 2nd last element != 0
        cmp dx , 0
        jz NEXT__D4

        mov [row1+si] , ax
        mov [row2+si] , bx
        mov [row3+si] , cx
        mov [row4+si] , dx
        jmp PRINT_D4

NEXT__D4:
        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , cx
        jmp PRINT_D4

NEXT_CAL_D4:  ;2nd last element = 0
        cmp dx , 0  ;
        jz LAST_0_D4

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D4

LAST_0_D4: ;last element = 0

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D4

AGAINNNN_D4:  ;2nd and 3rd element are =

        add bx , cx ;addition


        cmp ax , 0
        jz CHECK_D4

NOT_ZERO_FIRST_D4:

        cmp dx , 0
        jz ZERO__D4

        mov word [row1+si] , 0
        mov [row2+si] , ax
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D4

ZERO__D4:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , ax
        mov [row4+si] , bx
        jmp PRINT_D4

CHECK_D4:
        cmp dx , 0
        jz CHECK_AGAIN_D4

        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov [row3+si] , bx
        mov [row4+si] , dx
        jmp PRINT_D4

CHECK_AGAIN_D4:
        mov word [row1+si] , 0
        mov word [row2+si] , 0
        mov word [row3+si] , 0
        mov [row4+si] , bx
        jmp PRINT_D4



PRINT_D4:
        call print
        call GenRan_up

        jmp interrupt


shifting_rows_left:

        mov bx , row1
        mov si , 0

Row_1:

        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz L_addition_first_two

        jnz L_not_     ; when first two cells are not equal

L_not_:
        jmp L_not_equal


L_addition_first_two:    ;first two cells


        add ax , cx

L_addition_next:


        cmp dx , di ; comparing the next two elements
        jne L_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz L_store__
        mov si , 0
        mov [bx+si] , ax
        add si ,  2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0

        jmp L_printing


L_store__:

        mov si , 0
        mov word [bx+si] , ax
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz L_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz L_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_zero:

        cmp dx , 0
        jz L_zero_

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_zero_:

        mov si , 0
        mov word [bx+si] , ax
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing



L_next_:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing




L_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  L_equality
        jnz L_not_equality


L_equality:
        jmp L_middle_equal

L_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz L_no_sum

L_sum:

        add dx , di

        cmp dx , 0
        jz L_result_0

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_result_0:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing

L_no_sum:
        cmp dx , 0
        jnz L_next_value

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_next_value:

        cmp di , 0
        jnz L_next_value__

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L_printing


L_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz L_first_not_zero



L_first_zero:

        cmp di , 0
        jz L_both_zero

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_both_zero:

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing



L_first_not_zero:

        cmp di , 0
        jnz L_both_not_zero

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_both_not_zero:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing


L_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz L_is_zero

      cmp di , 0  ;last element is zero
        jz L_is_zero_

L_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L_printing

L_is_zero:         
        cmp di , 0 ;last element
        jz L_bothzero_

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si], dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing

L_bothzero_:
        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing

L_is_zero_:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L_printing



L_printing:
        call print


        mov bx , row2
        mov si , 0

Row_2:

        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz L2_addition_first_two

        jnz L2_not_     ; when first two cells are not equal

L2_not_:
        jmp L2_not_equal


L2_addition_first_two:    ;first two cells


        add ax , cx

L2_addition_next:


        cmp dx , di ; comparing the next two elements
        jne L2_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz L2_store__
        mov si , 0
        mov [bx+si] , ax
        add si ,  2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0

        jmp L2_printing


L2_store__:

        mov si , 0
        mov word [bx+si] , ax
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz L2_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz L2_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_zero:

        cmp dx , 0
        jz L2_zero_

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_zero_:

        mov si , 0
        mov word [bx+si] , ax
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing



L2_next_:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing




L2_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  L2_equality
        jnz L2_not_equality


L2_equality:
        jmp L2_middle_equal

L2_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz L2_no_sum

L2_sum:

        add dx , di

        cmp dx , 0
        jz L2_result_0

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_result_0:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing

L2_no_sum:
        cmp dx , 0
        jnz L2_next_value

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_next_value:

        cmp di , 0
        jnz L2_next_value__

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L2_printing


L2_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz L2_first_not_zero



L2_first_zero:

        cmp di , 0
        jz L2_both_zero

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_both_zero:

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing



L2_first_not_zero:

        cmp di , 0
        jnz L2_both_not_zero

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_both_not_zero:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing


L2_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz L2_is_zero

      cmp di , 0  ;last element is zero
        jz L2_is_zero_

L2_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L2_printing

L2_is_zero:         
        cmp di , 0 ;last element
        jz L2_bothzero_

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si], dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing

L2_bothzero_:
        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing

L2_is_zero_:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L2_printing



L2_printing:
        call print


Row_3:
        mov bx , row3
        mov si , 0

        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz L3_addition_first_two

        jnz L3_not_     ; when first two cells are not equal

L3_not_:
        jmp L3_not_equal


L3_addition_first_two:    ;first two cells


        add ax , cx

L3_addition_next:


        cmp dx , di ; comparing the next two elements
        jne L3_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz L3_store__
        mov si , 0
        mov [bx+si] , ax
        add si ,  2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0

        jmp L3_printing


L3_store__:

        mov si , 0
        mov word [bx+si] , ax
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz L3_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz L3_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_zero:

        cmp dx , 0
        jz L3_zero_

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_zero_:

        mov si , 0
        mov word [bx+si] , ax
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing



L3_next_:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing




L3_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  L3_equality
        jnz L3_not_equality


L3_equality:
        jmp L3_middle_equal

L3_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz L3_no_sum

L3_sum:

        add dx , di

        cmp dx , 0
        jz L3_result_0

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_result_0:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing

L3_no_sum:
        cmp dx , 0
        jnz L3_next_value

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_next_value:

        cmp di , 0
        jnz L3_next_value__

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L3_printing


L3_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz L3_first_not_zero



L33_first_zero:

        cmp di , 0
        jz L3_both_zero

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_both_zero:

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing



L3_first_not_zero:

        cmp di , 0
        jnz L3_both_not_zero

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_both_not_zero:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing


L3_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz L3_is_zero

      cmp di , 0  ;last element is zero
        jz L3_is_zero_

L3_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L3_printing

L3_is_zero:         
        cmp di , 0 ;last element
        jz L3_bothzero_

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si], dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing

L3_bothzero_:
        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing

L3_is_zero_:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L3_printing



L3_printing:
        call print

        mov bx , row4
        mov si , 0

Row_4:
        mov ax , [bx+si]
        add si , 2
        mov cx , [bx+si]
        add si , 2
        mov dx , [bx+si]
        add si  , 2
        mov di , [bx+si]


        cmp ax , cx      ;comparing first two elements
        jz L4_addition_first_two

        jnz L4_not_     ; when first two cells are not equal

L4_not_:
        jmp L4_not_equal


L4_addition_first_two:   ;first two cells


        add ax , cx

L4_addition_next:


        cmp dx , di ; comparing the next two elements
        jne L4_storage_

        add dx , di  ;adding the next two elements
        cmp dx , 0
        jz L4_store__
        mov si , 0
        mov [bx+si] , ax
        add si ,  2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0

        jmp L4_printing


L4_store__:

        mov si , 0
        mov word [bx+si] , ax
        add si ,  2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_storage_:


        cmp di , 0 ;checking if the last cell is 0 or not
        jz L4_zero

        cmp dx , 0 ;checking if the 2nd last element is 0 or not
        jz L4_next_

        mov si , 0 ;if both 3rd and 4th cell are not 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_zero:

        cmp dx , 0
        jz L4_zero_

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_zero_:

        mov si , 0
        mov word [bx+si] , ax
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing



L4_next_:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing




L4_not_equal:         ;first two cells are not equal

        cmp cx , dx  ;comparing the middle elements
        jz  L4_equality
        jnz L4_not_equality


L4_equality:
        jmp L4_middle_equal

L4_not_equality:

        cmp dx , di    ;last two cells are equal
        jnz L4_no_sum

L4_sum:

        add dx , di

        cmp dx , 0
        jz L4_result_0

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_result_0:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing

L4_no_sum:
        cmp dx , 0
        jnz L4_next_value

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_next_value:

        cmp di , 0
        jnz L4_next_value__

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_next_value__:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L4_printing


L4_middle_equal:

        add cx , dx ;addition

        cmp ax , 0
        jnz L4_first_not_zero



L4_first_zero:

        cmp di , 0
        jz L4_both_zero

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_both_zero:

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing



L4_first_not_zero:

        cmp di , 0
        jnz L4_both_not_zero

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_both_not_zero:

        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing


L4_middle_not_equal:

        cmp ax , 0 ;first element is zero
        jz L4_is_zero

      cmp di , 0  ;last element is zero
        jz L4_is_zero_

L4_bothnot_zero:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov [bx+si] , di
        jmp L4_printing

L4_is_zero:         
        cmp di , 0 ;last element
        jz L4_bothzero_

        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si], dx
        add si , 2
        mov [bx+si] , di
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing

L4_bothzero_:
        mov si , 0
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing

L4_is_zero_:
        mov si , 0
        mov [bx+si] , ax
        add si , 2
        mov [bx+si] , cx
        add si , 2
        mov [bx+si] , dx
        add si , 2
        mov word [bx+si] , 0
        jmp L4_printing



L4_printing:
        call print
        call GenRan_left

        jmp interrupt


start:

call clrscr
call main_window
mov ah,0
int 16h

call clrscr

call printMessage ; boundaries

call grid ;printing grid

call print ; printing arrays in grid



interrupt:
call check_win
cmp word [extra],1
jz end

mov ah , 0

INT 0x16 ;keyboard interrupt

cmp ah , 0x4D ; right
jnz next_cmp

call shifting_cols_right


next_cmp:

cmp ah , 0x48  ;up
jnz nextcmp

call shift_rows_up

nextcmp:

        cmp ah , 0x50   ;down
        jnz lastcmp

        call shift_rows_down

lastcmp:

        cmp ah , 0x4B   ;left
        call shifting_rows_left

        jmp interrupt
end:

mov ax , 0x4c00
int 0x21