# Assembly to Machine

- Here are the codes to do different things:

```asm
# rbx would be 3, rax would be 0
rrmovq rA, rB       (2 0 rA rB)
rrmovq %rbx, %rcx   (2 0 3 1)

# the f is used to say we aren't really using a register
irmovq V, rB        (3 0 F rB V)
irmovq $15, %rxb    (3 0 F 3 0F00000000000000)

rmmovq rA, D(rB)    (4 0 rA rB D)
mrmovq D(rB), rA    (5 0 rA rB D)

# the fn is just the condition with which we do something
jXX Dest            (7 fn Dest)
cmovXX rA, rB       (2 fn rA rB)

call Dest           (8 0 Dest)
ret                 (9 0)

pushq rA            (A 0 rA F)
pop rA              (B 0 rA F)

halt                (0 0)
nop                 (1 0)
```
