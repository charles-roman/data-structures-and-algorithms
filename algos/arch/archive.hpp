#include <vector>

// Insertion Sort ------------------------------------------------- (Written as a Recursive Algorithm)
template <typename T>
void rec_isort(std::vector<T> &vec) {
    static size_t i{0};
    static size_t current{0};

    auto key = vec[i + 1];
    if (vec[i] > key) {
        std::swap(vec[i], vec[i + 1]);
        if (i > 0) {
            --i;
            isort(vec);
        }
    }
    i = current;
    ++i;
    ++current;
    if (current >= (vec.size() - 1))
        return;

    isort(vec);
}

// Counting Sort ------------------------------------------------- (Sorts Input Array in Place)

/*
    size_t i = input.size() - 1;                    // sorts in place 
    while (i < input.size()) {
        T pos = counter[input[i]] - 1;
        if (pos == i) {                        
            --counter[input[i]];
            --i;
        } else {
            while (input[i] == input[pos]) {
                --pos;
            } 
            std::swap(input[i], input[pos]);
        }
    }

*/

// Merge Sort ------------------------------------------------- (using iterators)
template<typename It>
concept ItValCopyableAndTotallyOrdered = std::copyable<std::iter_value_t<It>> &&
                                         std::totally_ordered<std::iter_value_t<It>>;

template <typename RandomIt, typename Compare>
static void merge(RandomIt begin, RandomIt mid, RandomIt end, Compare comp);

template <ItValCopyableAndTotallyOrdered RandomIt, 
            typename Compare = std::less_equal<std::iter_value_t<RandomIt>>>
void merge_sort(RandomIt begin, RandomIt end, Compare comp = Compare());      // end iterator must point to last element

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