# Intro to C

- C is low level, to be better than assembly but still do system level programming
- We have the same data types: char (there is no string in C), int, short, long, float, double
- We have the same loops (if-else and while)
- Where is the difference?
    - Streams! You don't have the input and output streams
        - You don't use `cout << "hello"`
        - You use, `printf("hello")`
            - You can put %char in the string and then replace them with params at the end of the `printf` function
                - The types to put in %char are:
                    - c - char
                    - d - decimal
                    - s - string
                    - x - hexadecimal
                    - f - floating point
                    - l - double
        - You don't use `cin >> num`
        - You use `scanf("%char", &num)`
            - The & gives us the address, not the value
