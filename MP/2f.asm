;input and concatenate strings


section .data
	
	msg1 db "Hello, enter string",10
	msglen1 equ $-msg1
	msg2 db "You have entered",32
        msglen2 equ $-msg2
	msg3 db "Now enter the offset length",10
        msglen3 equ $-msg3
section .bss
        
	str1   : resb 25	;max length is 25bytes
	len1   : resb 1		;the actual length of string        
	str2   : resb 25
	len2   : resb 1
	offset : resb 1		;actual integer variable
	temp   : resb 3
	len    : resb 1
	str3   : resb 50	;resultant string
	len3   : resb 1	

section .text

	global _start:
	_start:
;--------------------------------------------------ACCEPT DISPLAY STRING1------------------------------------------------------------
here:	
        mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,msg1
	mov rdx,msglen1
        syscall

	mov rax,0		;take user input
	mov rdi,0
	mov rsi,str1
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
	mov rsi,str1
	mov rdx,[len1]
        inc rdx			;to include 0AH
        syscall
      
;---------------------------------------------------------------------------------------------------------------------------------------

;--------------------------------------------------ACCEPT DISPLAY STRING2------------------------------------------------------------
	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,msg1
	mov rdx,msglen1
        syscall

	mov rax,0		;take user input
	mov rdi,0
	mov rsi,str2
	mov rdx,25
        syscall
        	
	dec al	
        mov [len2],al		;store length of entered string 

	mov rax,1
	mov rdi,1
	mov rsi,msg2		;display msg2
	mov rdx,msglen2
        syscall

	mov rax,1		;display entered string
	mov rdi,1
	mov rsi,str2
	mov rdx,[len2]
        inc rdx			;to include 0AH
        syscall
      
;---------------------------------------------------------------------------------------------------------------------------------------

;----------------------------------------------ACCEPT OFFSET----------------------------------------------------------------------------

	mov rax,1
	mov rdi,1
	mov rsi,msg3		;display msg3
	mov rdx,msglen3
        syscall

	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,3
	syscall
	
	dec al
	mov [len],al

	cmp al,01		;one-digit number
	jmp oneDigit

	mov al,[temp]		;for two-digit number
	sub al,30H
	mov bl,[temp+1]		;base-displacement addressing
	sub bl,30H

	mov cl,10
	mul cl			;rangle of al=10-90
	add al,bl		;as ah=0
	mov [offset],al
	jmp concatenate

	oneDigit:
		mov al,[temp]
		sub al,30H
		mov [offset],al
;--------------------------------------------------------------------------------------------------------------------------------------------	

;--------------------------------------CONCATENATE AFTER OFFSET------------------------------------------------------------------------------

        concatenate:
		mov cl,[offset]
		mov esi,str1	;address of str1 to esi
		mov edi,str3	;address of str3 to edi	
		mov bl,0
		for:           ;copy till index of str1!=offset

		  mov al,[esi]
		  mov [edi],al
		  inc esi
		  inc edi
		  inc bl
		  dec cl
		  jnz for
		
		mov esi,str2
		
		while:
		  mov al,[esi]
		  mov [edi],al
		  inc bl
		  cmp al,0AH
		  jz display
		  inc esi
		  inc edi
		  jmp while

		display:  		
	  	
		  mov [len3],bl
		  mov rax,1		;display entered string
		  mov rdi,1
		  mov rsi,str3
		  mov rdx,[len3]
	          inc rdx			;to include 0AH
	          syscall
	jmp here	
	mov rax,60
	mov rdi,0
	syscall


