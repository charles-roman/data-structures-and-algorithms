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

std::string err_msg(const std::string &func, ErrorMsg msg) {

    std::string err_msg;
    std::string err_str;

    switch (msg) {
        case BadAlloc: 
            err_msg = "memory allocation failure";
            break;
        case RemoveFromEmpty:
            err_msg = "cannot remove element from empty object";
            break;
        case ReadFromEmpty:
            err_msg = "cannot read element from empty object";
            break;
        case OutOfRange:
            err_msg = "index out of range";
            break;
        case Overflow:
            err_msg = "overflow occurred";
            break;
        default:
            err_msg = "fatal error occurred";
    }
    err_str = "ERROR using " + func + "; " + err_msg;

    return err_str;
}

}   // namespace utils (utilities [library])