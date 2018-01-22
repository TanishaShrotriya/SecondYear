;Positive negative counter

%macro display 2

mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall

%endmacro


%macro input 2

mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall

%endmacro

section .data 
 
	arr   dw 12H,0FFH,00,-21,54H,-10,000,265,076H,07654H
	zero  db 0H              ;zero cnt
	pos_  db 0H              ;positive counter     
        neg_  db 0H              ;negative counter
        len   db 0H              ;for length of res

section .bss 

        res :resb 3
         
 
section .text

global _start
_start:

mov dl,0			;array counter
mov esi,arr

again:
	mov al,[esi]
	add al,0
	js neg
	jz zero_
	inc byte[pos_]
	jmp next

neg:
	inc byte[neg_]
	jmp next

zero_:
	inc byte[zero]
next:
	inc dl
	add esi,2              ; because arr is in dw size
	cmp dl,10
	jl again

;mov al,[neg_]
;call pack
;mov al,[pos_]
;call pack
mov al,[zero]
call pack


mov rax,60
mov rdi,0
syscall

pack:

        mov dx,0
   	mov cl,0
        mov bl,10 
        mov edi,res
	push_:
  		div bl
  	        push dx
   		inc cl
   		cmp al,0
                jnz push_
   
	pop_:
     		pop dx
   		add dx,30H
   		mov [edi],dx
   		inc edi 
   		dec cl
   		cmp cl,0
   		jnz pop_

;		mov esi,[res]
;	countBytes:
;		inc cl
 ;               inc esi
;		cmp esi,edi
;		jnz countBytes
        
        mov byte[len],1
	display res,[len]

ret
