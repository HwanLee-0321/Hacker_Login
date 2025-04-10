## Q1. 다음 어셈블리 코드를 실행했을 때 출력되는 결과로 올바른 것은?

### [Assembly Code]
```asm
main:
    push rbp
    mov rbp, rsp
    mov esi, 0xf                  ; write 길이: 15 byte
    mov rdi, 0x400500             ; 출력할 문자열 주소
    call 0x400497 <write_n>
    mov eax, 0x0
    pop rbp
    ret

write_n:
    push rbp
    mov rbp, rsp
    mov QWORD PTR [rbp-0x8], rdi  ; 문자열 주소 저장
    mov DWORD PTR [rbp-0xc], esi  ; 길이 저장
    xor rdx, rdx
    mov edx, DWORD PTR [rbp-0xc]  ; edx = length
    mov rsi, QWORD PTR [rbp-0x8]  ; rsi = buffer address
    mov rdi, 0x1                  ; rdi = STDOUT (fd = 1)
    mov rax, 0x1                  ; syscall number (write)
    syscall
    pop rbp
    ret
```

### [Memory Content at Address 0x400500]
```
0x400500 | 0x3037207964343372
0x400508 | 0x003f367562336420
```

### [해석 과정]
메모리는 리틀 엔디안 방식으로 저장되어 있으므로, 각 8바이트는 역순으로 읽어야 함:

- 0x400500: `0x3037207964343372` → `72 33 34 64 79 20 37 30` → ASCII: `r34dy 70`
- 0x400508: `0x003f367562336420` → `20 64 33 62 75 36 3f 00` → ASCII: ` d3bu6?\0`

따라서, 총 15바이트는 다음과 같다:
```
r34dy 70 d3bu6?
```

### [정답]
**r34dy 70 d3bu6?**

