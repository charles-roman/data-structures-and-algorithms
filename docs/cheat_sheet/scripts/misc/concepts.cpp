// CONCEPTS
/*
    Concepts are a mechanism to place constraints on template type parameters
*/

// #include <concepts>

    // Standard Concepts (examples)
    std::integral           // Core Language Concept | specifies type is integral type
    std::floating_point     // Core Language Concept | specifies type is floating point type
    std::boolean-testable   // Comparison Concept | specifies type can be used in Boolean contexts
    std::moveable           // Object Concept | specifies object can be moved and swapped
    std::copyable           // Object Concept | specifiess object can be copied, moved, and swapped
                            // Callable Concept |
    
    // Custom Concepts (creation)
    template <typename T>                               // syntax
    concept MyConcept = /*requirements*/;

    template <typename T>                               // example
    concept IsIntegral = std::is_integral_v<T>;

    template <typename T>                               // syntax
    concept MyConcept = requires(T param, ..) {
        /*statement(s)*/
    };

    template <typename T>                               // example
    concept Multipliable = requires(T a, T b) {
        a * b;                                          // simple requirement : only checks syntax!
    };

    template <typename T>                               // example
    concept Multipliable = requires(T a, T b) {
        (a * b) != 0;
        requires (a * b) != 0;                          // nested requirement : checks condition
    };

    template <typename T>                               // example
    concept Multipliable = requires(T a, T b) {
        {a * b} noexcept -> std::convertible_to<int>;   // compound requirement : checks syntax and result requirement
    };                                                  // (noexcept is optional)

    // Constraints (application)
    template <typename T>                                                       // syntax 1
    requires /*concept-name*/<T>
    type my_function(type param) {}

    template </*concept-name*/ T>                                               // syntax 2
    type my_function(type param) {}
                                        
    /*concept-name*/ auto my_function(/*concept-name*/ auto param) {}           // syntax 3

    template <typename T>                                                       // syntax 4
    type my_function(type param) requires /*concept-name*/<T> {}
        
    template <typename T>                                                       // concept combination
    requires /*concept-name*/<T> && /*concept-name*/<T> || /*concept-name*/<T>
    type my_function(type param) {}

    /*concept-name*/ auto my_variable = my_function(arg);                       // variable constraint
