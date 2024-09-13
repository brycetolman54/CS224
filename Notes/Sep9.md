# More about C

- When we pass an arg into a function, if we want to actually change the value of that arg, we use the `&arg` to pass by reference (its address) and let the function actually change the value of that arg
    - We use this with `scanf("%type", &arg)` to actually read the input into that variable
