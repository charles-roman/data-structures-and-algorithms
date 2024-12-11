#include <iostream>
#include "stack.hpp"

namespace crs {

template <class T, class Container>
bool Stack<T, Container>::empty() const {
    return cont.empty();
}

template <class T, class Container>
size_t Stack<T, Container>::size() const {
    return cont.size();
}

template <class T, class Container>
const T& Stack<T, Container>::top() const {
    return cont.back();
}

template <class T, class Container>
T& Stack<T, Container>::top() {
    return cont.back();
}

template <class T, class Container>
void Stack<T, Container>::pop() {
    cont.pop_back();
}

template <class T, class Container>
void Stack<T, Container>::push(const T& element) {
    cont.push_back(element);
}

template <class T, class Container>
void Stack<T, Container>::print() const {
    if (cont.empty()) {
        std::cout << "Stack is empty, nothing to print" << std::endl;
        return;
    }

    Container copy = cont;  // copy
    
    while(copy.size() > 0) {
        std::cout << copy.back() << '\n' << '-' << '\n';    // make look like stack
        copy.pop_back();
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [data] structures [library])