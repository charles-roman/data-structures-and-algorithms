// STACKS:

/* 
Stacks provide the functionality of a LIFO data structure

Implemented as container adaptor (a class that uses another container class as its underlying container)
The underlying container class can be vector, deque, or list (default is deque)

Does not support iterators

Supports default ctor, itr ctors, range-based ctors, and copy/move ctors (some are implicitly declared)
Supports copy/move assignment oprs (implicitly declared)

Access -> O(1)
Insert -> O(1)
Delete -> O(1)
Search -> N/A
*/  

#include <stack>

std::stack<value_type, container_type> stack;