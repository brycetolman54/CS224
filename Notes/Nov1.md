# Functions

- How do we pass arguments and return values
    - We pass arguments using the `%rdi, %rsi, %rdx, %r8, %r9, %r10` registers
        - If we have more than 6, we just put them on the stack
            - The Calling function puts them there, the Callee pulls them off with offsets
    - We return values from the function to the `%rax` register
        - We can only return one value that way
- What about using the stack for local storage?
    - We do this when we run out of registers
    - We do this when we pass address in our function (registers don't have addresses)
    - We do this when the variable is an array or struct
    - To do this, we just push and pop and keep track of the rsp
- What if our functions need to use registers that have values?
    - We have the registers pushed to memory, used, and then restored
    - Callee-registers = `%rbx, %rbp, %r12, %r13, %r14, %r15`
    - Caller-registers = all else (except for `%rsp`)
- Example of recursion:

In C:
```c
long rsum(long n) {
    if(n == 0) {
        return 0;
    }
    else {
        return n + rsum(n-1);
    }
}
```

In Assembly:
```asm

irmovq stack, %rsp

# set up param n
irmovq $0 %rdi

# set up a value for decrementing
irmovq $1, %r10

# call function
call rsum

halt


# define function
rsum:

# check if n == 0
andq %rdi, %rdi

# jump if not 0
jne recurse

# if n == 0
irmovq $0, %rax

ret

# else
recurse:

# add to sum
addq %rdi, %rax

# decrement
subq %r10, %rdi

# recurse
call rsum

ret


.pos 0x90
stack:

```
