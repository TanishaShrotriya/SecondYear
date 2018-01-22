
;implement os commands of type, copy,delete 
;uses only two buffers , can work with one buff too

%macro display 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro input 2
mov rax,00
mov rdi,00
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro fopen 1
mov rax,02
mov rdi,%1
mov rsi,02
mov rdx,0777o
syscall
%endmacro

%macro fread 3
mov rax,0
mov rdi,%1     ;file handle
mov rsi,%2     ;buff
mov rdx,%3     ;buff_len 
syscall
%endmacro

%macro fwrite 3
mov rax,1      
mov rdi,%1     ;filehandle
mov rsi,%2     ;buff
mov rdx,%3     ;buff_len
syscall 
%endmacro

%macro fclose 1
mov rax,03
mov rdi,%1
syscall
%endmacro

%macro ShowContents 4                ;fname,fhandle,buff,blen,flen

	fread %1,%2,%3    ; store contents to variable buff1
        mov %4,ax
        mov byte[%2 + rax - 1],0AH
	display %2,%4    

%endmacro


section .data
	
	fname2 db "b1.txt",00H
	msg1 db "1.Type",0AH,"2.Copy",0AH,"3.Delete",0AH,"4.Exit",0AH
	msg1len equ $-msg1
	msg2 db "Enter the type command",0AH
	msg2len equ $-msg2
	msg3 db "Enter the copy command",0AH
	msg3len equ $-msg3
	msg4 db "File copied",0AH
	msg4len equ $-msg4
	msg5 db "Enter the delete command",0AH
	msg5len equ $-msg5
	msg6 db "File deleted",0AH
	msg6len equ $-msg6
        msg7 db "Error in opening file",0AH
        msg7len equ $-msg7
        msg8 db "No such command exists",0AH
        msg8len equ $-msg8
        msg9 db "File not present,nothing to delete",0AH
        msg9len equ $-msg9

        type db "type "    
        typelen equ $-type
        Copy db "copy "    
        copylen equ $-Copy
        Del db "delete "    
        delLen equ $-Del
 
section .bss
	
        fname1 : resb 20 
	choice : resb 2
	  str1 : resb 20
       str1len : resb 1	
	 buff1 : resb 512
	 blen1   equ $-buff1       ;note: blen1 cannot exceed 512 bytes!!
	 buff2 : resb 1024
	 blen2   equ $-buff2
         flen1 : resb 1
      fhandle1 : resq 1
      fhandle2 : resq 1


section .text

global _start
_start:

menu:
	display msg1,msg1len
	input choice,2
	
	mov esi,choice
	mov al,[esi]
	cmp al,31H     ; works as a switch case, according to msg1
	je open        ; label open
	cmp al,32H
	je copy        ; label copy
	cmp al,33H
	je delete      ; label delete
	cmp al,34H
	je exit        ; label exit


;-------------------------------------------------**TYPE**-----------------------------------------------------

open:
	display msg2,msg2len
	input str1,20

	mov esi,str1
	mov edi,type	
        mov bl,typelen 
        call verifyCommand
      
        mov edi,fname1
      
  
        loop:                 ;copy one string to another
		mov al,[esi]
		cmp al,0ah
		je opn

		mov [edi],al
		inc esi
		inc edi
		jmp loop
		
		opn:
			mov byte[edi],0
        fopen fname1
        cmp rax,-1H                     ; if negative implies file does not exist
        jle error
	mov [fhandle1],rax              ; rax stores int value that holds the ID of file, which is dq in size
        ShowContents [fhandle1],buff1,blen1,[flen1]
        fclose fhandle1
        jmp menu
        error:
               display msg7,msg7len
               jmp menu

;--------------------------------------------------**COPY**----------------------------------------------------
copy:

	display msg3,msg3len
	input str1,20

;---------------------------exactly same as type for f1--------------------------------------------------           

	mov esi,str1
	mov edi,Copy	
        mov bl,copylen 
        call verifyCommand

        mov edi,fname1
loop1:
	mov al,[esi]
	cmp al,20H        ; to check for space and know its the end of file1
	je next

	mov [edi],al
	inc esi
	inc edi
	jmp loop1
;------------------------------------same as type for f2----------------------------------------------------------
next:
	mov byte[edi],0
	inc esi            ; after the space we get file2 name 
	mov edi,fname2
loop2:	
	mov al,[esi]
	cmp al,0AH         ; we check for enter to know end of name file2
	je cpy

	mov [edi],al
	inc esi
	inc edi
	jmp loop2

cpy:
	mov byte[edi],0

;---------------- copy contents of file1 to buff1 -----------------------

        
	fopen fname1
        cmp rax,-1H                     ; if negative implies file does not exist
        jle error
	mov [fhandle1],rax
	fread [fhandle1],buff1,blen1
        dec rax
        mov [flen1],rax
	fclose fhandle1

;--------------- operations on file 2 ---------------------------------
	
        ;-------------  display initial contents of file2 ---------------------------
        fopen fname2 
        cmp rax,-1H                     ; if negative implies file does not exist
        jle error
	mov [fhandle2],rax              ; rax stores int value that holds the ID of file, which is dq in size
        ShowContents [fhandle2],buff2,blen2,[flen1]
        
        ;------------  paste contents from buff1 to file2  -----------------------

	fwrite [fhandle2],buff1,[flen1]    ; write from buff1 to file	
	

;------------display final contents of file2-------------------------------------

        ShowContents [fhandle2],buff2,blen2,[flen1]
        fclose fhandle2
        display msg4,msg4len

	jmp menu

;-----------------------------------------**DELETE**-----------------------------------------------------------
delete:

	display msg5,msg5len
	input str1,20

	mov esi,str1
	mov edi,Del	
        mov bl,delLen 
        call verifyCommand

        mov edi,fname1
  
loop3:                    ; copy str1 to fname1
	mov al,[esi]
	cmp al,0ah
	je del

	mov [edi],al
	inc esi
	inc edi
	jmp loop3

        del:
	fopen fname1
        cmp rax,-1H                     ; if negative implies file does not exist
        jle notPresent
	
	mov byte[edi],0

	mov rax,87
	mov rdi,fname1
	syscall

	display msg6,msg6len
        jmp menu

notPresent:
     
	display msg9,msg9len
        jmp menu
;--------------------------------------------------------------------------------------------------------------
exit:
 mov rax,60
 mov rdi,0
 syscall

verifyCommand:
   
 check:
       mov al,[esi]
       cmp al,[edi]
       jne Error
       inc edi
       inc esi
       dec bl
       jnz check
       je done
 Error:
      display msg8,msg8len
      jmp menu
 done:

ret
