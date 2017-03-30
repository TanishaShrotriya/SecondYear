section .data

	msg1 db "Error",10
	msglen1 equ $-msg1
	fname db "file.txt",0
        space db 0
	ent   db 0
	char  db 0
	temp  db 0

section .bss

	fhandle : resq 1	
	buff    : resb 512
	len     : resw 1

section .text

global _start:
_start:
    

	mov rax,02
	mov rdi,fname
	mov rsi,02
	mov rdx,07770
	syscall


;----------------------------------------------------reading file-------------------------------------------------------------------------------	
	jns working
      	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,msg1
	mov rdx,msglen1
        syscall		

	working:
	mov [fhandle],rax

	mov rax,0
	mov rdi,fhandle
	mov rsi,buff
	mov rdx,512
	syscall

	mov [len],ax
	mov rdi,fhandle
	syscall
	mov rax,03
;-----------------------------------------------checking for special char------------------------------------------------------------------------------	
	mov esi,buff
	mov ax,[len]
        
loop :
        mov bx,[esi]
	cmp bx,20H
	je space_
	cmp bx,10H
	je enter_
	cmp bx,41H	
	inc byte[char]
	jmp check
	space_:
            inc byte[space]
	    jmp check
	enter_:
	    inc byte[ent]
	    jmp check
	check:
	inc esi
	dec byte[len]	
	jnz loop

;---------------------------------------------packing number-----------------------------------------------------------------------------------------------
 
	mov ax,[space]
	cmp ax, 9H
        ja alpha
	add ax,30H

	alpha:
 		add ax,37H
 	
	mov [space],ax
;--------------------------- 
	mov ax,[char]
	cmp ax, 9H
        ja alpha1
	add ax,30H

	alpha1:
 		add ax,37H
 	
	mov [char],ax
;--------------------------
	mov ax,[ent]
	cmp ax, 9H
        ja alpha2
	add ax,30H

	alpha2:
 		add ax,37H
 	
	mov  [ent],ax	 
;--------------------------------------------display result-------------------------------------------------------------------------------------------------


	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,space
	mov rdx,1
        syscall	
	
	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,ent
	mov rdx,1
        syscall	
	
	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,char
	mov rdx,1
        syscall	
	
        mov rax,60
	mov rdi,0
	syscall
