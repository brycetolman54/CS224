# More Signed Numbers

- When we convert between types, we can lose bits
    - If we go `int` to `char`, we lose the 3 most significant bytes
    - This is called truncation
- We can also go the other direction
    - If we go `char` to `int`, we have to add bytes
        - The low order bits stay the same
        - If the variable is unsigned, we fill in with 0s
        - If the variable is positive signed, we fill in with 0s
        - If the variable is negative signed, we fill in with 1s
            - The filled in bits are just an extension of the rightmost bit
            - This is what allows it to keep the same value
- We can change both sign and size:
    - We convert first size then sign

```C
short sx = 0xcfc7;
unsigned uy = sx; // that unsigned assumes int
printf("uy = %x", uy);
// prints out 0xffffcfc7
```

# Project 2

- We are going to run a filter on pictures to make the picture grey, then black
