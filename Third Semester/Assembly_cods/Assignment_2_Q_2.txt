[org 0x0100]
jmp start
array1: dw 6, 7,3, 9, 100, 5, 1, 50
swap: db 0
lenArray1: dw 8
min :dw 0
max:dw 0
median : dw 0

start:
 	mov ax, array1
	push ax ; place start of array on stack
	mov ax, [lenArray1]
	push ax ; place element count on stack
	
	call statsofarray
	mov bx,[min]		;Minimum value stored in bx register
	mov cx,[max]		; maximum value stored in cx register
	mov dx,[median]		; median stored in dx register

	mov ax, 0x4c00 		; terminate program
	int 0x21



statsofarray:
	call bubblesort
	push bp
	mov bp,sp
	push ax
	push bx
	push si
	push cx
	mov bx,[bp+6]
	mov si,0
	mov ax,[bx+si]
	mov [min],ax
	mov ax,[bp+4]
	mov bx ,2
	mul bx
	mov si,ax
	mov bx,[bp+6]
	sub si,2
	mov ax,[bx+si]		
	mov [max],ax
	mov ax,[bp+4]
	mov bx,2
	div bx
	cmp dx,0
	jz l2
	; IN case of Even number
	mul bx
	mov bx,ax
	sub bx,2
	mov si,[bp+6]
	mov ax,[si+bx]
	mov [median],ax
	jmp end
	
	

l2:
	;IN case of odd number
	add ax,2
	mov bx,ax
	mov si,[bp+6]
	mov ax,[si+bx]
	add bx,2
	mov cx,[si+bx]
	add ax,cx
	mov bx,2
	div bx
	mov [median],ax

end:
	pop cx
	pop si 
	pop bx
	pop ax
	mov sp, bp 			; remove space created on stack
	pop bp 
	ret 4



bubblesort:
	push bp	 		; save old value of bp
	mov bp, sp 			; make bp our reference point
	sub sp, 2 			; make two byte space on stack
	push ax 			; save old value of ax
	push bx 			; save old value of bx
	push cx 			; save old value of cx
	push si 			; save old value of si
	mov bx, [bp+8] 		; load start of array in bx
	mov cx, [bp+6] 		; load count of elements in cx
	dec cx 			;last element not compared
	shl cx, 1 			; turn into byte count
mainloop:
	 mov si, 0 			; initialize array index to zero
	mov word [bp-2], 0 	; reset swap flag to no swaps
innerloop: 
	mov ax, [bx+si] 		; load number in ax
	cmp ax, [bx+si+2] 	; compare with next number
	jbe noswap 			; no swap if already in order
	xchg ax, [bx+si+2] 	; exchange ax with second number
	mov [bx+si], ax 		; store second number in first
	mov word [bp-2], 1 	; flag that a swap has been done
	noswap: add si, 2 	; advance si to next index
	cmp si, cx 			; are we at last index
	jne innerloop 		; if not compare next two
	cmp word [bp-2], 1 	; check if a swap has been done
	je mainloop 		; if yes make another pass
	pop si 			; restore old value of si
	pop cx 			; restore old value of cx
	pop bx 			; restore old value of bx
	pop ax 			; restore old value of ax
	mov sp, bp 			; remove space created on stack
	pop bp 			; restore old value of bp
	ret   			; go back and remove two params
	