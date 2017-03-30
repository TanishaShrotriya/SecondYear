 section .data
	msg1 db "Enter a BCD number: ",0ah 
	msg1len equ $-msg1
	msg2 db " Hexadecimal number  : ",0ah
	msg2len equ $-msg2
	base dw 10


section .bss 
	temp: resb 1
	bcdno:resw 1
	num1:resw 1
	num:resw 1 
	nostr: resb 4

section .text
global _start

_start:

;------------------------to display message------------------------

	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,msg1len
	syscall
;-------------------------------------------------------------------





;------------------------to accept BCD number-----------------------
	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,5
	syscall
	dec rax

	mov ax,0
	mov cl,4
	mov esi,temp
	again:
		mov bl,[esi]
		sub bl,30h
		shl ax,4
		movzx bx,bl
		add ax,bx
		inc esi
		dec cl
		jnz again
		
	;loop to form BCD value
;------------------------------------------------------------------------



;--------------------------conversion--------------------	
	mov[bcdno],ax
	mov cl,12
	mov word[num],0
	;number BCD
	mov ch,4
	mov bx,0f000h
	ag:
		mov ax,[num]
		mul word [base]
		mov dx,[bcdno]
		and dx,bx
		shr dx,cl
		
		add ax,dx
		mov[num],ax
		sub cl,04
		shr bx,04
		dec ch
		jnz ag
	
;---------------------------------------------------------------------



	
;-----------------------------display no--------------------------------



	mov esi,nostr
	mov[num1],ax
	mov ch,04
	mov cl,12
	mov bx,0f000h
	ag1:
		mov ax,[num1]
		and ax,bx
		shr ax,cl
		cmp ax,09
		ja add37
		add al,30h
		jmp store
	add37:
		add al,37h

	store:
		mov [esi],al
		inc esi
		shr bx,4
		sub cl,4
		dec ch
		jnz ag1
		jz skip
	skip:
 		
		mov rax,1
		mov rdi,1         ;--------- to display hexadecimal no :
		mov rsi,msg2
		mov rdx,msg2len
		syscall



		mov rax,1		;Displaying the final message 
		mov rdi,1 
		mov rsi,nostr 
		mov rdx,50 
		syscall 
		jmp end 
	
	end: 
		mov rax,60		;system call to exit program 
		mov rdi,0 
		syscall 
