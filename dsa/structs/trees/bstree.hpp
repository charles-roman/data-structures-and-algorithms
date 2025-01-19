#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <vector>
#include <functional>
// #include "../iterators/iterator.hpp"

namespace crs {

template <class Key, class T, class Compare = std::less<Key>>
class BSTree {
    public:
        // Forward Declaration
        class BSTreeIterator;

        // Member Types
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const Key, T>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using key_compare = Compare;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator = BSTreeIterator;
        using const_iterator = const iterator;

        // Validate Iterator
        static_assert(std::bidirectional_iterator<iterator>);

                                                                                    // (h = height of tree, n = # of elements)

        // Default Constructor
        BSTree();                                                                   // O(1)
        // Destructor
        ~BSTree();                                                                  // O(n)
        // Copy Constructor
        BSTree(const BSTree& other);                                                // O(n)
        // Move Constructor
        BSTree(BSTree&& other) noexcept;                                            // O(1)
        // Copy Assignment Operator
        BSTree& operator=(const BSTree& other);                                     // O(n)
        // Move Assignment Operator 
        BSTree& operator=(BSTree&& other) noexcept;                                 // O(1)

        // Returns iterator to first node in-order if exists (null otherwise)
        iterator begin() noexcept;                                                  // O(h) (could be const time if we store pos of min)
        const_iterator cbegin() const noexcept; 
        // Returns successor to last node in-order
        iterator end() noexcept;                                                    // O(h) (could be const time if we store pos of max)
        const_iterator cend() const noexcept;
        // Returns iterator to root of bst
        iterator root() noexcept;                                                   // O(1)

        // Checks if tree is empty
        bool empty() const;                                                         // O(1)
        // Returns number of elements in tree
        size_type size() const;                                                     // O(1)

        // Returns iterator to node w/ specific key if exists (null otherwise)
        iterator search(const key_type& key, iterator it = nullptr);                // O(h) *(preferred in practice over recursive counterpart)
        iterator search_r(const key_type& key, iterator it);                        // recursive approach

        // In-order traversal, copies elements to vector (depth-first search)
        std::vector<value_type> in_order(iterator it = nullptr) const;              // O(n) (auxiliary stack approach)
        std::vector<value_type> in_order_mor(iterator it = nullptr) const;          // Morris traversal approach
        std::vector<value_type> in_order_suc(iterator it = nullptr) const;          // successor approach
        void in_order_r(std::vector<value_type>& vec, iterator it) const;           // recursive approach
        // Pre-order traversal, copies elements to vector (depth-first search)
        std::vector<value_type> pre_order(iterator it = nullptr) const;             // O(n) (auxiliary stack approach)
        void pre_order_r(std::vector<value_type>& vec, iterator it) const;          // recursive approach
        // Post-order traversal, copies elements to vector (depth-first search)
        std::vector<value_type> post_order(iterator it = nullptr) const;            // O(n) (auxiliary stack approach) 
        void post_order_r(std::vector<value_type>& vec, iterator it) const;         // recursive approach
        // Level-order traversal, copies elements to vector (breadth-first search)
        std::vector<value_type> level_order(iterator it = nullptr) const;           // O(n) (auxiliary queue approach)
        // boundary traversal
        // diagonal traversal

        // Clears all elements of tree
        void clear();                                                               // O(n)
        // Inserts element into tree based on given key
        std::pair<iterator, bool> insert(const value_type& value);                  // O(h)
        // Erases element from tree at given node
        iterator erase(iterator it);                                                // O(h)
        // Erases element from tree based on given key
        size_type erase(const key_type& key);                                       // O(h)

        // Returns function used to compare keys 
        Compare key_comp() const;

        // Print elements of bst in-order
        void print() const;

    private:
        struct Node {                     
            key_type key;       // order of {key, data} members are specific for iterator deref
            mapped_type data;
            Node* parent;
            Node* left;
            Node* right;

