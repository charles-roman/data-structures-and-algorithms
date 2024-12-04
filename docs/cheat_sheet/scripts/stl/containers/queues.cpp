// QUEUES:

/* Container that stores elements in FIFO order

    Implemented as container adaptor (a class that uses another container class as its underlying container)
    The underlying container class can be deque or list (default is deque)
    Does not support iterators

    Access -> O(1)
    Insert/Delete -> O(1)
    Search -> O(n)
*/ 

#include <queue>

std::queue<type> my_queue;	                // declare queue (as deque)
std::queue<type, std::list<type>> my_queue; // declare queue (as list)
std::queue<type> my_queue2 = my_queue;      // copy queue

// Member Functions:
    // Capacity
    my_queue.empty();	    // checks if queue is empty
    my_queue.size();		// returns number of elements in queue 

    // Modifiers 
    my_queue.pop();		    // removes element at front of queue 
    my_queue.push();		// adds element at back of queue
    my_queue.push_range();  // inserts range of elements at end of queue
    my_queue.emplace();     // constructs element in place at end of queue
    my_queue.swap();        // swaps the contents

    // Access
    my_queue.front();	    // returns first (next) element within queue
    my_queue.back();        // returns last element in queue

