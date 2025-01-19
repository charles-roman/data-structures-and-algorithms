#include "bstree.hpp"
#include <iostream>
#include <stack>
#include <queue>

namespace crs {

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::BSTree() : root_(nullptr), size_(0), comp_(Compare()) {}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::~BSTree() {
    clear();
    root_ = nullptr;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::BSTree(const BSTree& other) : root_(nullptr), size_(0), comp_(other.comp_) { 
    build_tree(other.root_);    // copy using pre-order traversal to maintain order (level-order works as well)
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::BSTree(BSTree&& other) noexcept : root_(other.root_), size_(other.size_), comp_(other.comp_) {
        other.root_ = nullptr;
        other.size_ = 0;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>& BSTree<Key, T, Compare>::operator=(const BSTree& other) {
    if (this != &other) {
        clear();
        build_tree(other.root_);    // copy using pre-order traversal, order will remain same unless comp function differs
    }
    return *this;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>& BSTree<Key, T, Compare>::operator=(BSTree&& other) noexcept {
    if (this != &other) {
        root_ = other.root_;
        size_ = other.size_;
        
        other.root_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::begin() noexcept {  
    Node* current = root_;
    while (current->left != nullptr) {
        current = current->left;
    }
    return iterator(current);
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::const_iterator BSTree<Key, T, Compare>::cbegin() const noexcept {
    Node* current = root_;
    while (current->left != nullptr) {
        current = current->left;
    }
    return iterator(current);
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::end() noexcept { 
    Node* current = root_; 
    while (current != nullptr) {
        current = current->right;
    }
    return iterator(current);   // one past the max value
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::const_iterator BSTree<Key, T, Compare>::cend() const noexcept {
    Node* current = root_; 
    while (current != nullptr) {
        current = current->right;
    }
    return iterator(current);   // one past the max value
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::root() noexcept {
    return iterator(root_);
}

template <class Key, class T, class Compare>
bool BSTree<Key, T, Compare>::empty() const {
    return (size_ == 0);
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::size_type BSTree<Key, T, Compare>::size() const {
    return size_;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::search(const key_type& key, iterator it) {
    Node* node;
    if (it.node_ == nullptr) {    // default condition, start at root
        node = root_;
    } else {
        node = it.node_;
    }

    while (node != nullptr && !key_eq(key, node->key)) {
        if (comp_(key, node->key)) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return iterator(node);
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::search_r(const key_type& key, iterator it) {
    Node* node = it.node_;
    if (node == nullptr || key_eq(key, node->key)) {
        return iterator(node);
    }

    if (comp_(key, node->key)) {
        return search_r(key, iterator(node->left));
    } else {
        return search_r(key, iterator(node->right));
    }
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::in_order(iterator it) const {
    Node* node;
    if (it.node_ == nullptr) {      // default condition, start at root
        node = root_;
    } else {
        node = it.node_;
    }

    std::vector<value_type> vec;
    std::stack<Node*> stk;

    while (node != nullptr || !stk.empty()) {
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        vec.push_back(std::make_pair(node->key, node->data));
        node = node->right;
    }
    return vec;
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::in_order_mor(iterator it) const {
    Node* curr;
    if (it.node_ == nullptr) {      // default condition, start at root
        curr = root_;
    } else {
        curr = it.node_;
    }

    std::vector<value_type> vec;
    while (curr != nullptr) {
        if (curr->left == nullptr) {        // current lowest, add to output, advance current
            vec.push_back(std::make_pair(curr->key, curr->data));
            curr = curr->right;
        } else {                            // not current lowest, advance prev to determine next step
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {   // add thread, retract current
                prev->right = curr;
                curr = curr->left;
            } else {                        // remove thread, add to output, advance current
                prev->right = nullptr;
                vec.push_back(std::make_pair(curr->key, curr->data));
                curr = curr->right;
            }
        }
    }
    return vec;
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::in_order_suc(iterator it) const {
    if (it.node_ == nullptr) {      // default condition, start at root
        it = cbegin();
    }

    std::vector<value_type> vec;

    while (it != nullptr) {
        vec.push_back(*it);
        ++it;   // gets successor
    }
    return vec;
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::in_order_r(std::vector<value_type>& vec, iterator it) const {
    Node* node = it.node_;
    if (node != nullptr) {
        in_order_r(vec, iterator(node->left));
        vec.push_back(std::make_pair(node->key, node->data));
        in_order_r(vec, iterator(node->right));
    }
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::pre_order(iterator it) const {
    Node* node;
    if (it.node_ == nullptr) {
        node = root_;
    } else {
        node = it.node_;
    }

    std::vector<value_type> vec;
    std::stack<Node*> stk;
    stk.push(node);

    if (node == nullptr) return vec;    // in case of empty tree

    while (!stk.empty()) {
        node = stk.top();
        stk.pop();
        vec.push_back(std::make_pair(node->key, node->data));
        
        if (node->right != nullptr) // push right first so its processed last
            stk.push(node->right);

        if (node->left != nullptr)
            stk.push(node->left);
    }
    return vec;
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::pre_order_r(std::vector<value_type>& vec, iterator it) const {
    Node* node = it.node_;
    if (node != nullptr) {
        vec.push_back(std::make_pair(node->key, node->data));
        pre_order_r(vec, iterator(node->left));
        pre_order_r(vec, iterator(node->right));
    }
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::post_order(iterator it) const {
    Node* node;
    if (it.node_ == nullptr) {
        node = root_;
    } else {
        node = it.node_;
    }

    std::vector<value_type> vec;
    std::stack<Node*> stk1, stk2;
    stk1.push(node);

    if (node == nullptr) return vec;

    while (!stk1.empty()) {
        node = stk1.top();
        stk1.pop();
        stk2.push(node);

        if (node->left != nullptr)
            stk1.push(node->left);

        if (node->right != nullptr)
            stk1.push(node->right);
    }

    while (!stk2.empty()) {
        node = stk2.top();
        stk2.pop();
        vec.push_back(std::make_pair(node->key, node->data));
    }
    return vec;
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::post_order_r(std::vector<value_type>& vec, iterator it) const {
    Node* node = it.node_;
    if (node != nullptr) {
        post_order_r(vec, iterator(node->left));
        post_order_r(vec, iterator(node->right));
        vec.push_back(std::make_pair(node->key, node->data));
    }
}

template <class Key, class T, class Compare>
std::vector<typename BSTree<Key, T, Compare>::value_type> BSTree<Key, T, Compare>::level_order(iterator it) const {
    Node* node;
    if (it.node_ == nullptr) {
        node = root_;
    } else {
        node = it.node_;
    }

    std::vector<value_type> vec;
    std::queue<Node*> q;
    q.push(node);

    if (node == nullptr) return vec;

    while (!q.empty()) {
        node = q.front();
        q.pop();
        vec.push_back(std::make_pair(node->key, node->data));

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }
    return vec;
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::clear() {         
    erase_tree(root_);                      // post-order traversal to free elements
    size_ = 0;
}

template <class Key, class T, class Compare>
std::pair<typename BSTree<Key, T, Compare>::iterator, bool> BSTree<Key, T, Compare>::insert(const value_type& value) {
    Node* current = root_;
    Node* prev = nullptr;

    while (current != nullptr) {
        prev = current;
        if (comp_(value.first, current->key)) {
            current = current->left;
        } else if (comp_(current->key, value.first)) {
            current = current->right;
        } else {                                                // no duplicates
            return std::make_pair(iterator(current), false);
        }
    }

    Node* new_node = new Node(value.first, value.second);
    new_node->parent = prev;
    if (prev == nullptr) {
        root_ = new_node;
    } else if (comp_(new_node->key, prev->key)) {
        prev->left = new_node;
    } else {
        prev->right = new_node;
    }

    ++size_;
    return std::make_pair(iterator(new_node), true);
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::iterator BSTree<Key, T, Compare>::erase(iterator it) {
    Node* node = it.node_;
    ++it;
    Node* successor = it.node_;

    if (node->left == nullptr) {            // no left children
        transplant(node->right, node);
    } else if (node->right == nullptr) {    // no right children
        transplant(node->left, node);
    } else {                                // both children
        if (successor != node->right) {
            transplant(successor->right, successor);
            successor->right = node->right;
            successor->right->parent = successor;
        }
        transplant(successor, node);
        successor->left = node->left;
        successor->left->parent = successor;
    }
    delete node;
    node = nullptr;
    --size_;
    return it;
}

template <class Key, class T, class Compare>
BSTree<Key, T, Compare>::size_type BSTree<Key, T, Compare>::erase(const key_type& key) {
    size_type count{0};
    Node* current = root_;
    while (current != nullptr) {
        if (comp_(key, current->key)) {
            current = current->left;
        } else if (comp_(current->key, key)) {
            current = current->right;
        } else {
            erase(iterator(current));
            return ++count;
        }
    }
    return count;
}

template <class Key, class T, class Compare>
Compare BSTree<Key, T, Compare>::key_comp() const {
    return comp_();
}

template <class Key, class T, class Compare>
bool BSTree<Key, T, Compare>::key_eq(const key_type& k1, const key_type& k2) const {
    return (!comp_(k1, k2) && !comp_(k2, k1));
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::transplant(Node* src, Node* dest) {
    if (dest->parent == nullptr) {              // destination at root
        root_ = src;
    } else if (dest == dest->parent->left) {    // destination is left child of parent
        dest->parent->left = src;
    } else {                                    // destination is right child of parent
        dest->parent->right = src;  
    }

    if (src != nullptr) {
        src->parent = dest->parent;
    }
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::erase_tree(Node* node) {
    if (node != nullptr) {
        erase_tree(node->left);
        erase_tree(node->right);
        delete node;
        node = nullptr;
    }
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::build_tree(Node* node) {
    if (node != nullptr) {
        insert(std::make_pair(node->key, node->data));
        build_tree(node->left);
        build_tree(node->right);
    }
}

template <class Key, class T, class Compare>
void BSTree<Key, T, Compare>::print() const {     // could be improved to print in shape of tree
    if (empty()) {
        std::cout << "Nothing to print, tree is empty" << std::endl;
        return;
    }

    iterator it = cbegin();
    iterator last = cend();
    while (it != last) {
        std::cout << "{" << it->first << ": " << it->second << "} -> ";
        ++it;
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [data] structures [library])