            Node() = default;
            Node(key_type k, mapped_type d)
                : key(k), data(d), parent(nullptr), left(nullptr), right(nullptr) {}
        };

        Node* root_;
        size_type size_;
        Compare comp_;   // this can reverse the BST property

        // Checks given keys for equality
        bool key_eq(const key_type& k1, const key_type& k2) const;
        // Replaces one subtree as a child of its parent with another subtree
        void transplant(Node* src, Node* dest);
        // Erases elements in tree from subtree rooted at given node using post-order traversal
        void erase_tree(Node* node);
        // Adds elements to tree from subtree rooted at given node using pre-order traversal
        void build_tree(Node* node);

    public:
        class BSTreeIterator {
            public:
                // Declare Friend
                friend class BSTree;

                // Member Types
                using iterator_category = std::bidirectional_iterator_tag;
                using difference_type = std::ptrdiff_t;
                using value_type = std::pair<const Key, T>;
                using reference = value_type&;
                using pointer = value_type*;

                // default constructor
                BSTreeIterator() : node_(nullptr) {}
                // parameterized constructor
                BSTreeIterator(Node* node) : node_(node) {}
                // dereference
                reference operator*() const noexcept {return *reinterpret_cast<pointer>(&node_->key);}
                // member access
                pointer operator->() const noexcept {return &operator*();}
                // pre-increment
                BSTreeIterator& operator++() {node_ = successor(node_); return *this;} 
                // post-increment
                BSTreeIterator operator++(int) {BSTreeIterator temp = *this; ++(*this); return temp;}
                // pre-decrement
                BSTreeIterator& operator--() {node_ = predecessor(node_); return *this;}
                // post-decrement
                BSTreeIterator operator--(int) {BSTreeIterator temp = *this; --(*this); return temp;}  
                // equality comparison
                friend bool operator==(const BSTreeIterator& left, const BSTreeIterator& right) {return (left.node_ == right.node_);}  
                // inequality comparison
                friend bool operator!=(const BSTreeIterator& left, const BSTreeIterator& right) {return (left.node_ != right.node_);}

            private:
                Node* node_;

                // Returns node ptr to min element in subtree rooted at given node
                Node* minimum(Node* node) {                               // O(h)                   
                    while (node->left != nullptr) {
                        node = node->left;
                    }
                    return node;
                }

                // Returns node ptr to min element in subtree rooted at given node (recursive approach)
                Node* minimum_r(Node* node) {                             // O(h)
                    if (node->left != nullptr) {
                        return minimum_r(node->left);
                    } else {
                        return node;
                    }
                }

                // Returns node ptr to max element in subtree rooted at given node
                Node* maximum(Node* node) {                               // O(h)
                    while (node->right != nullptr) {
                        node = node->right;
                    }
                    return node;
                }

                // Returns node ptr to max element in subtree rooted at given node (recursive approach)
                Node* maximum_r(Node* node) {                             // O(h)
                    if (node->right != nullptr) {
                        return minimum_r(node->right);
                    } else {
                        return node;
                    }
                }

                // Returns successor of given node if exists (null otherwise)
                Node* successor(Node* node) {                             // O(h)
                    if (node->right != nullptr) {
                        return minimum(node->right);
                    } else {
                        Node* ancestor = node->parent;
                        while (ancestor != nullptr && ancestor->left != node) {
                            node = ancestor;
                            ancestor = ancestor->parent;
                        }
                        return ancestor;
                    }
                }

                // Returns predecessor of given node if exists (null otherwise)
                Node* predecessor(Node* node) {                           // O(h)
                    if (node->left != nullptr) {
                        return maximum(node->left);
                    } else {
                        Node* ancestor = node->parent;
                        while (ancestor != nullptr && ancestor->right != node) {
                            node = ancestor;
                            ancestor = ancestor->parent;
                        }
                        return ancestor;
                    }
                }                                                                
        };
};

}   // namespace crs (c. roman [data] structures [library])

#include "bstree.tpp"

#endif  // BSTREE_HPP