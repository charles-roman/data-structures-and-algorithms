#include <cmath>
#include <iostream>
#include "pqueue.hpp"
#include "../../../utils/utils.hpp"

namespace crs {

template <typename T, typename Container, typename Compare>
size_t PQueue<T, Container, Compare>::parent(const size_t i) const {
    return std::ceil(i / 2.0f) - 1;
}

template <typename T, typename Container, typename Compare>
size_t PQueue<T, Container, Compare>::left(const size_t i) const {
    return (2 * i + 1);
}

template <typename T, typename Container, typename Compare>
size_t PQueue<T, Container, Compare>::right(const size_t i) const {
    return (2 * i + 2);
}

template <typename T, typename Container, typename Compare>
void PQueue<T, Container, Compare>::heapify_down(const size_t i) {    
    size_t l = left(i);
    size_t r = right(i);
    size_t min_max;

    if ((l < cont.size()) && comp(cont[i], cont[l])) {
        min_max = l;
    } else {
        min_max = i;
    }

    if ((r < cont.size()) && comp(cont[min_max], cont[r])) {
        min_max = r;
    }

    if (min_max != i) {
        std::swap(cont[i], cont[min_max]);
        heapify_down(min_max);           
    }
}

template <typename T, typename Container, typename Compare>
void PQueue<T, Container, Compare>::heapify_up(size_t i) {
    while ((i > 0) && comp(cont[parent(i)], cont[i])) {
        std::swap(cont[parent(i)], cont[i]);
        i = parent(i);
    }
}

template <typename T, typename Container, typename Compare>
size_t PQueue<T, Container, Compare>::size() const {
    return cont.size();
}

template <typename T, typename Container, typename Compare>
bool PQueue<T, Container, Compare>::empty() const {
    return cont.empty();
}

template <typename T, typename Container, typename Compare>
const T& PQueue<T, Container, Compare>::top() const {
    return cont.front();
}

template <typename T, typename Container, typename Compare>
T& PQueue<T, Container, Compare>::top() {
    return cont.front();
}

template <typename T, typename Container, typename Compare>                
void PQueue<T, Container, Compare>::pop() {
    cont.front() = cont.back();
    cont.pop_back();
    heapify_down(0);
}

/*
template <typename T>
void PQueue<T>::increase(const T &obj) {

}
*/

template <typename T, typename Container, typename Compare>                 
void PQueue<T, Container, Compare>::push(const T &obj) {
    cont.push_back(obj);
    heapify_up(cont.size() - 1);
}

/*
template <typename T>
void PQueue<T>::remove(const T &obj) {

}
*/

template <typename T, typename Container, typename Compare>
void PQueue<T, Container, Compare>::print() const {
    if (cont.empty()) {
        std::cout << "Nothing to print, priority_queue is empty" << std::endl;
        return;
    }

    for (const auto &c : cont) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [cont] structures [library])