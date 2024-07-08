// NAMESPACES:

/* Namespaces define the space or context in which identifiers (i.e. variable, function, class)
   are defined to avoid naming collisions 

    namespace declarations only appear at global scope
    namespace declarations can be nested within another namespace
    namespace definition can be split over several units (important!)
*/

    // Define
    namespace my_namespace              // define namespace
    {
        type my_variable;

        type my_function(type param) {
            /*function def*/
        }

        class MyClass {
            /*class def*/
        };
    }

    namespace my_namespace              // extending definition (NOT new namespace)
    {
        class MyNewClass {
            /*class def*/
        };
    }

    namespace                           // unnamed (anonymous) namespace
    {
        type my_variable;
    }                                   // ... used for creating unique identifiers for a given translation unit
                                        // ... (superior replacement for static variables/functions; also allow for classes)
                                        // ... compiler generates unique name for namespace

    // Access
    my_namespace::my_variable;          // scope resolution operator to access identifiers in namespace
    my_namespace::my_function(arg);
    my_namespace::MyClass myObject;

    // Using Directive
    using namespace my_namespace;       // tells compiler following code is using specified namespace (Dangerous!)
    using my_namespace::my_variable;    // using my_variable from specified namespace

    // Aliasing
    namespace my_ns = my_namespace;     // my_ns now refers to my_namespace

    // Inline Namespaces
    namespace my_namespace1
    {
        inline namespace my_namespace2  // inline allows identifiers of nested namespace to belong to parent/enclosing namespace     
        {
            type my_variable;
        }
    }