;input and concatenate strings
;Program in x86/64 ALP to perform non-overlapped and over-lapped block transfer.
;a) Define block in data segment
;b) Display the output to the user

%macro print 2
	mov rax,1		;display message to monitor
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
        syscall
%endmacro

%macro input 2
	mov rax,0		;take user input
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro		

section .data
	 
        msg0 db 0AH,"Hello , choose operation :", 0AH,"0.Give string input",0AH,"1.Non-overlapped", 0AH ,"2.Overlap",0AH,"3.Exit",0AH 
	msglen0 equ $-msg0
	msg1 db 0AH,"Enter string",10
	msglen1 equ $-msg1
        msg2 db 0AH,"You have entered",32
        msglen2 equ $-msg2
	msg3 db 0AH,"Now enter the offset length",10
        msglen3 equ $-msg3
	msg4 db 0AH,"Incorrect Choice",10
        msglen4 equ $-msg4
        msg5 db 0AH,"Do you wish to continue?",10
        msglen5 equ $-msg5
        msg6 db 0AH
        msglen6 equ $-msg6

section .bss

        str0   : resb 2         ;to store choice of user        
        s0       equ $-str0 
	str1   : resb 50	;max length is 25bytes
	l1       equ $-str1	;to store number of bytes reserved, incase we change them in the future      
	len1   : resb 1         ; to store actual string length
        str2   : resb 50
	l2       equ $-str2
        len2   : resb 1 
	offset : resb 1		;actual integer variable
	temp   : resb 3
	len    : resb 1
	str3   : resb 100	;resultant string
	len3   : resb 1	

section .text

	global _start:
	_start:

;-------------------------------------------------DISPLAY MENU ---------------------------------------------------------------------

 	menu: 

        	print msg0,msglen0
        	input str0,s0

        	cmp byte[str0],30H
        	je takeIn
        	cmp byte[str0],31H
        	je nonOverlapped
        	cmp byte[str0],32H
       		je overlap
   		cmp byte[str0],33H
		je exit
        	jmp error
        
;--------------------------------------------------ACCEPT DISPLAY STRING1------------------------------------------------------------
	
 	takeIn:
		 
        		print msg1,msglen1
       			input str1,l1 
                        
                        dec al
			mov [len1],al		;store length of entered string - 0AH 
                       
        		print msg2,msglen2
        		print str1,l1 
			 


;--------------------------------------------------ACCEPT DISPLAY STRING2------------------------------------------------------------

                        print msg1,msglen1 
       			input str2,l2
	                
                        dec al
			mov [len2],al		;store length of entered string - 0AH 

        		print msg2,msglen2
         		print str2,l2 
                      
                        jmp menu

;--------------------------------------------------------------------------------------------------------------------------------------

        nonOverlapped:               
                        
                        mov al,[len1]
                        mov [offset],al 
                        jmp concatenate
			

;----------------------------------------------ACCEPT OFFSET----------------------------------------------------------------------------

        overlap:  

   		print msg3,msglen3 
       		input temp,3

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


;-----------------------------------------------CONCATENATE AFTER OFFSET------------------------------------------------------------------------------

		concatenate:

			mov cl,[offset]
			mov esi,str1	;address of str1 to esi
			mov edi,str3	;address of str3 to edi	
		        mov bl,0  
                     	
			for:            ;copy till index of str1!=offset
			  mov al,[esi]
			  mov [edi],al
			  inc esi
			  inc edi
                          inc bl
			  dec cl
			  jnz for
	
		       	mov esi,str2     ; copy string two whole
	                mov cl,[len2]

			while:
			  mov al,[esi]
			  mov [edi],al
			  inc esi
			  inc edi
                          inc bl
			  dec cl
			  jnz while  		
		  	 
                          mov cl,[offset]
			  mov [len3],cl
                          mov cl,[len2]
                          add [len3],cl

                          print str3,[len3]
                          print msg6,msglen6 
                         
                          print msg5,msglen5 
       			  input str0,s0

			  cmp byte[str0],31H
			  je menu
			  jmp exit
			
;----------------------------------------------------------------------------------------------------------------------

;--------------------------------------incorrect choice----------------------------------------------------------------
        error :
	        mov rax,1		;display message to monitor
		mov rdi,1
		mov rsi,msg4
		mov rdx,msglen4
	        syscall
	        jmp menu
	 	
        exit :

		mov rax,60
		mov rdi,0
		syscall


