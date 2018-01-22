section .data

	msg1 db "Enter the First number",10
	len1 equ $-msg1

	msg2 db "Enter the Second number",10
	len2 equ $-msg2

	msg3 db "Invalid entry..Please enter again",10
	len3 equ $-msg3

section .bss
	num1: resb 3
	num2: resb 3
	num: resb 3
	res: resb 5
	ctr: resb 1
	ct: resb 1

section .text

global _start
_start:

begin:	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,len1
	syscall

	mov rax,0
	mov rdi,0
	mov rsi,num1								;Storing Entered number in entno
	mov rdx,3
	syscall

	dec al

	jz diserr
	cmp al,2								;Checking if Length > 1 
	ja diserr

	mov byte[ctr],al
	mov byte[ct],al							;ctr stores lenght of entered string		
	mov esi,num1								;esi->address of entno
	mov eax,0
	mov ebx,10H
			
loop:	mov ecx,0
	mov cl,[esi]								;cl contains beginning digit's ASCII 
	cmp cl,30H								;checking if cl is number
	jb diserr

	cmp cl,39H								;checking if cl is number
	jbe va
	
	cmp cl,41H
	jb diserr

	cmp cl,46H
	jbe va

diserr:	mov rax,1
	mov rdi,1
	mov rsi,msg3
	mov rdx,len3
	syscall
	jmp begin

va:	inc esi
	dec byte [ctr]
	jnz loop


begin1:	mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,len2
	syscall

	mov rax,0
	mov rdi,0
	mov rsi,num2								;Storing Entered number in entno
	mov rdx,3
	syscall

	dec al

	jz diser
	cmp al,2								;Checking if Length > 1 
	ja diser

	mov byte[ctr],al							;ctr stores lenght of entered string
	mov esi,num2								;esi->address of entno
	mov eax,0
	mov ebx,10H
			
loop2:	mov ecx,0
	mov cl,[esi]								;cl contains beginning digit's ASCII 
	cmp cl,30H								;checking if cl is number
	jb diser

	cmp cl,39H								;checking if cl is number
	jbe valid3
	
	cmp cl,41H
	jb diser

	cmp cl,46H
	jbe valid2

diser:	mov rax,1
	mov rdi,1
	mov rsi,msg3
	mov rdx,len3
	syscall
	jmp begin1

valid2:	sub cl,07H
valid3:	sub cl,30H								;cl contains actual number	
	mul ebx 								
	add eax,ecx
	mov byte[num2],al
	inc esi
	dec byte [ctr]
	jnz loop2

	mov byte[num],al

	mov esi,num1								;esi->address of entno
	mov eax,0
	mov ebx,10H
	
pck:	mov ecx,0
	mov cl,[esi]							;cl contains beginning digit's ASCII
	cmp cl,41H
	jb valid
	sub cl,07H
valid:	sub cl,30H
	mul ebx							;cl contains actual number							
	add eax,ecx
	inc esi
	dec byte [ct]
	jnz pck

	mov ebx,0
result:	add ebx,eax
	dec byte[num]
	jnz result

	mov eax,ebx
	mov esi,res
	mov cl,0
	mov ebx,10H


	loop1:	mov dx,0
		div bx
		push dx
		inc cl
		cmp ax,0
		ja loop1

	mov byte[ctr],cl

	lo:	pop dx
		cmp dl,10
		jb add30
		add dl,7H

		add30:	add dl,30H
			mov byte[esi],dl
			inc esi
			dec byte[ctr]
		 	jnz lo

	mov byte[esi],48H
	inc esi
	inc cl
	mov byte[esi],10
	inc cl

mov rax,1
mov rdi,1
mov rsi,res
mov dx,cx
syscall

mov rax,60
mov rdi,0
syscall

