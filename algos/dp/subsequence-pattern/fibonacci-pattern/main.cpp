#include <iostream>
#include "fibonacci.hpp"

int main(int argc, char* argv[]) {
    // Write C++ code here
    int n = 5;
    
    // RECURSION
    std::cout << fib(5) << std::endl;
    
    // TOP-DOWN
    std::vector<int> res(n + 1, -1);
    std::cout << fib_top_down(5, res) << std::endl;
    
    // BOTTOM-UP
    std::cout << fib_bottom_up(5) << std::endl;
    std::cout << fib_bottom_up_opt(5) << std::endl;

    return 0;
}