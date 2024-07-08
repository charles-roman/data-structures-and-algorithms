// TEMPLATES

    // Functions
    /* A function template is a tool that allows the addition of data types as parameters.
       The compiler uses the template as a blueprint to generate instructions for a function (template instances).

        Templates are created entirely in header files 
        Templates allow selection of type implementation (both I/O) when called
        Templates will generally slow down compile time but speed up execution time
        Templates serve to eliminate the need to overload a function repetitively, however they can be overloaded as well!
    */

        // Defining
        template <typename T>                       // function template syntax (T = typeidentifier)
        T my_function(T param1, T param2) {         // function with same parameter and return type "T"
            /* function def */
        }

        template <class T>                          // use of 'class' or 'typename' is arbitrary
        template <class T1, class T2>               // multiple type identifiers are permitted

        const T& my_function(const T& param) {}     // can use references as always in function signature

        template <>                                 // template specialization (for specific inputs)
        const char* my_function<const char*> (const char* param) {
            /* function def */
        }

        // Calling
        my_function (arg1, arg2);                   // template type deduction (compiler deduces type based on arg(s))
        my_function <type> (arg1, arg2);            // explicit type arg (allows implicit conversion of args)
        my_function <type1, type2> (arg1, arg2);    // must use multiple type params for templates w/ multiple identifiers

    // Classes
    /* Class templates are classes defined along with a generic type that can be applied throughout the class definition

        Templates are typically defined in header files, 
        but member functions are implemented in .tpp files (with .hpp files included at the end)
    */

        template <class typeidentifier> class MyClass {     // class template 
            // class def		                               
        };							

        MyClass <type> myObject(params);			        // instantiation


        
         
