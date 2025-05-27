#include <iostream>
#include "darray.hpp"

int main (int argc, char* argv[]) {
    
    crs::DArray<int> dArr;
    crs::DArray<int> _dArr(3);
    
    std::cout << "BEGIN TEST" << std::endl;

    std::cout << "PUSHING..." << std::endl;
    dArr.push_back(1);
    dArr.push_back(2);
    dArr.push_back(3);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "at(0): " << dArr.at(0) << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "POPPING..." << std::endl;
    dArr.pop_back();
    dArr.pop_back();
    dArr.pop_back();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "INSERTING..." << std::endl;
    dArr.insert(0, 4);
    dArr.insert(0, 5);
    dArr.insert(0, 6);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "dArr[0]: " << dArr[0] << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "ERASING..." << std::endl;
    dArr.erase(0);
    dArr.erase(0);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "SHRINKING..." << std::endl;
    dArr.shrink_to_fit();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::cout << "CLEARING..." << std::endl;
    dArr.clear();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "PUSHING..." << std::endl;
    _dArr.push_back(1);
    _dArr.push_back(2);
    _dArr.push_back(3);
    std::cout << "-----------------------------" << std::endl;
    std::cout << "_size: " << _dArr.size() << std::endl;
    std::cout << "_capacity: " << _dArr.capacity() << std::endl;
    std::cout << "_printing...\n";
    _dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "COPYING..." << std::endl;
    dArr = _dArr;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "size: " << dArr.size() << std::endl;
    std::cout << "capacity: " << dArr.capacity() << std::endl;
    std::cout << "printing...\n";
    dArr.print();
    std::cout << "-----------------------------" << std::endl;

    std::cout << "TEST COMPLETE";
}