section.text:

global _start

_start:

mov al,02
mov bl,03
add al,bl
mov rax,61
mov rdi,0
syscall
