// HashMap class using iterators and linked buckets for efficient iteration-------------------------------------------------

#ifndef ARCH_HPP
#define ARCH_HPP

#include <functional>

namespace crs {

template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>>
class HashMap { // std::unordered_multimap
    public:
        // Forward Declarations
        class MapIterator;

        // Aliases
        typedef MapIterator Iterator;
        typedef std::pair<const Key, T> value_type;

        // Constructors
        HashMap();
        explicit HashMap(size_t count);

        // Destructor
        ~HashMap();

        // Copy Constructor (deep copy)
        HashMap(const HashMap& other);                                          // Needs adjustment                
        // Move Constructor
        HashMap(HashMap&& other) noexcept;                                      

        // Copy Assignment Operator (deep copy)
        HashMap& operator=(const HashMap& other);                               // Needs adjustment
        // Move Assignment Operator
        HashMap& operator=(HashMap&& other) noexcept;                           // Needs adjustment

        // Returns pointer to first element
        Iterator begin() const;                                                 // O(1)
        // Returns pointer to last element
        Iterator end() const;                                                   // O(1)

        // Checks whether map is empty
        bool empty() const;                                                     // O(1)
        // Returns number of elements in map
        size_t size() const;                                                    // O(1)

        // Clears contents of map
        void clear() noexcept;                                                  // Needs adjustment // O(n)
        // Inserts element to map
        Iterator insert(const value_type& value);                               // Needs adjustment // O(n) (O(1) on avg)
        // Removes element from map and returns next element
        Iterator erase(Iterator it);                                            // Needs adjustment // O(n) (O(1) on avg); using a doubly-linked list would make this O(1) worst case    
        // Erases elements with specific key from map and returns count
        size_t erase(const Key& key);                                           // Needs adjustmnet // O(n) (O(key_count) on avg)

        // Returns number of elements matching key
        size_t count(const Key& key) const;                                     // Needs adjustment // O(n) (O(key_count) on avg)
        // Finds element with specific key
        Iterator find(const Key& key);                                          // Needs adjustment // O(n) (O(1) on avg)
        // Checks if map contains element with specific key
        bool contains(const Key& key) const;                                    // Needs adjustment // O(n) (O(1) on avg)

        // Returns number of buckets in map
        size_t bucket_count() const;                                            // O(1)
        // Returns number of elements in specific bucket
        size_t bucket_size(size_t bucket) const;                                // Needs adjustment // O(n) (O(1) on avg)?
        // Returns bucket for specific key
        size_t bucket(const Key& key) const;                                    // O(1)

        // Returns load factor (avg number of elements per bucket)
        float load_factor() const;                                              // O(1)
        // Gets maximum load factor
        float max_load_factor() const;                                          // O(1)
        // Sets maximum load factor
        void max_load_factor(float ml);                                         // O(1) (could restrict this to be positive)
        // Reserves specified number of buckets and regenerates map
        void rehash(size_t count);                                              // Needs adjustment // O(n + m) (linking lists from separate buckets can improve to O(n))
                                                                                // (m = current bucket count, n = # of elements)
        // void reserve (size_t size); 

        // Returns function used to hash keys 
        Hash hash_function() const;                                             // O(1)
        // Returns function used to compare keys
        KeyEqual key_eq() const;                                                // O(1)

        // Print elements in map
        void print() const;                                                     // Needs adjustment

    private:
        size_t hash_value(const Key& key, size_t count = bucket_count()) const; // O(1)

        class Node;
        static const size_t INV_GOLDEN_RATIO;
        Iterator begin_;
        Iterator end_;  // this is effectively always a nullptr since it points to one after last element
        size_t size_;
        size_t bucket_count_;   // class uses a bucket count that is a power of 2 (instead of a prime)
        float max_load_factor_;
        Hash hash_function_;                
        KeyEqual key_eq_;                   
        Node** bucket_arr_;

        class Node {
            friend class MapIterator;

            public:
                // Constructors
                Node() = default;
                Node(const value_type& value, Node* node = nullptr)
                    : data(value), next(node) {}

                // Destructor
                // ~Node() = default;

                value_type data;

            private:
                Node* next;
        };

    public:
        class MapIterator {
            public:
                // constructors
                MapIterator() : node_(nullptr) {} 
                MapIterator(Node* node) : node_(node) {}

                // Destructor
                // ~MapIterator() = default; 

                // dereference
                value_type& operator*() const noexcept {
                    return node_->data;
                }

                // member access
                value_type* operator->() const noexcept {
                    return &node_->data;
                }

                // pre-increment
                Iterator& operator++() {
                    node_ = node_->next;
                    return *this;
                } 

                // post-increment
                Iterator operator++(int) {
                    Iterator temp(*this);
                    node_ = node_->next;
                    return temp;
                } 

                // equality comparison
                bool operator==(const Iterator& other) const {
                    return (node_ == other.node_);
                }  

                // inequality comparison
                bool operator!=(const Iterator& other) const {
                    return (node_ != other.node_);
                }  

            private:
                Node* node_;
        };
};

}   // namespace crs (c. roman [data] structures [library])

#include "arch.tpp"

#endif  // ARCH_HPP