section .data
	
	msg1 db "Hello, enter BCD",10
	msglen1 equ $-msg1
	msg2 db "You have entered",32
        msglen2 equ $-msg2
	msg3 db "Now enter the offset length",10
        msglen3 equ $-msg3
	num   dw  0H
	base  dw  10

section .bss
        
	bcd1   : resb 25	;string for user input
	len1   : resb 1		        
	bcd2   : resw 25	;actual bcd storage location
	len2   : resb 1
	hex    : resw 1		;i/p or operand
	hex_str: resw 2 	;resultant string o/p
	len    : resb 1	

section .text

	global _start:
	_start:
;--------------------------------------------------ACCEPT DISPLAY BCD1------------------------------------------------------------

	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,msg1
	mov rdx,msglen1
        syscall

	mov rax,0		;take user input
	mov rdi,0
	mov rsi,bcd1
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
	mov rsi,bcd1
	mov rdx,[len1]
        inc rdx			;to include 0AH
        syscall
      
;---------------------------------------------------------------------------------------------------------------------------------------

	mov dx,4                ;!!!!!!cx value won't change thus replaced with dx
	mov ax,0
	mov esi,bcd1
	loop:
		mov bl,[esi]
		sub bl,30H
		shl ax,4
		mov bh,0 	;explicitly needed to make bx =0n where n is value of bl
		add ax,bx	; option to this is movzx bx,bl
		inc esi
		dec dx
		jnz loop

;-------------------------------------------------------------------------ax holds bcd value---------------------------------------------
	
	mov cl,12		; must be cl or immediate operand for shr 
	mov [bcd2],ax
	mov bx,0F000H
	mov ch,4
	;mov ax,0
	loop1:
		mov dx,[bcd2]
		and dx,bx
		shr dx,cl
		mov ax,[num]
		mul word[base]
		add ax,dx        ; !!!!!!!ax won't get added        
		mov [num],ax
		shr bx,4
		sub cl,4
		dec ch
		jnz loop1

;-----------------------------------------------------------------converted to binary format----------------------------------------------------------------
;---------------------------------------------------------------------------------------------------------------------------------------------------------

	mov cl,12
	mov ch,04
	mov bx,0F000H
	mov esi,hex_str
	loop3:
		mov ax,[num]
		and ax,bx
		shr ax,cl
		cmp al,09
		ja add_37	;jump if above compared value
		add al,30H
		jmp store
	add_37:
		add al,37H
	store:
		mov [esi],al
		inc esi
		sub ch,04
		shr bx,04
		dec ch
		jnz loop3	
;-----------------------------------------------------------------Stored as HEX in hex_str------------------------------------------------------------
        
	
	mov rax,1		;display entered string
	mov rdi,1
	mov rsi,hex_str
 	mov rdx,4
	syscall
        
	mov rax,60
	mov rdi,0
	syscall





