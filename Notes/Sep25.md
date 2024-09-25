# More on Signs

- You might want to use `char` instead of `int` when you know your ints aren't going to be that big and you want to save space

- To flip the sign, we flip all bits and then add 1:
    - -5 is 1011
    - 5 is 0101

- Do not mix signed and unsigned
    - This causes fun problems
    - The signed values become unsigned in this case
    - If we do have to mix, you can put a U at the end of the int
