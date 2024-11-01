# The Stack

- Pop moves the stack top from the memory to the register, then moves down to the next part of the stack
- Push moves the pointer, then puts the thing from a register to memory

# Call and Ret

- We start at P, jump to Q, then return to P
- How do we deal with:
    - Passing control from P to Q:
        - We store the address of P on the stack (the return address)
            - This is call, we store the address of P then jump to Q
            - Then we ret, this jumps back to the address we put on the stack (and removes it)
            - The address we store is actually incremented from the call, to be at the place we need to continue from
