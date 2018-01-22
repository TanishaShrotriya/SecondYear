
section .data
arr db 10,15,0FFH,0E2H,-21

section .bss

section .text
global _start
_start:
mov bl,0      ;positive counter
mov cl,0      ;negative counter
mov dl,0      ;counter of arr
mov esi,arr
again:
mov al,[esi]    ;ds:[esi]
add al,0
js negcntr
inc bl
jmp next
negcntr: inc cl
next: inc esi
      inc dl
      cmp dl,05
      jl again

mov rax,60
mov rdi,0
syscall

