# Unsigned Types

- These types can be unsigned:
    - char
    - short
    - int (this is just the size_t, also this is what just `unsigned` is)
    - long
- These can't be:
    - float
    - double
    - pointer

- Ranges for unsigned (from all 0 to all 1):
    - char: [0, 255]
    - short: [0, 65,535]
    - int: [0, 4,293,967,295]
    - long: [0, 18,446,744,073,709,551,615]
- We can store more with unsigned

# Signed Characters

- These are the default
- We can represent both positive and negative, but we lose some range
- How do we show that it is negative?
    - We could just make the first bit reflect the sign
        - This gives us two values for 0 (bad)
        - This is easy to do, just flip the first bit (good)
        - This doesn't allow us to do addition with the same circuits (bad)
    - We can do Two's complement (the first bit has negative its value)
        - So, the 1 in 1000 is negative 8 instead of 8 like usual
        - We don't have duplicate values (good)
        - Is it easy to negate?
            - We flip all the bits and add 1
        - We can use the same addition circuitry (good)

- Ranges for signed (we use half for positive and half for positive)
    - char: [-128, 127]
    - short: [-32,768, 32.767]
    - int: [-2,147,483,648, 2,147,483,647]
    - long: [-9,223,372,...]
