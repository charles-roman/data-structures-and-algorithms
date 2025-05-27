#include <vector>
#include <iostream>
#include "stack.hpp"

int main(int argv, char* argc[]) {

    crs::Stack<int, std::vector<int>> stk;
    
    std::cout << "BEGIN TEST" << std::endl;

    std::cout << "PUSHING..." << std::endl;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << stk.size() << std::endl;
    std::cout << "top: " << stk.top() << std::endl;
    std::cout << "printing...\n";
    stk.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "POPPING..." << std::endl;
    stk.pop();
    stk.pop();
    stk.pop();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << stk.size() << std::endl;
    std::cout << "printing...\n";
    stk.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "TEST COMPLETE" << std::endl;

    exit(EXIT_SUCCESS);
}