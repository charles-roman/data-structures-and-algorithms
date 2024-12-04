// VECTORS:

/* 
Vectors are dynamic arrays

Support random access iterators

Access/Modify -> O(1)
Insert/Delete -> O(n)
Search -> O(n)
*/

#include <vector>

std::vector<type> my_vec;	                        // declare vector (type can’t be changed after declaration)
std::vector<type> my_vec(size);	                    // declare with pre-allocated size
std::vector<type> my_vec(size, val1);	            // declare with pre-allocated size & initialize w/ some value
std::vector<type> my_vec({ val1, val2, val3...});   // declare and initialize with multiple values
std::vector<type> my_vec = {val1, val2, val3};      // alternate syntax
std::vector<type> my_vec(other_vec);                // initialize with another vector 
	
my_vec[idx];    // access value at index
	
// Member Functions

    operator=
    my_vec.assign(size,val);    // assigns new value to vector elements
    my_vec.assign_range();

    // Iterators
    my_vec.begin();     // returns an iterator pointing to first element in vec
    my_vec.cbegin();    // returns a const iterator pointing to firest element
    my_vec.end();       // returns an iterator pointing to one past last element in vec
    my_vec.cend();      // returns a const iterator pointing to one past last element
    my_vec.rbegin();
    my_vec.crbegin();
    my_vec.rend();
    my_vec.crend();

    // Capacity
	my_vec.size();		    // returns number of elements in vec
    my_vec.max_size();
	my_vec.capacity();	    // returns number of elements allocated to vec
    my_vec.empty();         // returns whether vec is empty
    my_vec.shrink_to_fit(); // reduces vec capacity to fit size (destroys elements beyond capacity)
    my_vec.reserve(n);      // requests vec capacity to be at least enough to contain n elements

    // Access
    operator[]
	my_vec.at(idx); // returns reference to element at idx (safer access method, throws error if idx out of bounds)
	my_vec.front(); // returns reference to first element of vector
	my_vec.back();  // returns reference to last element of vector
    my_vec.data();

    // Modifiers
    my_vec.resize(n);           // resizes vec so that it contains n elements
    my_vec.pop_back();	        // removes element from end of vector (no return value)
	my_vec.push_back(val);      // adds element to end of vector (temporary obj creation)
    my_vec.emplace_back(val);   // adds element to end of vector (direct obj creation)
    my_vec.append_range();
    my_vec.emplace(it,val);     // extends vector by placing new element at position (by construction)
    my_vec.insert(it,val);      // inserts new element(s) before specified position (by copy/move)
    my_vec.insert_range();
    my_vec.erase(it);           // removes elements from specified position/range
    my_vec.clear();             // removes all elements of vector
    my_vec.swap();
	