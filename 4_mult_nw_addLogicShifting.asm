section .data
	
	msg1 db "Enter hex multiplicand",10
	msglen1 equ $-msg1
	msg2 db "Enter the multiplier",10
        msglen2 equ $-msg2
	msg3 db "Incorrect input!!"
 	msglen3 equ $-msg3
	flag_Ml  db  0H
	sum_     dw  0H
section .bss
        
	Md     : resb 10	;multiplicand
	l_Md   : resb 1		        
	Ml     : resb 10	;multiplier string
	l_Ml   : resb 1
	ml     : resb 1         ;actual multiplier	 	
	sum    : resb 10        ; resultant
section .text

	global _start:
	_start:
;----------------------------------------------------INPUT----------------------------------------------------------------------------------------------------
;--------------------------------------------------------------------------------------------------------------------------------------------------------------
	Md_accept:

		mov rax,1		;display message to monitor
		mov rdi,1
		mov rsi,msg1
		mov rdx,msglen1
        	syscall	
	
		mov rax,0		;take user input for multiplicand
		mov rdi,0
		mov rsi,Md
		mov rdx,10
        	syscall
        	
		dec al	
        	mov [l_Md],al		;store length of entered string 

;-------------------------------------------------------------CHECK NUMBER OF DIGITS---------------------------------------------------------------------------
        	cmp al,2
		ja invalid

;--------------------------------------------------------------------------------------------------------------------------------------------------------------		
	Ml_accept:
		mov rax,1		;display message to monitor
		mov rdi,1
		mov rsi,msg2
		mov rdx,msglen2
        	syscall	
	
                cmp byte[flag_Ml],0
		ja if
		mov rax,0		;take user input for multiplier
		mov rdi,0
		mov rsi,Ml
		mov rdx,10
        	syscall

        	mov byte[flag_Ml],1
		
		dec al	
        	mov [l_Ml],al		;store length of entered string 

;-------------------------------------------------------------CHECK NUMBER OF DIGITS---------------------------------------------------------------------------
        	cmp al,2
		ja invalid2
	
;-------------------------------------------------------------PACKING WITH VALIDATION--------------------------------------------------------------------------

	mov ch,[l_Md]
        mov esi,Md

	if:
		mov al,[esi]
		cmp al,30H
		jb  invalid
		cmp al,39H
		jb  sub_30H	;jump if below compared value
		cmp al,40H
		jb invalid
		cmp al,46H
		ja invalid
		sub al,07H

        sub_30H: 
		sub al,30H
 		mov [esi],al
		inc esi
		dec ch
		jnz if	
	cmp byte[flag_Ml],2
	je mul

	mov ch,[l_Ml]
        mov esi,Ml
        mov byte[flag_Ml],2
	jmp if
	
	invalid :
		mov rax,1		;display message to monitor
		mov rdi,1
		mov rsi,msg3
		mov rdx,msglen3
        	syscall	
		jmp Md_accept

	invalid2 :
		mov rax,1		;display message to monitor
		mov rdi,1
		mov rsi,msg3
		mov rdx,msglen3
        	syscall
		mov byte[flag_Ml],0			
		jmp Ml_accept
;-------------------------------------------------------------PERFORM MULTIPLICATION---------------------------------------------------------------------------
	
	mul:
	mov ax,0
	mov byte[sum],0
        mov ax,[Ml]
	mov bx,[Md]

	for:
        	add [sum_],ax
		dec bx	
        	jnz for
;--------------------------------------------------------------PACK RESULT TO HEX------------------------------------------------------------------------------

	mov cl,12
	mov ch,2
	mov bx,0F000H
	mov esi,sum_
	loop3:
		mov ax,[esi]
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
		sub cl,04
		shr bx,04
		dec ch
		jnz loop3	
;--------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	mov rax,1		;display sum
	mov rdi,1
	mov rsi,sum_
	mov rdx,2
        syscall
	
	mov rax,60
	mov rdi,0
	syscall


