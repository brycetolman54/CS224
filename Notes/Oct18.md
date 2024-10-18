# Assembly code

- Each instruction in assembly does one small thing to the register or memory

## Y86-64

- This is like a subset of the actual X86
- We only use `q-word` (8 byte things) in Y86
- The registers are just 8 byte values that are sort of short term memory
    - The first 8 names of them are historically named, then it just goes by number
    - These all are general purpose though, except for `%rsp`, which points to the top of the stack

### Operations

- `halt` - stop the processor
- `nop` - do nothing
- `rrmovq` - move from register to register
- `irmovq` - move from immediate to register
- `rmmovq` - move from register to memory
- `mrmovq` -  move from memory to register
- `cmov_` - conditional move
    - The _ can be e, ne, l, le, g, ge
- `addq` - do addition in ALU
- `subq` - do subtraction in ALU
- `andq` - do and in ALU
- `xorq` - do xor in ALU

- The flags are important in order to compare things (with ==, <=, and so on)

#### Some Examples

```asm

; move something into the registry (the $ means a value, the % means a register)
irmovq $0x42, %rax
irmovq $0x88, %rcx

; move something into the memory from the register
; the first arg is telling us to take that value at rax and move it to the memory of rcx (so memory 88)
; the () are like dereferencing the pointer that is rcx (so we interpret th 88 as an address and not a value)
rmmovq %rax, (%rcx)

; move something from register to regster (this copies the value in rax to rdx)
rrmovq %rax, %rdx

; add two registers (this stores in rcx, the second register provided)
addq %rax, %rcx

; subtract two registers (this can get a negative number and set a sign flag >> SF, which can only ever be set by ALU operations)
; it subtracts the first from the second
subq %rcx, %rax

; if we get a zero at any point, we set the ZF flag to 1
; we set the flags (SF, ZF, and OF [which is overflow]) after each ALU

```
