//TYPES
    // primitive data types
    int			    // 4 bytes
    float 			// (6 decimal precision, 4 bytes memory, runs slower)
    double 			// (15 decimal precision, 8 bytes memory, runs faster)
    char			// 1 byte
    wchar_t 		// (2 or 4 byte char instead of 1 byte) (primitive in C++ only)
    void            //
    bool			// 1 byte (primitive in C++ only)

    // derived data types
    function
    array
    pointer
    reference

    // (abstract) user defined data types
    class 			// (C++ only)		
    struct
    union
    enum
    enum class	    // (scoped enums in C++ only)
    typedef (int8_t, char16_t, uint32_t, etc.)

    // special (useful) types
    size_t          // (platform dependent size)
    std::string		// (size varies)
    std::nullptr_t  //
    
    // type modifiers
    signed/unsigned (int/uint)
    short/long, long long

    // type qualifiers
    const type my_variable;     // value cannot be changed after initialization
    constexpr type my_variable; // lets compiler evaluate value of var/func at compile time
    volatile type my_variable;  // tells compiler value of variable may change at any time...
                                // ...prevents optimizations and forces compiler to read back mem location
    restrict type my_variable;  // (C Only?)

    // storage class specifers
    auto type my_variable;      // let compiler deduce variable type (C++ only)
    register type my_variable;  //
    static type my_variable;	// (locally) declares var which holds value each invocation...
                                // ...(globally) dictates access control only in immediate script
    extern type my_variable;    // used to declare variable in one file but define it in another
    mutable type my_variable;
    thread_local type my_variable;

//DECLARE/INITIALIZE
    type my_variable;	       // declare
    const type MY_VARIABLE;	   // declare constant
    type my_variable = value;  // initialize
    type my_variable{value};   // initialize (alternate syntax)

//LITERALS (apply to all standard types)
    int my_int = 0X1A;              // int literals can be written in several number systems (bin, hex, oct, etc.)
    float my_float = 0.0f;          // f to specify float
    double my_double = 0.0ULL;      // ints and floating point nums can have opt type modifiers (ULL = unsigned long long)
    bool my_bool = true/false;      // true/false keyword for boolean literals
    int* my_int_ptr = nullptr/NULL; // nullptr keywords for unintialized ptrs

//CASTING
    my_var2 = (char)my_var1; // explicit conversions (less dangerous than implicit)
    my_var3 = (int)my_var2;	 // char to int gives number of character location (ASC-II)

    /*--------------------------------------------*/// (C++ only)
    var = static_cast<type>(var);                   // simple compile-time cast
    ptr = reinterpret_cast<type*>(ptr);             // used to convert ptr of some type to ptr of another type
    ptr = dynamic_cast<BaseClass*>(&DerivedClass);  // run-time cast (Upcast or Downcast)
    ptr = const_cast<type*>(ptr); 		            // used to remove const-ness of any object (ptr is of same type)
