#include <cstddef>

#ifndef PROJECT_SLIST_HPP
#define PROJECT_SLIST_HPP

namespace crs {

template <class T>
class Node {
    public:
        // Constructors
        Node() = default;
        Node(const T& value, Node<T>* node)
            : data(value), next(node) {}
        // ~Node() = default;

        // Accessors
        const T& get_data() const {return data;}
        Node<T>* get_next() const {return next;}
        // Modifiers
        void set_data(const T& value) {data = value;}
        void set_next(Node<T>* node) {next = node;}

    private:
        T data;
        Node<T>* next{nullptr};
};

template <class T>
class SList {
    public:
        // Constructor(s)
        SList() = default;
        SList(const SList&) = delete;
        SList& operator=(const SList&) = delete;
        // Destructor
        ~SList();

        // Return number of elements in list
        size_t size() const;                                    // (O(n))
        // Check if list is empty
        bool empty() const;                                     // (O(1))
        // Add element to front of list
        void push_front(const T& value);                        // (O(1))
        // Remove element from front of list
        void pop_front();                                       // (O(1))
        // Read element from front of list
        const T& front() const;                                 // (O(1))
        // Add element to back of list (non STL function)
        void push_back(const T& value);                         // (O(n)) (O(1) w tail)
        // Remove element from back of list (non STL function)
        void pop_back();                                        // (O(n))
        // Read element from back of list (non STL function)
        const T& back() const;                                  // (O(n)) (O(1) w tail)
        // Read value at location (non STL function)
        const T& value_at(int index) const;                     // (O(n))
        // Insert value after location
        void insert_after(int index, const T& value);           // (O(n))
        // Erase value after location
        void erase_after(int index);                            // (O(n))
        // Print list
        void print() const;

    private:
        Node<T>* head{nullptr};
        Node<T>* tail{nullptr};
};

} // namespace crs (c. roman [data] structures [library])

#include "slist.tpp"

#endif  // PROJECT_SLIST_HPP