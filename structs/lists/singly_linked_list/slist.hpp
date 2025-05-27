#ifndef SLIST_HPP
#define SLIST_HPP

#include <cstddef>

namespace crs {

template <class T>
class SList {
    public:
        // Constructors
        SList(); // = default; not working properly?
        explicit SList(size_t count);
        SList(size_t count, const T& value);

        // Destructor
        ~SList();                                                                    

        // Copy Constructor (deep copy)
        SList(const SList& other);
        // Move Constructor
        SList(SList&& other);

        // Copy Assignment Operator (deep copy)
        SList& operator=(const SList& other);
        // Move Assignment Operator
        SList& operator=(SList&& other) noexcept;

        // Check if list is empty
        bool empty() const;                                     // O(1)
        // Return number of elements in list (non STL function)
        size_t size() const;                                    // O(n)                   

        // Read element from front of list
        const T& front() const;                                 // O(1)
        T& front();
        // Read element from back of list (non STL function)
        const T& back() const;                                  // O(n) (O(1) w tail)
        T& back();
        // Read value at location (non STL function)
        const T& at(size_t index) const;                        // O(n)                 

        // Clear contents of list
        void clear();                                           // O(n)                     
        // Add element to front of list
        void push_front(const T& value);                        // O(1)
        // Remove element from front of list
        void pop_front();                                       // O(1)
        // Add element to back of list (non STL function)
        void push_back(const T& value);                         // O(n) (O(1) w tail)
        // Remove element from back of list (non STL function)
        void pop_back();                                        // O(n)
        // Insert value after location
        void insert_after(size_t index, const T& value);        // O(n) (using itr instead of index -> O(1))
        // Erase value after location
        void erase_after(size_t index);                         // O(n) (using itr instead of index -> O(1))

        // Reverses order of list
        void reverse();                                         // O(n)
        // merge    

        // Print list
        void print() const;

    private:
        struct Node {
            // Constructors
            Node() = default;
            Node(const T& value, Node* node = nullptr)
                : data(value), next(node) {}
        
            // Destructor
            // ~Node() = default;

            T data;
            Node* next;
        };

        Node* head;  // head (and tail) ptr can optionally be replaced with a sentinel
        Node* tail;  // tail ptr optional but allows quick access to end of list     
};

} // namespace crs (c. roman [data] structures [library])

#include "slist.tpp"

#endif  // SLIST_HPP