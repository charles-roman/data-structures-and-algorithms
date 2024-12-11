#ifndef PROJECT_DARRAY_HPP
#define PROJECT_DARRAY_HPP

#include <iostream>
#include <memory>

namespace crs {

template <class T>
class DArray {

    static const unsigned int sGrowthFactor{2};

    public:
        // Default Constructor
        DArray() = default;
        // Parameterized Constructor
        explicit DArray(size_t size); 

        // Copy Constructor (deep copy)
        DArray(const DArray& dArr);                     
        // Move Constructor
        DArray(DArray&& dArr) noexcept;                          

        // Destructor
        // ~DArray() = default;         // auto handled by RAII
        
        // Copy Operator (deep copy)
        DArray& operator=(const DArray& dArr);
        // Move Operator
        DArray& operator=(DArray&& dArr) noexcept;   

        T& operator[](size_t index);

        // Return number of elements in array
        size_t size() const;                            // O(1)
        // Return current storage capacity of array
        size_t capacity() const;                        // O(1)
        // Check if array is empty
        bool empty() const;                             // O(1)
        // Clear contents of array
        void clear();                                   // O(1)
        // Return value at specified index
        T& at(size_t index) const;                      // O(1)
        // Add element to back of array
        void push_back(const T&);                       // O(n), O(1) if array not full
        // Remove element from back of array
        void pop_back();                                // O(1)
        // Insert element at specified index
        void insert(size_t index, const T&);            // O(n), O(1) if inserting at end (and array not full)
        // Erase element at specified index
        void erase(size_t index);                       // O(n), O(1) if erasing at end
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