// PRIORITY_QUEUES:

/* 
Priority Queues provide the functionality of a data structure that stores elements in accordance with the rules of a heap

Implemented as container adaptor (a class that uses another container class as its underlying container)
The underlying container class can be vector or deque (default is vector)

Does not support iterators

Supports default ctor, itr ctors, range-based ctors, and copy/move ctors (some are implicitly declared)
Supports copy/move assignment oprs (implicitly declared)

Access -> O(1)
Insert -> O(logn)
Delete -> O(logn)
Search -> N/A
*/ 

#include <queue>

std::priority_queue<value_type, container_type, value_compare> pqueue;