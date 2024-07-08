// FUNCTIONS:

    // Declaring/Defining
    type my_function(type param1, type param2) 	        // function signature

    type my_function(type param1, type param2);	        // prototype/declaration (typically found in header files)

    type my_function(type param1, type param2=val) {    // function definition (default arguments for parameters are optional)
        /*actions*/
        return /*output*/;
    }

    void my_function(void) {	                        // fxn def w/ no input or return (optional to specify void input)
        return;                                      
    }

    // Input Parameters
    type my_function(type param) {/*function def*/}         // pass by value                                                         
    
    type my_function(type *param) {/*function def*/}        // pass by pointer                                                           
                                                             
    type my_function(type &param) {/*function def*/}        // pass by reference (use const ref to avoid data manipulation)

    type my_function(type my_array[]) {/*function def*/}    // passing arrays by value will decay to pointers (my_array[] = *my_array)
                                                            // (can avoid by passing by ref)

    // Function Specifiers
    inline type my_function() {}        // instructs compiler to isnert fxn body where called; can be beneficial for speed (sometimes)
    virtual type my_function() {}       // declares member function as virtual, allowing it to be overriden in derived classes
    type my_function() override {}      // specifies that a member function is intended to override a base class function
    virtual type my_function() final {} // prevents a virtual function from being overridden in derived classes
    explicit my_function() {}           // specifies that a constructor or conversion operator should not be implicitly invoked
    static type my_function() {}        // specifies that a member fxn doesn't operate on instance of class & can be called w/out obj
    constexpr type my_function() {}     // indicates that the func can produce a constant expression & can be evaluated @ compile time
    friend type my_function() {}        // allows a non-member function to access the private and protected members of the class

    // Passing Arguments
    my_function(arg1, arg2);                    // passing args to function
    my_variable = my_function(*arg1, &arg2);    // passing args and storing result in variable
                                                // args passed to func can be literals, variables, pointers, addresses, references, etc.

    // Passing Arguments
    /* 
        By Value:
            1) copies of arguments passed are made and stored in params
            2) generally runs slower for complex objects but faster for simple objects (ie primitive types) (overhead is copying)
            3) values of args CANNOT be modified 

       By Pointer:
            1) no copies of arguments need to be made (memory efficient)
            2) generally runs faster for complex objects but slower for simple objects (overhead is dereferencing)
            3) values of args CAN be modified

       By Reference:
            1) no copies of arguments need to be made (memory efficient)
            2) generally runs faster for complex objects but slower for simple objects (overhead is accessing)
            3) values of args CAN be modified
        
        Ptr vs Ref
            both are similar with similar computational efficiency
            generally passing by ref is more straightforward and preferred
            however passing by ptr can be useful in situations where it is useful to pass a NULL arg
    */

    // Returning Values
    /*
        It is okay to return a ref or ptr from a func if neccesary
        If return val could be NULL or will be dynamic memory address, better to use ptr (specifically smart pointer in C++)
        Otherwise it is generally more common to return a ref
        Returning a ref can be useful to avoid copying of more complex objects
        However, generally won't serve much purpose due to Copy Elision
        CAREFUL not to return a reference to a local variable (because it goes out of scope)
    */
