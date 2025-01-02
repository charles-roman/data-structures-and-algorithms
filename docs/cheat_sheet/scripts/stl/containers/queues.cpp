// QUEUES:

/* 
Queues provide the functionality of a FIFO data structure

Implemented as container adaptor (a class that uses another container class as its underlying container)
The underlying container class can be deque or list (default is deque)

Does not support iterators

Supports default ctor, itr ctors, range-based ctors, and copy/move ctors (some are implicitly declared)
Supports copy/move assignment oprs (implicitly declared)

Access -> O(1)
Insert -> O(1)
Delete -> O(1)
Search -> N/A
*/ 

#include <queue>

std::queue<value_type, container_type> queue; 