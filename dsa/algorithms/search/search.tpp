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

}   // namespace cra