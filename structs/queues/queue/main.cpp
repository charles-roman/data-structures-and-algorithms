#include <iostream>
#include "queue.hpp"

int main(int argv, char* argc[]) {

    crs::Queue<int> q;
    
    std::cout << "BEGIN TEST" << std::endl;

    std::cout << "PUSHING..." << std::endl;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "empty: " << q.empty() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;
    std::cout << "printing...\n";
    q.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "POPPING..." << std::endl;
    q.pop();
    q.pop();
    q.pop();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "empty: " << q.empty() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << "printing...\n";
    q.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "TEST COMPLETE" << std::endl;

    exit(EXIT_SUCCESS);
}