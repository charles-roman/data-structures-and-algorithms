#include <cmath>
#include <ctime>
#include <cstdlib>
#include "sort.hpp"

namespace cra {

// Insertion Sort --------------------------------------------------------------------------
template <CopyableAndTotallyOrdered T, typename Compare>
void insertion_sort(std::vector<T> &vec, Compare comp) {
    for (int i{1}; i < vec.size(); ++i) {
        auto key = vec[i];
        int j = i - 1;
        while ((j >= 0) && (comp(key, vec[j]))) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

// Selection Sort --------------------------------------------------------------------------
template <CopyableAndTotallyOrdered T, typename Compare>
void selection_sort(std::vector<T> &vec, Compare comp) {
    if (utils::is_sorted(vec.begin(), vec.end(), comp))                                                      
        return;

    for (size_t i{0}; i < (vec.size() - 1); ++i) {
        size_t key_index = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (comp(vec[j], vec[key_index]))
                key_index = j;
        }
        std::swap(vec[i], vec[key_index]);
    }
}

// Bubble Sort -----------------------------------------------------------------------------
template <CopyableAndTotallyOrdered T, typename Compare>
void bubble_sort(std::vector<T> &vec, Compare comp) {
    for(size_t i{0}; i < (vec.size() - 1); ++i) {
        for (size_t j = (vec.size() - 1); j > i; --j) {
            if (comp(vec[j], vec[j - 1]))
                std::swap(vec[j], vec[j - 1]);
        }
    }
}

// Merge Sort ------------------------------------------------------------------------------
template <typename RandomIt, typename Compare>
static void merge(RandomIt begin, RandomIt mid, RandomIt end, Compare comp) {
    // Copy
    std::vector<std::iter_value_t<RandomIt>> larr(begin, mid + 1);
    std::vector<std::iter_value_t<RandomIt>> rarr(mid + 1, end + 1);

    // Initialize
    auto left = larr.begin();
    auto right = rarr.begin();
    auto i = begin;

    // Sort
    while ((left != larr.end()) && (right != rarr.end())) {
        if (comp(*left, *right)) {
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

template <ItValCopyableAndTotallyOrdered RandomIt, typename Compare>                 
void merge_sort(RandomIt begin, RandomIt end, Compare comp) {                      
    if (begin >= end)
        return;

    RandomIt mid = begin + ((end - begin) / 2);
    merge_sort(begin, mid, comp);
    merge_sort((mid + 1), end, comp);
    merge(begin, mid, end, comp);
}

// Heap Sort -------------------------------------------------------------------------------  
static size_t left(const size_t i) {
    return (2 * i + 1);
}

static size_t right(const size_t i) {
    return (2 * i + 2);
}

template <typename T, typename Compare>
static void heapify(std::vector<T> &vec, const size_t size, const size_t i, Compare comp) {
    size_t l = left(i);
    size_t r = right(i);
    size_t min_max;

    if ((l < size) && (comp(vec[i], vec[l]))) {
        min_max = l;
    } else {
        min_max = i;
    }

    if ((r < size) && (comp(vec[min_max], vec[r]))) {
        min_max = r;
    }

    if (min_max != i) {
        std::swap(vec[i], vec[min_max]);
        heapify(vec, size, min_max, comp);
    }
}

template <typename T, typename Compare>
static void build_heap(std::vector<T> &vec, Compare comp) {
    for (size_t i = (vec.size() / 2) - 1; i != -1; --i) {
        heapify(vec, vec.size(), i, comp);
    }
}

template <CopyableAndTotallyOrdered T, typename Compare>
void heap_sort(std::vector<T> &vec, Compare comp) {
    size_t size = vec.size();                                                                        
    build_heap(vec, comp);
    for (size_t i = size - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        --size;
        heapify(vec, size, 0, comp);
    }
}

// Quick Sort ------------------------------------------------------------------------------
static int random(const int low, const int high) {
    srand(time(0));
    return rand() % (high - low) + low;
}

template <typename T>
static T median_of_3(T a, T b, T c) {
    return (b > a) == (a > c) ? a : (b > a) != (b > c) ? b : c;
}

template <typename RandomIt>
static RandomIt random_pivot(RandomIt begin, RandomIt end) {
    size_t size = end - begin;

    int i = random(0, size);
    int j = random(0, size);
    int k = random(0, size);

    RandomIt a = begin + i;
    RandomIt b = begin + j;
    RandomIt c = begin + k;

    auto median = median_of_3(*a, *b, *c);

    if (*a == median) {
        return a;
    } else if (*b == median) {
        return b;
    } else {
        return c;
    }
}

template <typename RandomIt, typename Compare>
static RandomIt randomized_partition(RandomIt begin, RandomIt end, Compare comp) {
    RandomIt pivot = random_pivot(begin, end);
    std::swap(*pivot, *(end - 1));
    pivot = (end - 1);

    RandomIt it1 = begin - 1;
    for (RandomIt it2 = begin; it2 != pivot; ++it2) {
        if (comp(*it2, *pivot)) {
            ++it1;
            std::swap(*it1, *it2);
        }
    }
    std::swap(*(it1 + 1), *pivot);
    return (it1 + 1);
}

template <ItValCopyableAndTotallyOrdered RandomIt, typename Compare>
void quick_sort(RandomIt begin, RandomIt end, Compare comp) {
    if (begin < (end - 1)) {
        RandomIt pivot_pos = randomized_partition(begin, end, comp);
        quick_sort(begin, pivot_pos, comp);
        quick_sort(pivot_pos + 1, end, comp);
    }
}

// Counting Sort ---------------------------------------------------------------------------
template <typename T>
requires std::unsigned_integral<T>
void counting_sort(std::vector<T> &input, size_t min, size_t max) {
    if (min == 0)
        min = *std::min_element(input.begin(), input.end());    // note: more efficient to find min/max simultaneously
    
    if (max == 0)
        max = *std::max_element(input.begin(), input.end());

    size_t k = max - min;
    std::vector<T> counter(k + 1, 0);
    std::vector<T> output(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        ++counter[input[i] - min];
    }

    for (size_t i = 1; i <= k; ++i) {   // reverse the direction of this loop to sort in descending order
        counter[i] += counter[i - 1];
    }

    for (size_t i = input.size() - 1; i != -1; --i) {
        size_t pos = counter[input[i] - min] - 1;
        output[pos] = input[i];
        --counter[input[i] - min];
    }

    input = output;

    /*                                          // sorts in place (loses stability)
    size_t i = input.size() - 1;                        
    while (i < input.size()) {                  
        size_t pos = counter[input[i] - min] - 1;
        if (pos == i) {                        
            --counter[input[i] - min];
            --i;
        } else {
            while (input[i] == input[pos]) {
                --pos;                          
            }                                   
            std::swap(input[i], input[pos]);
        }
    }
    */

}

/*
    counting sort can also work for floating point values. the counter array would
    need size (10^d *k) where k is the range and d is the max number of digits 
    after decimal. thus, it only works well for floating point values that have
    a low number of digits after the decimal.
*/

// Radix Sort ------------------------------------------------------------------------------
template <typename T>
static T digits(T num) {
    T d = 0;
    while (num) {
        num /= 10;
        ++d;
    }
    return d;
}

template <typename T>
static void counting_sort_by_digit(std::vector<T> &input, T k, T div) {      // sorts by LSD in base 10
    std::vector<T> counter(k, 0);
    std::vector<T> output(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        ++counter[(input[i] / div) % k];
    }

    for (T i = 1; i < k; ++i) {
        counter[i] += counter[i - 1];
    }

    for (size_t i = input.size() - 1; i != -1; --i) {
        size_t pos = counter[(input[i] / div) % k] - 1;
        output[pos] = input[i];
        --counter[(input[i] / div) % k];
    }

    input = output;
}

template <typename T>
requires std::unsigned_integral<T>
void radix_sort(std::vector<T> &input, T d) {                   // sorts by LSD in base 10
    T max = *std::max_element(input.begin(), input.end());

    if (d == 0) {
        d = digits(max);
    }

    T exp{};
    if (d < log10(input.size())) {
        exp = d;
    } else {
        exp = log10(input.size());
    }

    T k = pow(10, exp);
    for (T div = 1; (max / div) > 0; div *= k) {
        counting_sort_by_digit(input, k, div);
    }
}

// Bucket Sort -----------------------------------------------------------------------------


}   // cra namespace (c. roman algorithms [library])