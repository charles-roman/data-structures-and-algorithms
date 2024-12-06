#ifndef SELECT_HPP
#define SELECT_HPP

#include <concepts>

namespace cra {

template<class It>
concept ItValSwappableAndTotallyOrdered = std::swappable<std::iter_value_t<It>> &&
                                         std::totally_ordered<std::iter_value_t<It>>;

template<class T>
concept UnsignedIntegral = std::unsigned_integral<T>;

// Select Minimum   (std::min_element)
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
ForwardIt minimum(ForwardIt begin, ForwardIt end);

// Select Maximum   (std::max_element)
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
ForwardIt maximum(ForwardIt begin, ForwardIt end);

// Select Min and Max Simultaneously
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
std::pair<ForwardIt, ForwardIt> min_max_elements(ForwardIt begin, ForwardIt end);

// Select ith Order Statistic   (std::nth_element)
template <typename ForwardIt>
static ForwardIt randomized_partition(ForwardIt begin, ForwardIt end);

template <ItValSwappableAndTotallyOrdered ForwardIt, UnsignedIntegral T>
ForwardIt select(ForwardIt begin, ForwardIt end, T i);

}   // cra namespace (c. roman algorithms [library])

#include "select.tpp"

#endif