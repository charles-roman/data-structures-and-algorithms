#ifndef PROJECT_MISC_HPP
#define PROJECT_MISC_HPP

#include <vector>
#include <concepts>

namespace cra {

// linear search (O(n))
template <typename T>
requires std::equality_comparable<T>
int lsearch(const std::vector<T> &vec, const T val);

// binary search (O(logn))
template <typename T>
requires std::equality_comparable<T>
int bsearch(const std::vector<T> &vec, const T val);

}   // namespace cra

#include "search.tpp"

#endif  // PROJECT_MISC_HPP