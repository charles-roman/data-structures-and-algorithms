#include <iostream>
#include <string>
#include "utils.hpp"

namespace utils {

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
        case Underflow:
            err_msg = "underflow occurred";
            break;
        default:
            err_msg = "fatal error occurred";
    }
    err_str = "ERROR using " + func + "; " + err_msg;

    return err_str;
}

}   // namespace utils (utilities [library])