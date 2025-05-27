#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../trees/bstree.hpp"
#include "../arrays/darray.hpp"
#include "../lists/singly_linked_list/slist.hpp"

namespace crs {

/*
template <class Key, class T, class Compare>
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
        typename BSTree<Key, T, Compare>::Node* node_;

        // Returns node ptr to min element in subtree rooted at given node
        BSTree<Key, T, Compare>::Node* minimum(BSTree<Key, T, Compare>::Node* node) {          // O(h)                   
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        // Returns node ptr to min element in subtree rooted at given node (recursive approach)
        BSTree<Key, T, Compare>::Node* minimum_r(BSTree<Key, T, Compare>::Node* node) {        // O(h)
            if (node->left != nullptr) {
                return minimum_r(node->left);
            } else {
                return node;
            }
        }

        // Returns node ptr to max element in subtree rooted at given node
        BSTree<Key, T, Compare>::Node* maximum(BSTree<Key, T, Compare>::Node* node) {          // O(h)
            while (node->right != nullptr) {
                node = node->right;
            }
            return node;
        }

        // Returns node ptr to max element in subtree rooted at given node (recursive approach)
        BSTree<Key, T, Compare>::Node* maximum_r(BSTree<Key, T, Compare>::Node* node) {        // O(h)
            if (node->right != nullptr) {
                return minimum_r(node->right);
            } else {
                return node;
            }
        }

        // Returns successor of given node if exists (null otherwise)
        BSTree<Key, T, Compare>::Node* successor(BSTree<Key, T, Compare>::Node* node) {        // O(h)
            if (node->right != nullptr) {
                return minimum(node->right);
            } else {
                typename BSTree<Key, T, Compare>::Node* ancestor = node->parent;
                while (ancestor != nullptr && ancestor->left != node) {
                    node = ancestor;
                    ancestor = ancestor->parent;
                }
                return ancestor;
            }
        }

        // Returns predecessor of given node if exists (null otherwise)
        BSTree<Key, T, Compare>::Node* predecessor(BSTree<Key, T, Compare>::Node* node) {     // O(h)
            if (node->left != nullptr) {
                return maximum(node->left);
            } else {
                typename BSTree<Key, T, Compare>::Node* ancestor = node->parent;
                while (ancestor != nullptr && ancestor->right != node) {
                    node = ancestor;
                    ancestor = ancestor->parent;
                }
                return ancestor;
            }
        }                                                                
};
*/

// DArrayIterator

// SListIterator

// HashMapIterator

}   // namespace crs (c. roman [data] structures [library])

#endif  // ITERATOR_HPP