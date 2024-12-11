#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace crs {

template <class T, class Container = std::vector<T>>
class Stack {

    public:
        // Default Constructor
        Stack() = default;

        // Destructor
        // ~Stack() = default;

        // Checks if stack is empty
        bool empty() const;             // O(1)
        // Returns number of elements
        size_t size() const;            // O(1)
        // Accesses top element
        const T& top() const;           // O(1)
        T& top();                   
        // Removes top element
        void pop();                     // O(1)
        // Inserts element at top
        void push(const T&);            // O(1)
        // Prints contents of stack
        void print() const;

    private:
        Container cont;

};

}   // namespace crs (c. roman [data] structures [library])

#include "stack.tpp"

#endif  // STACK_HPP