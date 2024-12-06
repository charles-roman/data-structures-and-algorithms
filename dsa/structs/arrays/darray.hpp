#ifndef PROJECT_DARRAY_HPP
#define PROJECT_DARRAY_HPP

#include <iostream>
#include <memory>

namespace crs {

template <class T>
class DArray {

    static const int sGrowthFactor{2};

    public:
        // Constructors
        DArray() = default;
        explicit DArray(int size);

        // ~DArray() = default;
        
        // Operators
        T& operator[](int index);

        // Return number of elements in array
        size_t size() const;                            // O(1)
        // Return current storage capacity of array
        size_t capacity() const;                        // O(1)
        // Check if array is empty
        bool empty() const;                             // O(1)
        // Return value at specified index
        T& at(int index) const;                         // O(1)
        // Add element to back of array
        void push_back(const T&);                       // O(n), O(1) if array not full
        // Remove element from back of array
        void pop_back();                                // O(1)
        // Insert element at specified index
        void insert(int index, const T&);               // O(n), O(1) if inserting at end (and array not full)
        // Erase element at specified index
        void erase(int index);                          // O(n), O(1) if erasing at end
        // Reduces capacity to equal size of array
        void shrink_to_fit();                           // O(n)
        // Print elements in array
        void print() const;

    private:
        std::unique_ptr<T[]> pArr;
        size_t mSize{0};
        size_t mCapacity{0};

        // Upsize array so it can store more elements
        void upsize();
};

}   // namespace crs (c. roman [data] structures [library])

#include "darray.tpp"

#endif  // PROJECT_DARRAY_HPP