#include "select.hpp"
#include "../../utils/utils.hpp"

namespace cra {

// Select Minimum --------------------------------------------------------------------
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
ForwardIt minimum(ForwardIt begin, ForwardIt end) {
    if (begin == end)
        return end;

    ForwardIt min = begin;
    while(++begin != end) {
        if (*begin < *min)
            min = begin;
    }
    return min;
}

// Select Maximum --------------------------------------------------------------------
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
ForwardIt maximum(ForwardIt begin, ForwardIt end) {
    if (begin == end)
        return end;

    auto max = begin;
    while(++begin != end) {
        if (*begin > *max)
            max = begin;
    }
    return max;
}

// Select Min and Max Simultaneously -------------------------------------------------
template <class ForwardIt>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
std::pair<ForwardIt, ForwardIt> min_max_elements(ForwardIt begin, ForwardIt end) {
    // Empty Check
    if (begin == end) return {end, end};

    // Singular Element Check
    if (end == std::next(begin)) return {begin, begin};

    // Initialize
    size_t size = std::distance(begin, end);
    auto it = begin;
    auto min = begin;
    auto max = begin;
    
    // Check for Odd Number of Elements
    if (utils::is_odd(size)) it = std::next(begin);
    

    for(it; it != end; std::advance(it, 2)) {
        if (*it > *std::next(it)) {
            if (*it > *max) max = it;
            if (*std::next(it) < *min) min = std::next(it);
        } else {
            if (*it < *min) min = it;
            if (*std::next(it) > *max) max = std::next(it);
        }
    }

    return {min, max};
}

// Select ith Order Statistic --------------------------------------------------------
template <typename ForwardIt>
static ForwardIt randomized_partition(ForwardIt begin, ForwardIt end) {
    // Get size of current partition
    size_t size = std::distance(begin, end);

    // Calculate a random pivot from partition to be used as a pivot
    auto rnum = utils::random_int(0ULL, size - 1);
    auto pivot = begin + rnum;

    // Place pivot at end of partition
    std::swap(*pivot, *std::prev(end));
    pivot = std::prev(end);

    auto it1 = std::prev(begin);
    for (auto it2 = begin; it2 != pivot; ++it2) {
        if (*it2 <= *pivot) {
            ++it1;
            std::swap(*it1, *it2);
        }
    }
    std::swap(*(std::next(it1)), *pivot);
    pivot = std::next(it1);

    return pivot;
}

template <ItValSwappableAndTotallyOrdered ForwardIt, UnsignedIntegral T>
ForwardIt select(ForwardIt begin, ForwardIt end, T i) {
    // Empty Check
    if (begin == end) return end;

    if (begin == std::prev(end)) return begin;

    auto pivot = randomized_partition(begin, end);
    T k = std::distance(begin, pivot) + 1;  // size of new range

    if (i == k) {
        return pivot;
    } else if (i < k) {
        return select(begin, pivot, i);
    } else {
        return select(++pivot, end, i - k);
    }

}

}   // cra namespace (c. roman algorithms [library])