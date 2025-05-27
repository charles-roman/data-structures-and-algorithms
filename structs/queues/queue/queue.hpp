#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

namespace crs {

template <class T, class Container = std::deque<T>>
class Queue {
    public:
        // Default Constructor
        Queue() = default;

        // Destructor
        // ~Queue() = default;

        // Checks if queue is empty
        bool empty() const;                     // O(1)
        // Returns number of elements
        size_t size() const;                    // O(1)
        // Accesses element at front of queue   
        const T& front() const;                 // O(1)
        T& front();
        // Accesses element at back of queue
        const T& back() const;                  // O(1)
        T& back();
        // Inserts element at back of queue
        void push(const T&);                    // O(1)
        // Removes element from front of queue
        void pop();                             // O(1)
        // Print elements from queue
        void print() const;

    private:
        Container cont;
};

}   // namespace crs (c. roman [data] structures [library])

#include "queue.tpp"

#endif  // QUEUE_HPP