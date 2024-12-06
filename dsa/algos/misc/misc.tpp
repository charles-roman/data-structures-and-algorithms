#include <vector>
#include <concepts>

namespace cra {

// horner's rule (polynomial evaluation) [O(n)]
template <typename T>
requires std::integral<T> || std::floating_point<T>
T horner(const std::vector<T> &vec, const T x) {
    T p{0};
    for (size_t i = (vec.size() - 1); i >= 0; --i) {
        p = vec[i] + x*p;
    }
    return p;
}

// matrix multiplication


}   // namespace cra