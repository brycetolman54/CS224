# Y86 Project

- How to know if we set the overflow flag
    - For either $t = a + b$ or $t = -a + b$
        - Pass in either $a$ for add or $-a$ for subtract
        - Set it if:
            - `(a<0) == (b<0) && (a<0) != (t<0)`
            - If we are adding two negatives and get a positive, or vice versa, we set the flag
- 
