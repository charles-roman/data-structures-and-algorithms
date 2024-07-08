// ITERATORS:

/* 
Iterators are a concept, not a concrete or abstract type,
but any type that obeys iterator like rules. They can be 
thought of as abstractions of a pointer. 

Iterators are primarily used to move through the contents of containers

The major advantages of using iterators are that they
    1) bring you closer to container independence
    2) allow for efficient dynamic processing of containers

Iterator Types:         
    Contiguous          ^
    Random Access       |
    Bidirectional       |   powerfulness
    Forward             |
    Output              |
    Input              ---

Iterators point to memory addresses inside a container (similar to a pointer).

DEPENDING ON THE TYPE of iterator, they can potentially be dereferenced, used 
with increment/decrement operators, arithmetic operators, or relational operators
for various purposes
*/

// #include <iterator>

// Declaration
std::container_type<type>::iterator it;   // declare iterator called it

// Dereference
*it;        // dereference iterator (same as pointer)
it->member; // accessing member element called "member" (same as pointer)
            // dereferenced iterator may be used as rvalue or lvalue depending on iterator type

// Iterator Operations
my_container.begin();   // returns an iterator pointing to first element in container
my_container.end();     // returns an iterator pointing to one past last element in container

std::advance(it,n);             // increments given iterator by n elements              
std::next(it,n);                // returns the nth successor of iterator
std::prev(it,n);                // returns the nth predecessor of iterator
std::inserter(my_container,it); // returns insert_iterator which can be used to insert elements
std::copy(s_it,e_it,d_it);      // copies elements in source range to destination range

