# X86

- We can have different sizes of things (other than just quad words)
    - 1 byte (b)
    - 2 bytes (w)
    - 4 bytes (l)
    - 8 bytes (q)
- We have different sizes of registers 
    - This doesn't mean that we have more registers, we just can store different size things as needed
    - This allows us to improve efficiency with hardware and such
    - Here are the sizes: %rxx(x)
        - 1 byte (b)
        - 2 bytes (w)
        - 4 bytes (d)
        - 8 bytes (-)
- For operands:
    - We can now pass memory address in addition to values (That is why we have to use $ for values)
