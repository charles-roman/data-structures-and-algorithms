#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

namespace utils {

// ERROR HANDLING -------------------------------------------------------------------------
enum ErrorType {
    MallocError = 0,
    RemoveFromEmptyError,
    ReadFromEmptyError,
    IndexError,
    SizeDeclarationError,
    SizeOverflowError
};

void throw_error(const std::string &func, const int err);

// SORTING UTILITIES -----------------------------------------------------------------------

// Check if container is sorted
template <typename ForwardIt, typename Compare = std::less<std::iter_value_t<ForwardIt>>>
requires std::totally_ordered<std::iter_value_t<ForwardIt>>
bool is_sorted(ForwardIt begin, ForwardIt end, Compare comp = Compare()) {
    for (auto it = begin; it != std::prev(end); ++it) {
        if (comp(*std::next(it), *it))
            return false;
    }
    return true;
}

// I/O UTILITIES ---------------------------------------------------------------------------
template <typename ForwardIt>
void print_contents(ForwardIt begin, ForwardIt end) {
    if (begin == end)
        return;

    for (auto it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*
    if (key:value associative container)
        std::cout << "{" << it->first << ": " << it->second << "} ";
*/

template <typename Container>
void print_container(const Container& container) {
    if (container.empty()) {
        std::cout << "Container is empty, nothing to print" << std::endl;
        return;
    }

    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

/*
    if (key:value associative container)
        for (const auto& pair : container) {
            std::cout << "{" << pair.first << ": " << pair.second << "} ";
        }
*/

/*
template <typename Container>
void print_container(const Container &cont) {
    if (cont.empty()) {
        std::cout << "Container is empty, nothing to print" << std::endl;
        return;
    }

    if (false //container is unordered associative container) {
        std::copy(cont.begin(), cont.end(), 
                std::ostream_iterator<typename Container::mapped_type>(std::cout, " "));
    } else {
        std::copy(cont.begin(), cont.end(), 
                std::ostream_iterator<typename Container::value_type>(std::cout, " "));
    }
    std::cout << std::endl;
}
*/
    
}   // namespace utils (utilities [library])

#endif  // UTILS_HPP