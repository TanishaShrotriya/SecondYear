section .data
	msg1 db "ENTER THE DECIMAL NUMBER",0AH
	msg1len equ $ -msg1

	msg2 db "IN HEXADECIMAL SYSTEM ",0AH
	msg2len equ $ -msg2

	msg3 db "Enter HEX number: " 
	msg3len equ $-msg3 

	msg4 db "Invalid length..!",0AH 
	msg4len equ $-msg4

	msg5 db "Invalid Number..!",0AH 
	msg5len equ $-msg5

	msg6 db "Equivalent BCD is: " 
	msg6len equ $-msg6

	msg7 db "ENTER YOUR CHOICE: " ,0AH
	msg7len equ $-msg7

	msg8 db "1.BCD/DECIMAL TO HEX    2.HEXADECIMAL TO BCD/DECIMAL " ,0AH
	msg8len equ $-msg8

	msg9 db 0AH,"DO YOU WANT TO CONTINUE??(1/0)" ,0AH
	msg9len equ $-msg9


	num dw 0
	base dw 10


section .bss
	temp  :resb 5
	bcdno :resw 1
	hexno:resw 1
	hexstr:resb 4
	hex_no:resb 6 
	ctr:resb 1 
	res:resb 6 
	ans :resb 2
	choice :resb 2
section .text
global _start
_start:
;==================================ACCEPT USER CHOICE========================================================
user:
	mov rax,1
	mov rdi,1
	mov rsi,msg7
	mov rdx,msg7len
 	syscall

	mov rax,1
	mov rdi,1
	mov rsi,msg8
	mov rdx,msg8len
 	syscall

	mov rax,0
	mov rdi,0 
	mov rsi,ans
	mov rdx,2
 	syscall

	mov al,[ans]
	cmp al,31H
	je bcd
	jne hex
;===================================DECIMAL/BCD TO HEXADECIMAL================================================
bcd:
;------------------------ACCEPT AND DISPLAY------------------
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,msg1len
 	syscall


	mov rax,0
	mov rdi,0 
	mov rsi,temp
	mov rdx,5
 	syscall
;--------------------PACKING OF NUMBER---------------------------
	mov cl,4
	mov ax,0
	mov bh,0
	mov esi,temp
  loop:
	mov bl,[esi]
	sub bl,30H
	shl ax,4
	;movzx bx,bl
	add ax,bx
	inc esi
	dec cl
	jnz loop


;----------------convert to hex-------------------------
	mov [bcdno],ax
	mov cl,12
	mov word[num],0
	mov bx,0F000H
	mov ch,4
 loop1:
	
	mov ax,[num]
	mul word[base]
	mov dx,[bcdno]
	AND dx,bx
	shr dx,cl
	
	
	add ax,dx
	mov [num],ax
	shr bx,4
	sub cl,4
	dec ch
	jnz loop1



;------------display hexadecimal number-------------------
	mov esi,hexstr 
	mov [hexno],ax
	mov cl,12
	mov ch,4
	mov bx,0F000H

	
 again:
	mov ax,[hexno]
	AND ax,bx
	shr ax,cl
	cmp al,09
	ja add37
	add al,30H
	
	jmp store
 add37: 
	add al,37H
	
 store:
	mov [esi],al
	inc esi
	sub cl,04
	shr bx,04
	dec ch
	jnz again

 display:
	
	mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,msg2len
 	syscall

	mov rax,1
	mov rdi,1
	mov rsi,hexstr
	mov rdx,4
	
	syscall
skip1:
	mov rax,1
	mov rdi,1
	mov rsi,msg9
	mov rdx,msg9len
 	syscall 
	  	
	mov rax,0 
	mov rdi,0 
	mov rsi,choice
	mov rdx,2
	syscall 
	
 	mov al,[choice]
	cmp al,31H
	je user
	
	mov rax,60	 
	mov rdx,0 
	syscall 
	
;=====================HEXADECIMAL TO BCD/DECIMAL=======================================================
hex:
hex1: 
		;Display msg 1 
		accept:	mov rax,1 
			mov rdi,1 
			mov rsi,msg3
			mov rdx,msg3len 
			syscall 
		;Accept the number 
		mov rax,0 
		mov rdi,0 
		mov rsi,hex_no 
		mov rdx,6 
		syscall 
		dec al 
	 
		cmp al,0 
		jz invalid 
		cmp al,4 
		ja invalid        ;jump above 

		mov esi,hex_no 
		mov byte[ctr],al  ;length of number 
		mov bx,10H        ;base 
		mov ax,0          ;num 
	 
	up:	mov cx,0 
		mov cl,byte[esi] 
		cmp cl,30H 
		jb invalid1 
		cmp cl,39H 
 		jbe valid 
		cmp cl,41H 
		jb invalid1        ;jump if  below 
		cmp cl,46H 
		jbe valid1 
	 
invalid1: 
	;Display msg 3(Invalid Number) 
	mov rax,1 
	mov rdi,1 
	mov rsi,msg5
	mov rdx,msg5len 
	syscall 
	jmp accept 

valid1: sub cl,07H     ;cl=cl-07H 

valid:	sub cl,30H     ;cl=cl-30H 
	mul bx 
	add ax,cx 
	inc esi 
	dec byte[ctr] 
	jnz up 
		 
skip: 
	;Display Number 
	mov esi,res 
	mov cl,0 
	mov ch,0 
	mov bx,10 

hex2:   
	mov dx,0 
	div bx 
	push dx 
	inc cl 
	cmp ax,0 
	ja hex2 ;jump if above 

hex3: 
	pop dx 
	cmp dl,0 
	jb add30  ;jump if below 

add30: 
	add dl,30H 
	mov byte[esi],dl 
	inc esi 
	dec cl 
	jnz hex3 
	 
	;Display msg 4(equivalent Bcd message)        
	mov rax,1 
	mov rdi,1 
	mov rsi,msg6
	mov rdx,msg6len 
	syscall 

	mov rax,1 
	mov rdi,1 
	mov rsi,res 
	mov rdx,6 
	
	syscall 
	jmp skip8

invalid: 
	;Display msg2 (Invalid length) 
	mov rax,1 
	mov rdi,1 
	mov rsi,msg4 
	mov rdx,msg4len 
	syscall 
	jmp accept	;accept HEX number again 
	 
skip8:
	mov rax,1
	mov rdi,1
	mov rsi,msg9
	mov rdx,msg9len
 	syscall 
	  	
	mov rax,0 
	mov rdi,0 
	mov rsi,choice
	mov rdx,2
	syscall 
 	mov ah,[choice]
	cmp ah,31H
	je user
	
skip2:	mov rax,60	 
	mov rdx,0 
	syscall 
	

	







	
