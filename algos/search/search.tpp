#include <vector>
#include <concepts>

namespace cra {

// linear search
template <typename T>
requires std::equality_comparable<T>
int linear_search(const std::vector<T>& vec, const T& val) {
    for (size_t i{0}; i < vec.size(); ++i) {
        if (vec[i] == val) 
            return i;
    }
    return -1;
}

// binary search
template <typename T>
requires std::equality_comparable<T>
int binary_search(const std::vector<T>& vec, const T& val) {
    int l = 0, r = vec.size() - 1;
    while (l <= r) {
        int m = l + (r - l + 1) / 2;
        if (vec[m] > val) {
            r = m - 1;
        } else if (vec[m] < val) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return -1;
}

}   // namespace cra