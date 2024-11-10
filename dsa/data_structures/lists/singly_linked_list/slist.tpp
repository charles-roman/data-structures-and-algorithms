#include <iostream>
#include "slist.hpp"
#include "../../../utilities/utils.hpp"

namespace crs {

template <typename T>
SList<T>::~SList() {
    while(!this->empty()) { // might be slightly less efficient due to derefencing, but is cleaner to read
        this->pop_front();  // this double checks the empty list, but is cleaner to read
    }
}

template <typename T>
size_t SList<T>::size() const {
    size_t size{0};
    Node<T>* node = head;
    while (node != nullptr) {
        ++size;
        node = node->get_next();
    }
    return size;
}

template <typename T>
bool SList<T>::empty() const {
    return (head == nullptr);
}

template <typename T>
void SList<T>::push_front(const T& value) {
    auto node = new(std::nothrow) Node<T>;
    if (node == nullptr)
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);

    node->set_data(value);
    node->set_next(head);
    head = node;

    if (tail == nullptr)
        tail = head;
}

template <typename T>
void SList<T>::pop_front() {
    if (this->empty()) // might be slightly less efficient due to derefencing, but is cleaner to read
        throw_error(__PRETTY_FUNCTION__, utils::RemoveFromEmptyError);

    Node<T>* temp = head;
    head = head->get_next();
    delete temp;
    temp = nullptr;

    if (head == nullptr)
        tail = nullptr;
}

template <typename T>
const T& SList<T>::front() const {
    if (this->empty()) // might be slightly less efficient due to derefencing, but is cleaner to read
        throw_error(__PRETTY_FUNCTION__, utils::ReadFromEmptyError);

    return head->get_data();
}

template <typename T>
void SList<T>::push_back(const T& value) {
    auto node = new(std::nothrow) Node<T>;
    if (node == nullptr)
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);

    node->set_data(value);
    // node->set_next(nullptr);

    if (tail == nullptr) {
        tail = node;
        head = node;
    } else {
        tail->set_next(node);
        tail = node;
    }
}

template <typename T>
void SList<T>::pop_back() {
    if (this->empty()) // might be slightly less efficient due to derefencing, but is cleaner to read
        throw_error(__PRETTY_FUNCTION__, utils::RemoveFromEmptyError);

    if (tail == head) {
        tail = nullptr;
        delete head;
        head = nullptr;
    } else {
        Node<T>* node = head;
        while (node->get_next()->get_next() != nullptr) {
            node = node->get_next();
        }

        tail = node;
        delete node->get_next();
        node->set_next(nullptr);
    }
}

template <typename T>
const T& SList<T>::back() const {
    if (this->empty()) // might be slightly less efficient due to derefencing, but is cleaner to read
        throw_error(__PRETTY_FUNCTION__, utils::ReadFromEmptyError);

    return tail->get_data();
}

template <typename T>
const T& SList<T>::value_at(int index) const {
    if ((index < 0) || (index >= this->size())) // slightly inefficient as it preemptively loops thru list, but clean to read
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    size_t current{0};
    Node<T>* node = head;
    while(current != index) {
        node = node->get_next();
        ++current;
    }
    return node->get_data();
}

template <typename T>
void SList<T>::insert_after(int index, const T& value) {
    if ((index < 0) || (index >= this->size())) // slightly inefficient as it preemptively loops thru list, but clean to read
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    size_t current{0};
    Node<T>* node = head;
    while(current != index) {
        node = node->get_next();
        ++current;
    }

    auto new_node = new Node<T>;
    if (new_node == nullptr)
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);

    new_node->set_data(value);
    new_node->set_next(node->get_next());
    node->set_next(new_node);

    if (tail == node)
        tail = new_node;
}

template <typename T>
void SList<T>::erase_after(int index) {
    if ((index < 0) || (index >= (this->size() - 1))) // slightly inefficient as it preemptively loops thru list, but clean to read
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    size_t current{0};
    Node<T>* node = head;
    while(current != index) {
        node = node->get_next();
        ++current;
    }
    Node<T>* temp = node->get_next();
    node->set_next(node->get_next()->get_next());
    delete temp;
    temp = nullptr;
}

template <typename T>
void SList<T>::print() const {
    if (this->empty())    // might be slightly less efficient due to derefencing, but is cleaner to read
        std::cout << "Nothing to print, list is empty" << std::endl;
    
    Node<T>* node = head;
    while (node != nullptr) {
        std::cout << node->get_data() << " --> ";
        node = node->get_next();
    }
    std::cout << std::endl;
}

} // namespace crs (c. roman [data] structures [library])