
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
      
	jmp here	
	mov rax,60
	mov rdi,0
	syscall


