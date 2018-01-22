section.data
arr db 10,15,64,8,2,0AH


section.text
global_start
_start:
mov bl,0
mov cl,0
mov esi,arr
loop1:
mov al,[esi]
mov dl,cl+1
cmp al,[esi+1]
jg exch
inc esi
inc cl
cmp cl,05
jz end

exch:
mov temp,al
mov al,[esi+1]
mov[esi+1],temp
next:
inc esi
inc cl
cmp cl,04
jnz loop1

mov cl,0
mov esi,arr

mov rax,0
mov rdi,0
mov rsi,temp
mov rdx,6
