#include <iostream>
#include "queue.hpp"

namespace crs {

template <class T, class Container>
bool Queue<T, Container>::empty() const {
    return cont.empty();
}

template <class T, class Container>
size_t Queue<T, Container>::size() const {
    return cont.size();
}

template <class T, class Container>
const T& Queue<T, Container>::front() const {
    return cont.front();
}

template <class T, class Container>
T& Queue<T, Container>::front() {
    return cont.front();
}

template <class T, class Container>
const T& Queue<T, Container>::back() const {
    return cont.back();
}

template <class T, class Container>
T& Queue<T, Container>::back() {
    return cont.back();
}

template <class T, class Container>
void Queue<T, Container>::push(const T& element) {
    cont.push_back(element);
}

template <class T, class Container>
void Queue<T, Container>::pop() {
    cont.pop_front();
}

template <class T, class Container>
void Queue<T, Container>::print() const {
    if (cont.empty()) {
        std::cout << "Queue is empty, nothing to print" << std::endl;
        return;
    }

    Container copy = cont;

    while(copy.size() > 0) {
        std::cout << copy.front() << "<--";     // make look like queue
        copy.pop_front();
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [data] structures [library])