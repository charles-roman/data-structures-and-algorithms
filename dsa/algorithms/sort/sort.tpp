#include <cmath>
#include <vector>
#include <concepts>
#include "../../utilities/utils.hpp"

namespace cra {

// should T requirements be std::integral<T> || std::floating_point<T> ? what custom objects would be sorted ?
// does three_way_comparable<T> behave as expected ?

// Insertion Sort --------------------------------------------------------------------
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void isort(std::vector<T> &vec, const int order) {
    if (order == utils::AscendingOrder) {
        for (int i{1}; i < vec.size(); ++i) {
            auto key = vec[i];
            int j = i - 1;
            while ((j >= 0) && (vec[j] > key)) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = key;
        }
    } else if (order == utils::DescendingOrder) {
        for (int i{1}; i < vec.size(); ++i) {
            auto key = vec[i];
            int j = i - 1;
            while ((j >= 0) && (vec[j] < key)) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = key;
        }
    }
}

// Selection Sort --------------------------------------------------------------------
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void ssort(std::vector<T> &vec, const int order) {
    if (is_sorted(vec, order))
        return;

    if (order == utils::AscendingOrder) {
        for (size_t i{0}; i < (vec.size() - 1); ++i) {
            size_t key_index = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[key_index])
                    key_index = j;
            }
            std::swap(vec[i], vec[key_index]);
        }
    } else if (order == utils::DescendingOrder) {
        for (size_t i{0}; i < (vec.size() - 1); ++i) {
            size_t key_index = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] > vec[key_index])
                    key_index = j;
            }
            std::swap(vec[i], vec[key_index]);
        }
    }
}

// Merge Sort ------------------------------------------------------------------------
template <typename RandomIt>
static void merge(RandomIt begin, RandomIt mid, RandomIt end) {

    // Copy
    std::vector<std::iter_value_t<RandomIt>> larr(begin, mid);
    std::vector<std::iter_value_t<RandomIt>> rarr(mid, end);

    // Initialize
    auto left = larr.begin();
    auto right = rarr.begin();
    auto i = begin;

    // Sort
    while ((left != larr.end()) && (right != rarr.end())) {
        if (*left < *right) {
            *i = std::move(*left);
            ++left;
        } else {
            *i = std::move(*right);
            ++right;
        }
        ++i;
    }

    while (left != larr.end()) {
        *i = std::move(*left);
        ++left;
        ++i;
    }

    while (right != rarr.end()) {
        *i = std::move(*right);
        ++right;
        ++i;
    }

}

template <typename RandomIt>                // must take only random access iterators
void msort(RandomIt begin, RandomIt end) {

    if (begin >= end)
        return;

    auto mid = begin + ((end - begin) / 2);
    msort(begin, mid);
    msort((mid + 1), end);
    merge(begin, mid, end);
}

// Bubble Sort -----------------------------------------------------------------------
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void bubble_sort(std::vector<T> &vec, const int order) {
    if (order == utils::AscendingOrder) {
        for(size_t i{0}; i < (vec.size() - 1); ++i) {
            for (size_t j = (vec.size() - 1); j > i; --j) {
                if (vec[j] < vec[j - 1])
                    std::swap(vec[j], vec[j - 1]);
            }
        }
    } else if (order == utils::DescendingOrder) {
        for(size_t i{0}; i < (vec.size() - 1); ++i) {
            for (size_t j = (vec.size() - 1); j > i; --j) {
                if (vec[j] > vec[j - 1])
                    std::swap(vec[j], vec[j - 1]);
            }
        }
    }
}

// Heap Sort -------------------------------------------------------------------------
static int left(const int i) {
    return (2 * i + 1);
}

static int right(const int i) {
    return (2 * i + 2);
}

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
static void heapify(std::vector<T> &vec, const int size, const int i) {
    int l = left(i);
    int r = right(i);
    int largest;

    if ((l < size) && (vec[l] > vec[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < size) && (vec[r] > vec[largest])) {
        largest = r;
    }

    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        heapify(vec, size, largest);
    }
}

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
static void build_heap(std::vector<T> &vec) {
    for (int i = std::floor(vec.size() / 2.0f) - 1; i >= 0; --i) {
        heapify(vec, vec.size(), i);
    }
}

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void heap_sort(std::vector<T> &vec) {
    build_heap(vec);
    int size = vec.size();
    for (int i = vec.size() - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        --size;
        heapify(vec, size, 0);
    }
}

// Quick Sort ------------------------------------------------------------------------

// Counting Sort ---------------------------------------------------------------------

// Radix Sort ------------------------------------------------------------------------

// Bucket Sort -----------------------------------------------------------------------

// external sorting?

}   // cra namespace (c. roman algorithms [library])