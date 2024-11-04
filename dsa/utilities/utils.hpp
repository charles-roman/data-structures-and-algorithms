#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

#ifndef UTILS_HPP
#define UTILS_HPP

namespace utils {

// ERROR HANDLING -------------------------------------------------------------------------
enum ErrorType {
    MallocError = 0,
    EmptyError,
    IndexError,
    SizeError
};

void throw_error(const std::string &func, const int err);

// SORTING UTILITIES -----------------------------------------------------------------------
enum OrderSpec {
    AscendingOrder = 0,
    DescendingOrder
};

// Check if array is sorted
template <typename T>
bool is_sorted(std::vector<T> &vec, const int order = utils::AscendingOrder) {
    if (order == utils::AscendingOrder) {
        for (auto it = vec.begin(); it != (vec.end() - 1); ++it) {
            if (*it > *(it + 1))
                return false;
        }
    } else if (order == utils::DescendingOrder) {
        for (auto it = vec.begin(); it != (vec.end() - 1); ++it) {
            if (*it < *(it + 1))
                return false;
        }
    }
    return true;
}

// I/O UTILITIES ---------------------------------------------------------------------------
template <typename Container>
void print(const Container &cont) {
    if (cont.empty()) {
        std::cout << "Container is empty, nothing to print" << std::endl;
        return;
    }

    // This adds support for mapped containers
    /*
    if (container is unordered associative container) {
        std::copy(cont.begin(), cont.end(), 
                std::ostream_iterator<typename container::mapped_type>(std::cout, " "));
    } else {
        std::copy(cont.begin(), cont.end(), 
                std::ostream_iterator<typename container::value_type>(std::cout, " "));
    }
    */

    std::copy(cont.begin(), cont.end(),
              std::ostream_iterator<typename Container::value_type>(std::cout, " "));

    std::cout << std::endl;
}
    
}   // namespace utils (utilities [library])

#endif  // UTILS_HPP