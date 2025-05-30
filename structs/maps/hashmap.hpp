#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>

namespace crs {

template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>>
class HashMap { // std::unordered_multimap
    public:
        // Constructors
        HashMap();
        explicit HashMap(size_t count);

        // Destructor
        ~HashMap();

        // Copy Constructor (deep copy)
        HashMap(const HashMap& other);                
        // Move Constructor
        HashMap(HashMap&& other) noexcept;           

        // Copy Assignment Operator (deep copy)
        HashMap& operator=(const HashMap& other);     
        // Move Assignment Operator
        HashMap& operator=(HashMap&& other) noexcept;

                                                                                // (m = current bucket count, n = # of elements)
        // Checks whether map is empty
        bool empty() const;                                                     // O(1)
        // Returns number of elements in map
        size_t size() const;                                                    // O(1)

        // Clears contents of map
        void clear() noexcept;                                                  // O(n + m) (linking lists from separate buckets can improve to O(n))
        // Inserts element to map
        void insert(const std::pair<const Key, T>& data);                       // O(n) (O(1) on avg)  
        // Erases elements with specific key from map and returns count
        size_t erase(const Key& key);                                           // O(n) (O(key_count) on avg)

        // iterator erase(iterator it);                                         // O(n) (O(1) on avg); using a doubly-linked list would make this O(1) worst case 

        // Returns number of elements matching key
        size_t count(const Key& key) const;                                     // O(n) (O(key_count) on avg)
        // Finds and returns element with specific key
        std::pair<const Key, T> find(const Key& key);                          // O(n) (O(1) on avg); must return a copy in case key is not found
        // Checks if map contains element with specific key
        bool contains(const Key& key) const;                                    // O(n) (O(1) on avg)

        // Returns number of buckets in map
        size_t bucket_count() const;                                            // O(1)
        // Returns number of elements in specific bucket
        size_t bucket_size(size_t bucket) const;                                // O(n) (O(1) on avg)?
        // Returns bucket for specific key
        size_t bucket(const Key& key) const;                                    // O(1)

        // Returns load factor (avg number of elements per bucket)
        float load_factor() const;                                              // O(1)
        // Gets maximum load factor
        float max_load_factor() const;                                          // O(1)
        // Sets maximum load factor
        void max_load_factor(float ml);                                         // O(1) (could restrict ml input to be positive)
        // Reserves specified number of buckets and regenerates map
        void rehash(size_t count);                                              // O(n + m) (linking lists from separate buckets can improve to O(n))

        // void reserve (size_t size);                                          // O(n^2) (O(n) on avg) 

        // Returns function used to hash keys 
        Hash hash_function() const;                                             // O(1)
        // Returns function used to compare keys
        KeyEqual key_eq() const;                                                // O(1)

        // Print elements in map
        void print() const;

    private:
        size_t hash_value(const Key& key, size_t count = 0) const;              // O(1)

        struct Node {
            // Constructors
            Node() = default;
            Node(const std::pair<const Key, T>& pair, Node* node = nullptr)
                : data(pair), next(node) {}

            // Destructor
            // ~Node() = default;

            std::pair<const Key, T> data;
            Node* next;
        };

        static const size_t INV_GOLDEN_RATIO;
        size_t size_;
        size_t bucket_count_;   // class uses a bucket count that is a power of 2 (instead of a prime)
        float max_load_factor_;
        Hash hash_function_;                
        KeyEqual key_eq_;                   
        Node** bucket_arr_;
};

}   // namespace crs (c. roman [data] structures [library])

#include "hashmap.tpp"

#endif  // HASHMAP_HPP