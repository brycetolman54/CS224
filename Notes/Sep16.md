# More about memory in C

- Little endian stores the least significant at the lowest address
- Big endian stores the most significant at the highest address

- Hex and binary: there are 4 bits in each hexadecimal number, so two hexes go in a box since that is a whole byte (8 bits)

## Typecasting

- We just cast the pointer to be something else
- That doesn't change the value in the box, just the way the compiler interprets it
- Part of the reason we do this is to get the pointers to increment properly (if you add 1 to a char pointer, it goes up by one memory space, if you add 1 to an int pointer, it goes up by 4 memory spaces)

- You can `%s` to mean print a string in C, you pass it the char array
- 
