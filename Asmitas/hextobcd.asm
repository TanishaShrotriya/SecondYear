;Program 3.b: Conversion HEX to BCD

section .data 
	msg1 db "Enter HEX number: " 
	msg1len equ $-msg1 
	msg2 db "Invalid length..!",0AH 
	msg2len equ $-msg2 
	msg3 db "Invalid Number..!",0AH 
	msg3len equ $-msg3 
	msg4 db "Equivalent BCD is: " 
	msg4len equ $-msg4 
		 
section .bss 
	hexno:resb 6 
	ctr:resb 1 
	res:resb 6 

section .text 
global _start 
_start: 
	loop: 
		;Display msg 1 
		accept:	mov rax,1 
			mov rdi,1 
			mov rsi,msg1 
			mov rdx,msg1len 
			syscall 
		;Accept the number 
		mov rax,0 
		mov rdi,0 
		mov rsi,hexno 
		mov rdx,6 
		syscall 
		dec al 
	 
		cmp al,0 
		jz invalid 
		cmp al,4 
		ja invalid        ;jump above 

		mov esi,hexno 
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
	mov rsi,msg3 
	mov rdx,msg3len 
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

loop1:   
	mov dx,0 
	div bx 
	push dx 
	inc cl 
	cmp ax,0 
	ja loop1  ;jump if above 

loop2: 
	pop dx 
	cmp dl,0 
	jb add30  ;jump if below 

add30: 
	add dl,30H 
	mov byte[esi],dl 
	inc esi 
	dec cl 
	jnz loop2 
	 
	;Display msg 4(equivalent Bcd message)        
	mov rax,1 
	mov rdi,1 
	mov rsi,msg4 
	mov rdx,msg4len 
	syscall 

	mov rax,1 
	mov rdi,1 
	mov rsi,res 
	mov rdx,6 
	syscall 
	jmp skip1 

invalid: 
	;Display msg2 (Invalid length) 
	mov rax,1 
	mov rdi,1 
	mov rsi,msg2 
	mov rdx,msg2len 
	syscall 
	jmp accept	;accept HEX number again 
	 
skip1:	mov rax,60	 
	mov rdx,0 
	syscall 
	
