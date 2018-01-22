section .data
	msg db "ENTER THE DECIMAL NUMBER",0AH
	msglen equ $ -msg
	num db 0
	base dw 10


section .bss
	temp  :resb 5
	bcdno :resw 1
	hexno:resw 1
	hexstr:resb 4
	hex   :resw 1
	



section .text
global _start
_start:
;------------------------ACCEPT AND DISPLAY------------------
	mov rax,1
	mov rdi,1
	mov rsi,msg
	mov rdx,msglen
 	syscall


	mov rax,0
	mov rdi,0
	mov rsi,temp
	mov rdx,5
 	syscall
;--------------------PACKING OF NUMBER---------------------------
	mov cl,4
	mov ax,0
	mov bh,0
	mov esi,temp
  loop:
	mov bl,[esi]
	sub bl,30H
	shl ax,4
	add ax,bx
	inc esi
	dec cl
	jnz loop


;----------------convert to hex-------------------------
	mov [bcdno],ax
	mov cl,12
	mov bx,0F000H
	mov ch,4
	

 loop1:
	mov dx,[bcdno]
	AND dx,bx
	shr dx,cl
	mov ax,[num]
	mul word[base]
	add ax,dx
	mov [num],ax
	shr bx,4
	sub cl,4
	dec ch
	jnz loop1



;------------display hexadecimal number-------------------

	mov [hexno],ax
	mov cl,12
	mov ch,4
	mov bx,0F000H
	mov esi,hexstr
 again:
	mov ax,[hexno]
	AND ax,bx
	shr ax,cl
	cmp al,09
	ja add37
	add al,30H
	
	jmp store
 add37: 
	add al,37H
	
 store:
	mov [esi],al
	inc esi
	sub cl,04
	shr bx,04
	dec ch
	jnz again

 display:
	
	mov rax,1
	mov rdi,1
	mov rsi,hexstr
	mov rdx,4
	syscall



	mov rax,60
	mov rdi,0
	syscall







	
