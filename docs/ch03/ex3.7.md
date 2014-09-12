##Exercise 3.7
>What would happen if you define the loop control variable in the previous
exercise as type char? Predict the results and then change your program
to use a char to see if you were right.

No different.

    auto& c : str

We use `auto` to let the compiler determine the type of `c`.
which in this case will be `char&`.
