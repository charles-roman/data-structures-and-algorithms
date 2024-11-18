#ifndef PROJECT_SORT_HPP
#define PROJECT_SORT_HPP

#include <vector>
#include <concepts>
#include "../../utilities/utils.hpp"

namespace cra {

// Insertion Sort -------------------------------------------------------------------- [O(n^2)]
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void insertion_sort(std::vector<T> &vec, const int order = utils::AscendingOrder);

// Selection Sort -------------------------------------------------------------------- [O(n^2)]
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void selection_sort(std::vector<T> &vec, const int order = utils::AscendingOrder);

// Merge Sort ------------------------------------------------------------------------ [O(nlogn)]
template <typename RandomIt>
static void merge(RandomIt begin, RandomIt mid, RandomIt end);

template <typename RandomIt>                // must take only random access iterators
void merge_sort(RandomIt begin, RandomIt end);

// Bubble Sort ----------------------------------------------------------------------- [O(n^2)]
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void bubble_sort(std::vector<T> &vec, const int order = utils::AscendingOrder);

// Heap Sort ------------------------------------------------------------------------- [O(nlogn)]
static int left(const int i);

static int right(const int i);

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
static void heapify(std::vector<T> &vec, const int size, const int i);

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
static void build_heap(std::vector<T> &vec);

template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void heap_sort(std::vector<T> &vec);

// Quick Sort ------------------------------------------------------------------------ [O(nlogn)]
static int random(int low, int high);

template <typename RandomIt>
static RandomIt median_of_3(RandomIt A, RandomIt B, RandomIt C);

template <typename RandomIt>
static RandomIt randomized_partition(RandomIt begin, RandomIt end);

template <typename RandomIt>
void quick_sort(RandomIt begin, RandomIt end);

// Counting Sort --------------------------------------------------------------------- [O()]

// Radix Sort ------------------------------------------------------------------------ [O()]

// Bucket Sort ----------------------------------------------------------------------- [O()]

// More Sorting
/* 
    Tim Sort
    Tree Sort
    Shell Sort
    Cube Sort
    Fuzzy Sort
    Introsort
*/

/*  
    we can coarsen sorting algs like merge_sort and quick_sort by modifying the base case
    to call insertion_sort once the number of elements becomes low enough; benchmarking
    run times would be neccessary to decide when this threshold is appropriately met
*/

}   // cra namespace (c. roman algorithms [library])

#include "sort.tpp"

#endif  // PROJECT_SORT_HPP