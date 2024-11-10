#include <iostream>
#include "darray.hpp"
#include "../../utilities/utils.hpp"

namespace crs {

template <typename T>
DArray<T>::DArray(int size) {
    if (size < 0)
        throw_error(__PRETTY_FUNCTION__, utils::SizeDeclarationError);

    mSize = size; 
    mCapacity = size;
    std::unique_ptr<T[]> pArr (new(std::nothrow) T[size]{}); // better to use std::make_unique, but wanted to utilize std::nothrow
    if (pArr == nullptr) 
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);
}

template <typename T>
T& DArray<T>::operator[](int index) {
    return pArr[index];
}

template <typename T>
size_t DArray<T>::size() const {
    return mSize;
}

template <typename T>
size_t DArray<T>::capacity() const {
    return mCapacity;
}

template <typename T>
bool DArray<T>::empty() const {
    return (mSize == 0);
}

template <typename T>
T& DArray<T>::at(int index) const {
    if ((index < 0) || (index >= mSize))
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    return pArr[index];
}

template <typename T>
void DArray<T>::push_back(const T &rValue) {
    if (mSize == mCapacity)
        this->upsize();

    pArr[mSize] = rValue;
    ++mSize;
}

template <typename T>
void DArray<T>::pop_back() {
    if (this->empty())
        throw_error(__PRETTY_FUNCTION__, utils::RemoveFromEmptyError);

    --mSize;
}

template <typename T>
void DArray<T>::insert(int index, const T &rValue) {
    if ((index < 0) || (index > mSize))
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    if (mSize == mCapacity)
        this->upsize();
        
    for (size_t i = mSize; i > index; --i) {
        pArr[i] = pArr[i-1];
    }
    pArr[index] = rValue;
    ++mSize;
}

template <typename T>
void DArray<T>::erase(int index) {
    if ((index < 0) || (index >= mSize))
        throw_error(__PRETTY_FUNCTION__, utils::IndexError);

    if (this->empty())
        throw_error(__PRETTY_FUNCTION__, utils::RemoveFromEmptyError);

    for (size_t i = index; i < (mSize - 1); ++i) {
        pArr[i] = pArr[i+1];
    }
    --mSize;
}

template <typename T>
void DArray<T>::shrink_to_fit() {
    if (mSize == mCapacity)
        return;
    
    mCapacity = mSize;
    std::unique_ptr<T[]> newArr(new(std::nothrow) T[mCapacity]); // better to use std::make_unique, but wanted to utilize std::nothrow
    if (newArr == nullptr)
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);   

    for (size_t i{0}; i < mSize; ++i) {
        newArr[i] = pArr[i];
    }
    pArr = std::move(newArr);
}

template <typename T>
void DArray<T>::print() const {
    if (this->empty()) {
        std::cout << "Nothing to print, array is empty" << std::endl;
        return;
    }

    for(size_t i{0}; i < mSize; ++i) {
        std::cout << pArr[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
void DArray<T>::upsize() {
    if (mCapacity == 0) {
        mCapacity = sGrowthFactor;
    } else {
        mCapacity *= sGrowthFactor;
    }

    std::unique_ptr<T[]> newArr(new(std::nothrow) T[mCapacity]); // better to use std::make_unique, but wanted to utilize std::nothrow
    if (newArr == nullptr)
        throw_error(__PRETTY_FUNCTION__, utils::MallocError);   

    for (size_t i{0}; i < mSize; ++i) {
        newArr[i] = pArr[i];
    }
    pArr = std::move(newArr);
}

} // namespace crs (c. roman [data] structures [library])