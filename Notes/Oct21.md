# Working with the stack

- We can either `pushq` or `popq`
    - Pop puts something from memory to register, then increments the pointer
    - Push decrements the pointer, then puts something from register to memory
    - Push changes the memory, pop does not

```asm

; set the stack pointer at the address of stack (defined below to be 0x80)
irmovq stack, %rsp

; add value to register
irmovq $0x88, %rax

; push the value from the register to memory at the pointer of the stack
pushq %rax

; sets a position to start code at
.pos 0x80

; make a label at the current address
stack:
```

- We notice that the pointer starts at 80, then when we push the rax the pointer decrements to 70 and stores the value in rax at that address
    - It moves before it pushes

# Function-related instructions

- `call Dest`: jumps to the function we are calling (we can have that as a label) and pushes the address of the next instruction on the stack so it knows where to go after the function has run
- `ret`: pops the top of the stack to get back to the address where we left off before going to the function

```asm

; use that function
call fun

; do something else
irmovq $0x42, %rcx

; make a function (we define it later as a label to do stuff, fun: gets the address of memory at that location)
fun:
irmovq $-1, %rax
ret

```

# Other Assembly things

```asm

; we can align the constants (they aren't by default), in this case it is in an 8 byte window that these are aligned
.align 8

; make a sort of constant that the assembler stores in memory for us
.quad 0x42
.quad 0x64

```
