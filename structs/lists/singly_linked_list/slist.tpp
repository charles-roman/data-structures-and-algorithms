#include <iostream>
#include <string>
#include "slist.hpp"
#include "../../../utils/utils.hpp"

namespace crs {

template <typename T>
SList<T>::SList() : head(nullptr), tail(nullptr) {}

template <typename T>
SList<T>::SList(size_t count) : head(nullptr), tail(nullptr) {
    while(count != 0) {
        push_front(T{});
        --count;
    }
}

template <typename T>
SList<T>::SList(size_t count, const T& value) : head(nullptr), tail(nullptr) {
    while(count != 0) {
        push_front(value);
        --count;
    }
}

template <typename T>
SList<T>::~SList() {
    clear();
}

template <typename T>
SList<T>::SList(const SList<T>& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;

    while(current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}

template <typename T>
SList<T>::SList(SList<T>&& other) : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
SList<T>& SList<T>::operator=(const SList<T>& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;

        while(current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
SList<T>& SList<T>::operator=(SList<T>&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template <typename T>
bool SList<T>::empty() const {
    return (head == nullptr);
}

template <typename T>
size_t SList<T>::size() const {
    size_t size{0};
    Node* node = head;
    while (node != nullptr) {
        ++size;
        node = node->next;
    }
    return size;
}

template <typename T>
const T& SList<T>::front() const {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::ReadFromEmpty));

    return head->data;
}

template <typename T>
T& SList<T>::front() {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::ReadFromEmpty));

    return head->data;
}

template <typename T>
const T& SList<T>::back() const {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::ReadFromEmpty));

    return tail->data;
}

template <typename T>
T& SList<T>::back() {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::ReadFromEmpty));

    return tail->data;
}

template <typename T>
const T& SList<T>::at(size_t index) const {
    size_t current{0};
    Node* node = head;

    while(current != index) {
        if (node == nullptr)
            throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

        node = node->next;
        ++current;
    }
    return node->data;
}

template <typename T>
void SList<T>::clear() {                                                                                                
    while (!empty()) {
        pop_front();    // slightly inefficient: double empty check & repeated nullptr checks
    }
}

template <typename T>
void SList<T>::push_front(const T& value) {
    auto node = new Node(value, head);  // optional to catch std::bad_alloc exception
    head = node;

    if (tail == nullptr)
        tail = head;
}

template <typename T>
void SList<T>::pop_front() {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;

    if (head == nullptr)
        tail = nullptr;
}

template <typename T>
void SList<T>::push_back(const T& value) {
    auto node = new Node(value); // optional to catch std::bad_alloc exception

    if (tail == nullptr) {
        tail = node;
        head = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

template <typename T>
void SList<T>::pop_back() {
    if (empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    if (tail == head) {
        tail = nullptr;
        delete head;
        head = nullptr;
    } else {
        Node* node = head;
        while (node->next->next != nullptr) {
            node = node->next;
        }

        tail = node;
        delete node->next;
        node->next = nullptr;
    }
}

template <typename T>
void SList<T>::insert_after(size_t index, const T& value) {
    size_t current{0};
    Node* node = head;
    while(current != index) {
        if (node == nullptr)
            throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

        node = node->next;
        ++current;
    }

    auto new_node = new Node(value, node->next);    // optional to catch std::bad_alloc exception
    node->next = new_node;

    if (tail == node)
        tail = new_node;
}

template <typename T>
void SList<T>::erase_after(size_t index) {
    size_t current{0};
    Node* node = head;
    while(current != index) {
        if (node == nullptr)
            throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

        node = node->next;
        ++current;
    }

    Node* temp = node->next;
    node->next = node->next->next;
    delete temp;
    temp = nullptr;
}

template <typename T>
void SList<T>::reverse() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    Node* temp = head;
    head = prev;
    tail = temp;
}

template <typename T>
void SList<T>::print() const {
    if (empty()) {
        std::cout << "Nothing to print, list is empty" << std::endl;
        return;
    }
    
    Node* node = head;
    while (node != nullptr) {
        std::cout << node->data << " --> ";   // make look like linked list
        node = node->next;
    }
    std::cout << std::endl;
}

} // namespace crs (c. roman [data] structures [library])