// PRIORITY QUEUES:

/* Container adaptor that stores elements in accordance with the rules of a heap

    Implemented as container adaptor (a class that uses another container class as its underlying container)
    The underlying container class can be vector or deque (default is vector)
    Does not support iterators

    Access -> O(1)
    Insert/Delete -> O(logn)
    Search -> N/A
*/ 

#include <queue>

std::priority_queue<type> my_pq;	                                    // declare queue (as vector)
std::priority_queue<type, std::deque<type>> my_pq;                      // declare queue (as deque)
std::priority_queue<type, std::deque<type>, std::greater<type>> my_pq;  // declare queue (as deque) with reversed ordering
std::priority_queue<type> my_pq2 = my_pq;                               // copy queue

// Member Functions:
    // Capacity
    my_pq.empty();	    // checks if queue is empty
    my_pq.size();		// returns number of elements in queue 

    // Modifiers 
    my_pq.pop();		// removes element at front of queue and sorts underlying container
    my_pq.push();		// adds element and sorts underlying container
    my_pq.push_range(); // inserts range of elements and sorts underlying container
    my_pq.emplace();    // constructs element in place and sorts underlying container
    my_pq.swap();       // swaps the contents

    // Access
    my_pq.top();	    // returns first (next) element within queue