#include <iostream>
#include <string>
#include "utils.hpp"

namespace utils {

void throw_error(const std::string &func, const int err = -1) {

    std::string err_str;

    switch (err) {
        case MallocError: 
            err_str = "memory allocation failure";
            break;
        case RemoveFromEmptyError:
            err_str = "cannot remove element from empty object";
            break;
        case ReadFromEmptyError:
            err_str = "cannot read element from empty object";
            break;
        case IndexError:
            err_str = "index out of bounds";
            break;
        case SizeDeclarationError:
            err_str = "improper size declaration";
            break;
        case SizeOverflowError:
            err_str = "overflow occurred";
            break;
        default:
            err_str = "fatal error occurred";
    }
    std::cerr << "\nERROR using " << func << "; " << err_str << "\n" << std::endl;
    exit(EXIT_FAILURE);
}

}   // namespace utils (utilities [library])