#include <cmath>
#include <iostream>
#include "pqueue.hpp"
#include "../../../utilities/utils.hpp"

namespace crs {

template <typename T>
int PQueue<T>::parent(int i) const {
    float f = (float)i;
    return (std::ceil(f / 2) - 1);
}

template <typename T>
int PQueue<T>::left(int i) const {
    return (2 * i + 1);
}

template <typename T>
int PQueue<T>::right(int i) const {
    return (2 * i + 2);
}

template <typename T>
void PQueue<T>::heapify(std::vector<T> &vec, int i) {

    int l = left(i);
    int r = right(i);
    int greatest;

    if ((l < vec.size()) && (vec[l] > vec[i])) {
        greatest = l;
    } else {
        greatest = i;
    }

    if ((r < vec.size()) && (vec[r] > vec[greatest])) {
        greatest = r;
    }

    if (greatest != i) {
        std::swap(vec[i], vec[greatest]);
        heapify(vec, greatest);
    }
}

template <typename T>
size_t PQueue<T>::size() const {
    return data.size();
}

template <typename T>
bool PQueue<T>::empty() const {
    return data.empty();
}

template <typename T>
const T& PQueue<T>::top() const {
    if (data.empty())
        throw_error(__PRETTY_FUNCTION__, utils::ReadFromEmptyError);

    return data.front();
}

template <typename T>
void PQueue<T>::pop() {
    if (data.empty())
        throw_error(__PRETTY_FUNCTION__, utils::RemoveFromEmptyError);

    data.front() = data.back();
    data.pop_back();
    heapify(data, 0);
}

/*
template <typename T>
void PQueue<T>::increase(const T &obj) {

}
*/

template <typename T>
void PQueue<T>::push(const T &obj) {
    data.push_back(obj);
    
    int i = data.size() - 1;
    while ((i > 0) && (data[parent(i)] < data[i])) {
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

/*
template <typename T>
void PQueue<T>::remove(const T &obj) {

}
*/

template <typename T>
void PQueue<T>::print() const {
    if (data.empty()) {
        std::cout << "Nothing to print, queue is empty" << std::endl;
        return;
    }

    for (const auto &d : data) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}

}   // namespace crs (c. roman [data] structures [library])