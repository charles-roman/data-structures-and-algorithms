#ifndef PROJECT_SORT_HPP
#define PROJECT_SORT_HPP

#include <vector>
#include <concepts>
#include "../../utils/utils.hpp"

namespace cra {

template<typename T>
concept CopyableAndTotallyOrdered = std::copyable<T> && std::totally_ordered<T>;

template<typename It>
concept ItValCopyableAndTotallyOrdered = std::copyable<std::iter_value_t<It>> &&
                                         std::totally_ordered<std::iter_value_t<It>>;

// Insertion Sort ------------------------------------------------------------------------ [O(n^2)]
template <CopyableAndTotallyOrdered T, typename Compare = std::less<T>>
void insertion_sort(std::vector<T> &vec, Compare comp = Compare());

// Selection Sort ------------------------------------------------------------------------ [O(n^2)]
template <CopyableAndTotallyOrdered T, typename Compare = std::less<T>>
void selection_sort(std::vector<T> &vec, Compare comp = Compare());

// Bubble Sort --------------------------------------------------------------------------- [O(n^2)]
template <CopyableAndTotallyOrdered T, typename Compare = std::less<T>>
void bubble_sort(std::vector<T> &vec, Compare comp = Compare());

// Merge Sort ---------------------------------------------------------------------------- [O(nlogn)]
template <typename RandomIt, typename Compare>
static void merge(RandomIt begin, RandomIt mid, RandomIt end, Compare comp);

template <ItValCopyableAndTotallyOrdered RandomIt, 
            typename Compare = std::less_equal<std::iter_value_t<RandomIt>>>
void merge_sort(RandomIt begin, RandomIt end, Compare comp = Compare());      // end iterator must point to last element 

// Heap Sort ----------------------------------------------------------------------------- [O(nlogn)]
static size_t left(const size_t i);

static size_t right(const size_t i);

template <typename T, typename Compare>
static void heapify(std::vector<T> &vec, const size_t size, const size_t i, Compare comp);

template <typename T, typename Compare>
static void build_heap(std::vector<T> &vec, Compare comp);

template <CopyableAndTotallyOrdered T, typename Compare = std::less<T>>
void heap_sort(std::vector<T> &vec, Compare comp = Compare());

// Quick Sort ---------------------------------------------------------------------------- [O(nlogn)]
static int random(const int low, const int high);

template <typename T>
static T median_of_3(T a, T b, T c);

template <typename RandomIt>
static RandomIt random_pivot(RandomIt begin, RandomIt end);

template <typename RandomIt, typename Compare>
static RandomIt randomized_partition(RandomIt begin, RandomIt end, Compare comp);

template <ItValCopyableAndTotallyOrdered RandomIt, 
            typename Compare = std::less_equal<std::iter_value_t<RandomIt>>>
void quick_sort(RandomIt begin, RandomIt end, Compare comp = Compare());

// Counting Sort ------------------------------------------------------------------------- [O(n+k)] (k = max - min)
template <typename T>
requires std::unsigned_integral<T>
void counting_sort(std::vector<T> &input, size_t min = 0, size_t max = 0);  

// Radix Sort ---------------------------------------------------------------------------- [O(d(n+k))]
template <typename T>
static T digits(T num);

template <typename T>
static void counting_sort_by_digit(std::vector<T> &input, T k, T div);

template <typename T>
requires std::unsigned_integral<T>
void radix_sort(std::vector<T> &input, T d = 0);

// Bucket Sort --------------------------------------------------------------------------- [O()]

// More Sorting
/* 
    Tim Sort
    Tree Sort
    Shell Sort
    Cube Sort
    Bitonic Sort
    Polyphase Sort
    Tape Sort
    Fuzzy Sort
    Introsort
    External Sorting
*/

/*  
    we can coarsen sorting algs like merge_sort and quick_sort by modifying the base case
    to call insertion_sort once the number of elements becomes low enough; benchmarking
    run times would be neccessary to decide when this threshold is appropriately met
*/

}   // cra namespace (c. roman algorithms [library])

#include "sort.tpp"

#endif  // PROJECT_SORT_HPP