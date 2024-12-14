// STACKS:

/* Data structure that stores elements in LIFO order

    Implemented as container adaptor (a class that uses another container class as its underlying container)
    The underlying container class can be vector, deque, or list (default is deque)
    Does not support iterators

    Access -> O(1)
    Insert/Delete -> O(1)
    Search -> N/A
*/  

#include <stack>

std::stack<type> my_stack;				        // declare stack (as deque)
std::stack<type, std::vector<type>> my_stack;   // declare stack (as vector)
std::stack<type> my_stack2(my_stack);           // initialize stack (using ctor)                                  
std::stack<type> my_stack2 = my_stack;          // initialize stack (using opr)

// Member Functions:
    // Capacity
    my_stack.empty();	    // returns true if no elements
    my_stack.size();	    // returns number of elements in stack

    // Modifiers
    my_stack.pop();		    // removes last item added to top of stack 
    my_stack.push();	    // adds element to top of stack
    my_stack.push_range();  // inserts a range of elements at the top
    my_stack.emplace();     // constructs element in place at the top
    my_stack.swap();        // swaps the contents 

    // Element Access
    my_stack.top();		    // returns element on top of stack

