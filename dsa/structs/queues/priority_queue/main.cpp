#include <iostream>
#include "pqueue.hpp"

int main (int argc, char* argv[]) {

    std::vector<int> vec = {3, 6, 9, 5, 4, 12, 10};
    
    crs::PQueue<int> pq;
    
    std::cout << "BEGIN TEST" << std::endl;

    std::cout << "PUSHING..." << std::endl;

    for (auto v : vec) {
        pq.push(v);
    }
    
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << pq.size() << std::endl;
    std::cout << "empty: " << pq.empty() << std::endl;
    std::cout << "top: " << pq.top() << std::endl;
    std::cout << "printing...\n";
    std::cout << "order of push: ";
    utils::print_container(vec);
    std::cout << "order of queue: ";
    pq.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "POPPING..." << std::endl;
    pq.pop();
    pq.pop();
    pq.pop();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << pq.size() << std::endl;
    std::cout << "empty: " << pq.empty() << std::endl;
    std::cout << "top: " << pq.top() << std::endl;
    std::cout << "printing...\n";
    std::cout << "queue: ";
    pq.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "TEST COMPLETE" << std::endl;

}