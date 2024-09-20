# Binary Math

- It works just like decimal addition...
- Multiplication and division by the base:
    - Multiplying by 2 in binary is just shifting everything to the left and putting 0 on the right
        - We can do a bit shift with << in C (a << 2 moves the bits 2 to the right)
    - Division by 2 in binary is just shifting everything to the right (we lose the 0.5)
        - We do this with a bit shift again (a >> 3 moves the bits 3 to the left)
    - This is just like multiplying/dividing by 10 in decimal
    - The computer can bit shift faster than it multiplies, so use that for multiplying/dividing by the base

