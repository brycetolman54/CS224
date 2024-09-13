# Memory in C

- Bytes for memory, each is 8 bits
- We number the memory of the computer form 0 and go on in hexadecimal
- Memory for each type:
    - `char` - 1 byte
    - `int` - 4 bytes
    - `short` - 2 bytes
    - `long` - 4 or 8 bytes
    - `float` - 4 bytes
    - `double` - 8 bytes
    - `pointer` - 4 or 8 bytes
- Arrays in memory are just consecutive memory things, the space after the last element is a null (a byte of 0)
- For multibyte types, the address is the lowest part of it
    - The least significant byte is stored in the lowest address
        - e.g. 10.0234 stores 34 in the lowest address (but this would actually need to be in hexadecimal)
- An array is stored with the address at the first element
- We can type cast pointers, the address stays the same but the computer interprets the memory there in a different way

# Project 1: myxxd

- We can check if something is a printable char using `isprint(char)`
    - We include that with "ctype.h"
- To print a hexadecimal, we use `%x`, we can use `%02x` to print leading 0 (the 0 means print it, the 2 means make the output 2 digits)
- 
