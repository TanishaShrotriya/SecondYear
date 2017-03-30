;Positive negative counter



section .data
 
arr dw 12H,0FFH,00,-21,54H,-10,000,265,076H,07654H
var db 0                        ;zero cnt

section .text

global _start
_start:

mov bl,0			;+ve counter
mov cl,0			;negative counter
mov dl,0			;array counter
mov esi,arr

again:
mov al,[esi]
add al,0
js neg
jz zero
inc bl
jmp next

neg:
inc cl
jmp next

zero:
mov al,[var]
add al,1
mov [var],al
next:
inc dl
add esi,2
cmp dl,10
jl again

mov al,[var]
mov rax,60
mov rdi,0
syscall
