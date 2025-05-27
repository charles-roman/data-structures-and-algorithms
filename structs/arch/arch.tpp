#include <iostream>
#include <cmath>
#include "arch.hpp"
#include "../../utils/utils.hpp"

namespace crs {

template <class Key, class T, class Hash, class KeyEqual>
const size_t HashMap<Key, T, Hash, KeyEqual>::INV_GOLDEN_RATIO = 0x9e3779b9;

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::HashMap() 
    : begin_(nullptr), end_(nullptr), size_(0),
        bucket_count_(1), max_load_factor_(1.0f), 
            hash_function_(Hash()), key_eq_(KeyEqual()), bucket_arr_(nullptr) {

        bucket_arr_ = new Node*[1]{nullptr};
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::HashMap(size_t count) 
    : begin_(nullptr), end_(nullptr), size_(0),
        bucket_count_(1), max_load_factor_(1.0f),
            hash_function_(Hash()), key_eq_(KeyEqual()), bucket_arr_(nullptr) {

        while (bucket_count_ < count) {
            bucket_count_ *= 2;
        }

        bucket_arr_ = new Node*[bucket_count_]{nullptr};
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::~HashMap() {
    clear();
    delete[] bucket_arr_;
    bucket_arr_ = nullptr;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::HashMap(const HashMap& other)                                     
    : begin_(nullptr), end_(nullptr), size_(other.size_), 
        bucket_count_(other.bucket_count_), max_load_factor_(other.max_load_factor_),
            hash_function_(other.hash_function_), key_eq_(other.key_eq_), bucket_arr_(nullptr) {


    // UPDATE begin_ and end_        

    bucket_arr_ = new Node*[bucket_count_]{nullptr};
    for (size_t i = 0; i < bucket_count_; ++i) {                // no need for rehashing, can just copy everything directly
        Node* current = other.bucket_arr_[i];
        while (current != nullptr) {                            // reverses order of other hashmap, but we are not concerned with order                        
            auto node = new Node(current->data, bucket_arr_[i]);    
            bucket_arr_[i] = node;
            current = current->next;
        }
    }
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::HashMap(HashMap&& other) noexcept
    : begin_(other.begin_), end_(other.end_), size_(other.size_),
        bucket_count_(other.bucket_count_), max_load_factor_(other.max_load_factor_),
            hash_function_(other.hash_function_), key_eq_(other.key_eq_), bucket_arr_(other.bucket_arr_)  {

    other.bucket_arr_ = new Node*[1]{nullptr};
    other.begin_ = nullptr;
    other.end_ = nullptr;
    other.size_ = 0;
    other.bucket_count_ = 1;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>& HashMap<Key, T, Hash, KeyEqual>::operator=(const HashMap& other) {
    if (this != &other) {
        clear();

        if (bucket_count_ != other.bucket_count_) rehash(other.bucket_count_);

        for(size_t i = 0; i < other.bucket_count_; ++i) {
            Node* current = other.bucket_arr_[i];
            while(current != nullptr) {           
                insert(current->data);
                current = current->next;
            }   
        }
    }
    return *this;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>& HashMap<Key, T, Hash, KeyEqual>::operator=(HashMap&& other) noexcept {
    if (this != &other) {
        clear();

        if (bucket_count_ != other.bucket_count_) rehash(other.bucket_count_);

        for(size_t i = 0; i < other.bucket_count_; ++i) {
            Node* current = other.bucket_arr_[i];
            while(current != nullptr) {           
                size_t bucket = hash_value(current->data.first);
                other.bucket_arr_[i] = current->next;
                current->next = bucket_arr_[bucket];
                bucket_arr_[bucket] = current;
                current = other.bucket_arr_[i];
            }                                                       // MAKE SURE SIZE IS ADJUSTED 
        }
        delete[] other.bucket_arr;
        other.bucket_arr_ = new Node*[1]{nullptr};
        other.begin_ = nullptr;
        other.end_ = nullptr;
        other.size_ = 0;
        other.bucket_count_ = 1;
    }
    return *this;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::Iterator HashMap<Key, T, Hash, KeyEqual>::begin() const {
    return begin_;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::Iterator HashMap<Key, T, Hash, KeyEqual>::end() const {
    return end_;
}

template <class Key, class T, class Hash, class KeyEqual>
bool HashMap<Key, T, Hash, KeyEqual>::empty() const {
    return (size_ == 0);
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::size() const {
    return size_;
}

template <class Key, class T, class Hash, class KeyEqual>
void HashMap<Key, T, Hash, KeyEqual>::clear() noexcept {

    // Iterator current = begin_;
    // while (current != nullptr) {
        
    // }


    for (size_t i = 0; i < bucket_count_; ++i) {
        while (bucket_arr_[i] != nullptr) {
            Node* temp = bucket_arr_[i];
            bucket_arr_[i] = bucket_arr_[i]->next;
            delete temp;
            temp = nullptr;
        }
    }
    size_ = 0;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::Iterator HashMap<Key, T, Hash, KeyEqual>::insert(const value_type& value) {
    size_t bucket = hash_value(value.first);
    Node* node = new Node(value, bucket_arr_[bucket]);
    bucket_arr_[bucket] = node;
    ++size_;

    if (size_ > (max_load_factor_ / bucket_count_)) rehash(bucket_count_ + 1);

    return node;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::Iterator HashMap<Key, T, Hash, KeyEqual>::erase(Iterator it) {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    size_t bucket = hash_value(it->first);
    Iterator next(it.node_->next);
    
    // Check if first element of map
    if (it == begin_) {
        // Check if last remaining element in map
        if (next == end_) {
            delete bucket_arr_[bucket];
            bucket_arr_[bucket] = nullptr;
            begin_ = nullptr;
            return end_;
        } else {
            size_t next_bucket = hash_value(next->first);
            // Check if last element of bucket
            if (bucket != next_bucket) {
                ++begin_;
                bucket_arr_[next_bucket] = begin_;
                delete bucket_arr_[bucket];
                bucket_arr_[bucket] = nullptr;
            } else {
                ++begin_;
                delete bucket_arr_[bucket];
                bucket_arr_[bucket] = begin_;
            }
        }
    } else {
        // Check if last element of map
        if (next == end_) {
            Iterator prev(bucket_arr_[bucket]);
            Iterator current(prev.node_->next);
            while (current != it) {
                prev = current;
                ++current;
            }
            // If last remaining element of bucket, reset bucket
            if (bucket_arr_[bucket] == prev.node_) bucket_arr_[bucket] = nullptr;
            prev.node_->next = nullptr;
            delete current.node_;
            current.node_ = nullptr;
        } else {
            size_t next_bucket = hash_value(next->first);

            Iterator prev(bucket_arr_[bucket]);
            Iterator current(prev.node_->next);
            while (current != it) {
                prev = current;
                ++current;
            }

            // Check if last element of bucket                      
            if (bucket != next_bucket) {
                prev.node_->next = current.node_->next;
                bucket_arr_[next_bucket] = prev.node_;
                // If last remaining element of bucket, reset bucket
                if (bucket_arr_[bucket] == prev.node_) bucket_arr_[bucket] = nullptr;
                delete current.node_;
                current.node_ = nullptr;
            } else {
                prev.node_->next = current.node_->next;
                delete current.node_;
                current.node_ = nullptr;
            }
        }
    }
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::erase(const Key& key) {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    size_t count{0};
    size_t bucket = hash_value(key);
    Node* prev = nullptr;
    Node* current = bucket_arr_[bucket];

    while (current != nullptr) {                        
        if (key_eq_(current->data.first, key)) {
            if (prev == nullptr) {
                bucket_arr_[bucket] = current->next;
                delete current;
                current = bucket_arr_[bucket];
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            ++count;
            --size_;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::count(const Key& key) const {
    size_t count{0};
    size_t bucket = hash_value(key);
    Node* current = bucket_arr_[bucket];

    while (current != nullptr) {
        if (key_eq_(current->data.first, key)) ++count;
        current = current->next;
    }
    return count;
}

template <class Key, class T, class Hash, class KeyEqual>
HashMap<Key, T, Hash, KeyEqual>::Iterator HashMap<Key, T, Hash, KeyEqual>::find(const Key& key) {
    size_t bucket = hash_value(key);
    Node* current = bucket_arr_[bucket];

    while (current != nullptr) {
        if (key_eq_(current->data.first, key)) return current;
        current = current->next;
    }
    return nullptr;
}

template <class Key, class T, class Hash, class KeyEqual>
bool HashMap<Key, T, Hash, KeyEqual>::contains(const Key& key) const {
    size_t bucket = hash_value(key);
    Node* current = bucket_arr_[bucket];

    while (current != nullptr) {
        if (key_eq_(current->data.first, key)) return true;
        current = current->next;
    }
    return false;
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::bucket_count() const {
    return bucket_count_;
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::bucket_size(size_t bucket) const {
    if (bucket >= bucket_count_)
        throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

    size_t count{0};
    Node* current = bucket_arr_[bucket];
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::bucket(const Key& key) const {
    return hash_value(key);
}

template <class Key, class T, class Hash, class KeyEqual>
float HashMap<Key, T, Hash, KeyEqual>::load_factor() const {
    return (size_ / bucket_count_);
}

template <class Key, class T, class Hash, class KeyEqual>
float HashMap<Key, T, Hash, KeyEqual>::max_load_factor() const {
    return max_load_factor_;
}

template <class Key, class T, class Hash, class KeyEqual>
void HashMap<Key, T, Hash, KeyEqual>::max_load_factor(float ml) {
    max_load_factor_ = ml;
}

template <class Key, class T, class Hash, class KeyEqual>
void HashMap<Key, T, Hash, KeyEqual>::rehash(size_t count) {
    // Determine new bucket_count_ based off count and required # of buckets to satisfy ml
    size_t new_count{bucket_count_};
    if (count >= bucket_count_) {
        while ((new_count < count) || (new_count < (size_ / max_load_factor_)) || (new_count < 2)) {
            new_count *= 2;
        }
    } else if (count < bucket_count_) {
        while ((new_count >= 2*count) && (new_count >= 2*(size_ / max_load_factor_)) && (new_count > 2)) {
            new_count /= 2;
        }
    } // rehash(0) provides no rehash for bucket_count_ = 1, unlike STL   

    // If count unchanged, no rehash required, else rehash
    if (new_count == bucket_count_) {
        return;
    } else {
        if (empty()) {
            delete[] bucket_arr_;
            bucket_arr_ = new Node*[new_count]{nullptr};
        } else {                                            // move
            Node** new_arr = new Node*[new_count]{nullptr}; 
            for (size_t i = 0; i < bucket_count_; ++i) {    
                Node* current = bucket_arr_[i];
                while (current != nullptr) {    
                    size_t bucket = hash_value(current->data.first, new_count);
                    bucket_arr_[i] = current->next;
                    current->next = new_arr[bucket];
                    new_arr[bucket] = current;
                    current = bucket_arr_[i];
                }
            }
            delete[] bucket_arr_;
            bucket_arr_ = new_arr;
            new_arr = nullptr;
            bucket_count_ = new_count;
        }
    }
}

template <class Key, class T, class Hash, class KeyEqual>
Hash HashMap<Key, T, Hash, KeyEqual>::hash_function() const {
    return hash_function_();
}

template <class Key, class T, class Hash, class KeyEqual>
KeyEqual HashMap<Key, T, Hash, KeyEqual>::key_eq() const {
    return key_eq_();
}

template <class Key, class T, class Hash, class KeyEqual>
size_t HashMap<Key, T, Hash, KeyEqual>::hash_value(const Key& key, size_t count) const {
    size_t hash_value = hash_function_(key);

    // number of bits stored in size type
    size_t size_tbits = sizeof(size_t) * CHAR_BIT;

    // number of bits needed to store number of size bucket_count - 1
    size_t count_bits = static_cast<size_t>(std::log2(count)); 

    // double-hash w/ multiply shift to constrict hash_value to valid index
    size_t bucket = (hash_value * INV_GOLDEN_RATIO) >> (size_tbits - count_bits); 

    return bucket;
}

template <class Key, class T, class Hash, class KeyEqual>
void HashMap<Key, T, Hash, KeyEqual>::print() const {
    if (empty()) {
        std::cout << "Nothing to print, map is empty" << std::endl;
        return;
    }

    for(size_t i = 0; i < bucket_count_; ++i) {
        Node* current = bucket_arr_[i];
        while (current != nullptr) {
            std::cout << "{Key: " << current->data.first << ", Value: " << current->data.second << "}, ";
            current = current->next;
        }
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [data] structures [library])