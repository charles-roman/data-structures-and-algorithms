#ifndef PROJECT_MISC_HPP
#define PROJECT_MISC_HPP

#include <vector>
#include <concepts>

namespace cra {

template <typename T>
requires std::integral<T> || std::floating_point<T>
T horner(const std::vector<T> &vec, const T x);

}   // namespace cra

#include "misc.tpp"

#endif