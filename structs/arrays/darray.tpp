#include <iostream>
#include "darray.hpp"
#include "../../utils/utils.hpp"

namespace crs {

template <typename T>
DArray<T>::DArray(size_t size)
    : mSize(size), mCapacity(size), pArr(std::make_unique<T[]>(mCapacity)) {
    // could catch std::bad_alloc if desired
}

template <typename T>
DArray<T>::DArray(const DArray& dArr)
    : mSize(dArr.mSize), mCapacity(dArr.mCapacity), pArr(std::make_unique<T[]>(dArr.mCapacity)) {
    for(size_t i = 0; i < dArr.mSize; ++i) {
        pArr[i] = dArr.pArr[i];
    }
}

template <typename T>
DArray<T>::DArray(DArray&& dArr) noexcept
    : mSize(dArr.mSize), mCapacity(dArr.mCapacity), pArr(std::move(dArr.pArr)) {
    dArr.mSize = 0;
    dArr.mCapacity = 0;
}

template <typename T>
DArray<T>& DArray<T>::operator=(const DArray& dArr) {
    if (this != &dArr) {
        mSize = dArr.mSize;
        mCapacity = dArr.mCapacity;
        pArr = std::make_unique<T[]>(dArr.mCapacity);
        for(size_t i = 0; i < dArr.mSize; ++i) {
            pArr[i] = dArr.pArr[i];
        }
    }
    return *this;
}

template <typename T>
DArray<T>& DArray<T>::operator=(DArray&& dArr) noexcept {
    if (this != &dArr) {
        mSize = dArr.mSize;
        mCapacity = dArr.mCapacity;
        pArr = std::move(dArr.pArr);

        dArr.mSize = 0;
        dArr.mCapacity = 0;
    }
    return *this;
}

template <typename T>
T& DArray<T>::operator[](size_t index) {
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
void DArray<T>::clear() {
    mSize = 0;
}

template <typename T>
T& DArray<T>::at(size_t index) const {
    if (index >= mSize)
        throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

    return pArr[index];
}

template <typename T>
void DArray<T>::push_back(const T &value) {
    if (mSize == mCapacity)
        this->upsize();

    pArr[mSize] = value;
    ++mSize;
}

template <typename T>
void DArray<T>::pop_back() {
    if (this->empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    --mSize;
}

template <typename T>
void DArray<T>::insert(size_t index, const T &value) {
    if (index > mSize)
        throw std::out_of_range(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

    if (mSize == mCapacity)
        this->upsize();
        
    for (size_t i = mSize; i > index; --i) {
        pArr[i] = pArr[i - 1];
    }
    pArr[index] = value;
    ++mSize;
}

template <typename T>
void DArray<T>::erase(size_t index) {
    if (this->empty())
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::RemoveFromEmpty));

    if (index >= mSize)
        throw std::runtime_error(err_msg(__PRETTY_FUNCTION__, utils::OutOfRange));

    for (size_t i = index; i < (mSize - 1); ++i) {
        pArr[i] = pArr[i + 1];
    }
    --mSize;
}

template <typename T>
void DArray<T>::shrink_to_fit() {
    if (mSize == mCapacity)
        return;
    
    mCapacity = mSize;
    std::unique_ptr<T[]> newArr = std::make_unique<T[]>(mCapacity); // could catch std::bad_alloc if desired   

    for (size_t i = 0; i < mSize; ++i) {
        newArr[i] = std::move(pArr[i]);
    }
    pArr = std::move(newArr);
}

template <typename T>
void DArray<T>::print() const {
    if (this->empty()) {
        std::cout << "Nothing to print, array is empty" << std::endl;
        return;
    }

    for(size_t i = 0; i < mSize; ++i) {
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

    std::unique_ptr<T[]> newArr = std::make_unique<T[]>(mCapacity); // could catch std::bad_alloc if desired   

    for (size_t i = 0; i < mSize; ++i) {
        newArr[i] = std::move(pArr[i]);
    }
    pArr = std::move(newArr);
}

} // namespace crs (c. roman [data] structures [library])