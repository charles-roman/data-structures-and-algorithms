// POINTERS:

    /* A pointer is a special type of variable that stores the memory address of a regular variable.
    It can store the address of any variable type (including other pointers). The address stored
    is the address of the first byte of memory that stores a variable. Pointers are dangerous, be
    cautious not to silently overwrite memory values in your program. */

    type* my_ptr;   // pointer declaration
    type *my_ptr;   // alternate syntax
    type * my_ptr;  // alternate syntax
                    // uninitialized pointer declaration is dangerous!
                    // current address is NOT a valid location and can cause issues if referenced

    type my_var;
    type* my_ptr = &my_var;     // creating a pointer and assigning variable address 
                                // (& = address-of operator, obtains address)
                                //  ptr stores memory address of variable (as hexadecimal)
                                //  ptr address can change but type must be consistent w/ variable type

    type my_var = *my_ptr;	    // assign data stored in memory pointed to by my_ptr
                                // (* = dereference operator, accesses data at address)

    my_ptr += n;    // incrementing my_ptr to store address n <data type> sizes away
    my_ptr -= n;	// decrementing "..."                                                                           
                    // ptrs can only do addition/subtraction with int (i.e. n = integer)
                    // must be careful not to increment/decrement ptr beyond the bounds of memory space
    
    type *my_ptr = NULL; 	    // initialize null pointer (C)
    type *my_ptr = nullptr;	    // initialize null pointer (C++) 
                                // preferred to just declaring ptr which gives indeterminate value
                                // still dangerous, my_ptr points to "nowhere", can still cause issues if referenced

    const type* my_ptr = &my_var;       // pointer to const int (my_var doesn't have to be const, but CAN be; can't modify my_var through ptr)
    type const* my_ptr = &my_var;       // alternate syntax
    const type* const my_ptr = &my_var; // const pointer to const int (my_ptr is const, my_var CAN be const; still can't modify my_var through ptr)
    type const* const my_ptr = &my_var; // alternate syntax

>-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------
    // Smart Pointers:   (#include <memory.h>)
    /* Class that manages pointers through RAII, allows for auto freeing and for pointers to be exception safe */

    std::unique_ptr<type>    // does not share ownership, will free resource at end of scope (eos)
    std::shared_ptr<type>	 // shares ownership, frees resource if no other owners counted at eos
    std::weak_ptr<type>	     // used with shared ptr, does not add to reference counter
    auto ptr = std::make_unique<type>(args);	// function to create unique pointer
    auto ptr = std::make_shared<type>(args);	// function to create shared pointer

// REFERENCES:

    /* References are aliases for other variables that can modify the data of the variable being referred to.
    They will inherit the same address as the variable they refer to. They can store a reference to any variable
    type (including other references). They can be thought of as const pointers (less dangerous than actual pointers) */

    type &my_var1 = my_var2;    // assigning a reference, my_var is an alias for my_var2 and cannot be reassigned
    type& my_var1 = my_var2;    // alternate syntax
    type & my_var1 = my_var2;   // alternate syntax
                                // (& = reference operator, establishes my_var as ref for my_var2)

    type&& my_var = 0;          // rvalue reference         

    my_var1 = my_var3;          // modifying a reference (my_var) will modify the target (my_var2) as well

    const &my_var1 = my_var2;               // const ref, can't modify original variable through ref
    type my_function(type const &my_var)    // const ref = computational efficiency w/out modifying data
    {
        return 0;
    }
-----------------------------------------------------EXCLUSIVE_TO_C++----------------------------------------------------------<

    /* Pointers vs References
        pointers:
        1) must go through dereference operator to read/write through pointed to value
        2) can be chnaged to point elsewhere
        3) can be declared unitialized (w/ garbage address)

        references:
        1) doesn't use dereferencing for read/write
        2) can't be changed to reference something else
        3) must be initialized on declaration
    /*

// MEMORY:

   /* program memory is generally organized into a few main categories: text, data, bss, heap, and stack
      two of primary importance in C/C++ programming are the stack and heap

        o	stack: highly ordered section of memory stored in a LIFO structure (used as scratch spaced for thread execution)
        o	heap: relatively unordered section of memory used for dynamic allocation

    Stack vs Heap
        stack:
        1) variables created on stack are automatically deallocated when they go out of scope
        2) much faster to allocate memory compared to heap
        3) data created on stack can be used with/without pointers
        4) typically has a max size determined when program starts
        5) each thread gets its own stack (stack frame)
        6) risk of stack overflow causing program to crash (typically caused by heavy recursion or enormous allocations)
        7) best to use stack if you know exactly how much data you need to allocate before compile time (and it is not too large!)

            Stores local data, return addresses, used for parameter passing

        heap:
        1) variables allocated on heap must be destroyed manually and never fall out of scope (otherwise there will be a memory leak)
        2) slower to allocate memory compared to stack
        3) data created on heap will be pointed to by pointers
        4) memory can be added to heap by OS if required
        5) typically only one heap is shared by an application (even multi-threaded apps)
        6) risk of fragmentation with a lot of allocations/deallocations
           risk of heap overflow (typically caused from memory leak or enormous allocations)
        7) best to use heap if you don't know exactly how much data you will need at run time or if you need to allocate a lot of data

    Storage
        Text: stores executable instructions from program to be run
        Data: contains all initialized global and static variables
        BSS: contains all uninitialized global and static variables
        Stack: stores all local (automatic) variables
        Heap: stores all user allocated data
    */

    // Dynamic Memory Allocation/Deallocation

        // C (#include <stdlib.h>)
        type *ptr = (type*) malloc(size);	        // reserve as many bytes as desired on heap
        type *ptr = (type*) calloc(n,size);	        // reserve contiguous memory for n elements of any data type
        type *ptr = (type*) realloc(ptr,size);	    // expand/contract block of reserved memory
        free(ptr);		                            // release previously allocated memory
        
        // C++
        type *ptr = new type;           // dynamically allocate memory
        type *ptr = new type(value);    // allocate and initialize (NOTE: need constructor for user-defined data)
        delete ptr;                     // delete memory
        ptr = nullptr;                  // good practice to reset memory to nullptr after releasing it
                                        // also good practice to check for valid address (i.e. not null) before using ptr

        type *array_ptr = new type[size]{values};   // create dynamic array (different from standard array! some array operations won't work!)
        delete[] array_ptr;                         // delete dynamic array
        array_ptr = nullptr;                        // reset dynamic array ptr

        type *ptr = new(std::nothrow) type{};       // std::nothrow returns a nullptr instead of throwing exception

    

