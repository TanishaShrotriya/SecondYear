section .data
	fname db "abc.txt",00H
	msg1 db "The number of blank spaces is :"
	str1len equ $-msg1
	msg2 db "The number of lines is :"
	str2len equ $-msg2
	msg3 db "Enter the character :"
	str3len equ $-msg3
        msg4 db "Number of times the character has occurred :"
	str4len equ $-msg4

section .bss
	buff: resb 512
	fhandle: resq 1
	cntr: resw 1
	blankspa: resb 3
	lines: resb 3

section .text

global _start

	_start:
	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,0777O
	syscall

	mov [fhandle],rax

	mov rax,0
	mov rdi,[fhandle]
	mov rsi,buff
	mov rdx,512
	syscall	

	mov [cntr],ax
	mov cx,00H
	mov esi,buff
	mov bx,[cntr]
	mov dl,20H
again:		
		mov al,[esi]
		cmp al,dl
		jne noincre
		inc cx
noincre:	inc esi
		dec bx
		jnz again

	mov esi,blankspa 
	mov ax,cx 
	mov dl,10 
	div dl 
	movzx ax,al 
	add ax,30H 
	mov [esi],ax 
	inc esi 
	mov ax,cx 
	mov dl,10 
	div dl 
	mov bx,00H 
	mov bl,ah 
	mov ax,bx 
	add ax,30H 
	mov [esi],ax

	mov cx,00H
	mov esi,buff
	mov bx,[cntr]	
	mov dl,0AH
again1:		
		mov al,[esi]
		cmp al,dl
		jne noincre1
		inc cx
noincre1:	inc esi
		dec bx
		jnz again1
	
	mov esi,lines
	mov ax,cx 
	mov dl,10 
	div dl 
	movzx ax,al 
	add ax,30H 
	mov [esi],ax 
	inc esi 
	mov ax,cx 
	mov dl,10 
	div dl 
	mov bx,00H 
	mov bl,ah 
	mov ax,bx 
	add ax,30H 
	mov [esi],ax


mov rax,03H
mov rdi,[fhandle]
syscall
	
	mov rax,1               
	mov rdi,1
	mov rsi,msg1
	mov rdx,str1len
	syscall
	
	mov rax,1          
	mov rdi,1	
	mov rsi,blankspa
	mov rdx,2
	syscall

	mov rax,1               
	mov rdi,1
	mov rsi,msg2
	mov rdx,str2len
	syscall
	
	mov rax,1          
	mov rdi,1	
	mov rsi,lines
	mov rdx,2
	syscall

 

mov rax,60
mov rdi,0
syscall
 

