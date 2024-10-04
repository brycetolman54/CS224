# Shifting

- We can move bits around using >> # or << #, to shift that # of bits
- We truncate either end of the bits that we are moving
- If we are moving the bits to the right, we sign extend (0s if unsigned, 1s if signed and leftmost bit is 1 and 0s if leftmost bit is 0)

# Masking

- We can create a mask to extract numbers from what we already have
- The mask is still just ones or 0s
- We do bitwise operations between the mask and other bits to extract what we want

# Bitwise operations with masks

- We can make masks and use bitwise operations to change the original number
- If we want to set things as 1s, we set the mask to 1s and do an OR
- If we want to set things to 0, we set the mask to 0s and do an AND
- If we ant to keep things as they are, we can use 1s and AND or 0s and OR

## Examples

- We have the number `x = 0x87654321`
    - We want to keep only the least significant byte of that:
        - We do `x & 0xff` and get `0x00000021`
    - We want to set the least significant byte to 1s but leave the rest alone
        - We do `x | 0xff` and get `0x876543ff`
    - We want the complement of everything except for the last byte
        - We do `x ^ ~0xff` to get `0x789abc21`
            - That `^` is the exclusive or, which is EXOR, (only 1 if only one of the two is 1)`
            - That ~ flips the whole mask
                - It was 1111...0000, then it becomes 0000...1111
        - EXOR using all 1s makes the complement of a byte (it flips every bit)


