#include <vector>
#include <concepts>

namespace cra {

// linear search
template <typename T>
requires std::equality_comparable<T>
int lsearch(const std::vector<T> &vec, const T val) {
    for (size_t i{0}; i < vec.size(); ++i) {
        if (vec[i] == val) 
            return i;
    }
    return -1;
}

// binary search
template <typename T>
requires std::equality_comparable<T>
int bsearch(const std::vector<T> &vec, const T val) {
    size_t mid;
    size_t begin = 0;
    size_t end = vec.size();

    do {
        mid = (begin + end) / 2;
        if (val == vec[mid]) {
            return mid;
        } else if (val > vec[mid]) {
            begin = mid;
        } else if (val < vec[mid]) {
            end = mid;
        }

    } while ((mid != 0) && (mid != (vec.size() - 1)));
        
    return -1;
}

}   // namespace cra