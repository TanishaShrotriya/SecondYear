;hex to bcd

section .data	
	msg1 db "Hello, enter Hex",10
	msglen1 equ $-msg1
	msg2 db "You have entered",10
        msglen2 equ $-msg2
	msg3 db "Now enter the offset length",10
        msglen3 equ $-msg3
	num   dw  0H
	base  dw  10

section .bss
        
	hex1   : resb 25	;string for user input
	len1   : resb 1	
	hex2   : resb 25	        
	bcd    : resw 1		;i/p or operand
	bcd_str: resw 2 	;resultant string o/p
	len    : resb 1	

section .text

	global _start:
	_start:
;--------------------------------------------------ACCEPT DISPLAY HEX------------------------------------------------------------

	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,msg1
	mov rdx,msglen1
        syscall

	mov rax,0		;take user input
	mov rdi,0
	mov rsi,hex1
	mov rdx,25
        syscall
        	
	dec al	
        mov [len1],al		;store length of entered string 

	mov rax,1
	mov rdi,1
	mov rsi,msg2		;display msg2
	mov rdx,msglen2
        syscall

	mov rax,1		;display entered string
	mov rdi,1
	mov rsi,hex1
	mov rdx,[len1]
        inc rdx			;to include 0AH
        syscall
      	
;-----------------------------------------------------------------convert to number format from ascii-------------------------------------------------------
;---------------------------------------------------------------------------------------------------------------------------------------------------------
	mov ch,04
        mov esi,hex1
	loop3:
		mov al,[esi]
		cmp al,39H
		jb  sub_30H	;jump if above compared value
		sub al,07H
       sub_30H: sub al,30H
		mov [esi],al
		inc esi
		dec ch
		jnz loop3	

;-----------------------------------------------------------convert to decimal---------------------------------------------------------------------------
;---------------------------------------------------------------------------------------------------------------------------------------------------------
	mov cl,4
	mov ax,0
	mov esi,hex1
	mov bh,0
	loop:
                shl ax,04
		mov bx,[esi]
		add ax,bx        
		inc esi		
		dec cl
		jnz loop
;-----------------------------------------------------------mod base -push remainder --------------------------------------------------------------------
;---------------------------------------------------------------------------------------------------------------------------------------------------------
        mov bx,10
        mov [bcd],ax

	loop1:	
		div bx
		push dx
                cmp ax,0
		ja loop1
	
	mov esi,hex2

	loop2:
		pop dx
		add dx,30H
		mov byte[esi],dl
		inc esi
		jnz loop2
        
	mov rax,1		;display entered string
	mov rdi,1
	mov rsi,hex2
	mov rdx,4
        syscall
      	
        mov rax,60
	mov rdi,0
	syscall
