#ifndef PROJECT_PQUEUE_HPP
#define PROJECT_PQUEUE_HPP

#include <vector>

namespace crs {

template <class T, class Container = std::vector<T>, class Compare = std::less<T>>
class PQueue {
    public:
        // Constructor
        PQueue() = default;

        // Destructor
        // ~PQueue() = default;

        // Return number of elements in queue
        size_t size() const;                                       // O(1)
        // Check if queue is empty
        bool empty() const;                                        // O(1)
        // Return key of first element in queue
        const T& top() const;                                      // O(1)
        T& top();
        // Remove first element in queue
        void pop();                                                // O(logn)
        // Insert new element into queue
        void push(const T &obj);                                   // O(logn)
        // Remove element from queue (non STL function)
            // void remove(const T &obj);                          // O(logn)
        // Increase key of element from queue (non STL function)          
            // void increase(const T &val);                        // O(logn)
        // Print queue 
        void print() const;               

    private:
        Container cont;
        Compare comp = Compare();

        size_t parent(const size_t i) const;
        size_t left(const size_t i) const;
        size_t right(const size_t i) const;
        void heapify_down(const size_t i);                         // O(logn)
        void heapify_up(size_t i);                                 // O(logn)
};

} // namespace crs (c. roman [data] structures [library])

#include "pqueue.tpp"

#endif  // PROJECT_PQUEUE_HPP