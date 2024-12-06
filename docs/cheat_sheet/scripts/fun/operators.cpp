// OPERATORS:

    // Increment/Decrement Operators
    ++my_var/--my_var       // pre-increment/decrement
    my_var++/my_var--       // post-increment/decrement

    // Arithmetic Operators
    +, -, *, /, %

    // Relational/Comparison Operators
    ==, !=, >, <, >=, <=

    // Logical/Boolean Operators
    &&, ||, !

    // Assignment/Compound Operators
    =, +=, -=, *=, /=, %=

    // Bitwise Operators
    &           // bitwise AND operator
    |           // bitwise OR operator
    ^           // bitwise XOR operator
    ~           // bitwsie Complement operator
    >>/<<       // bitwise Shift operators (right/left)

    // Other Operators
    sizeof()    // sizeof operator: returns size (in bytes) of input
    ? :         // ternary operator
    &           // address operator: fetches address of data
                // (ALSO) "reference" operator: assign token as ref
    .           // dot operator
    ->          // 
    <</>>       // streaming operators (input/output) (C++ Only)
    
    //
    Priority 	    Symbol
    1		     ++,  --,  ()
    2		     !, (typecast)
    3		     *,  /,  %
    4		     +,  -
    5		     <, <=, >, >=
    6		     ==, !=
    7		     &&
    8		     ||
    9		     all assignment operators (=, +=, etc.)