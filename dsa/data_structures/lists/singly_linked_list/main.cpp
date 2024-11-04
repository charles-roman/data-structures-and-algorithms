#include <iostream>
#include "slist.hpp"

int main (int argc, char* argv[]) {
    
    crs::SList<int> slist;

    std::cout << "TEST BEGIN" << std::endl;

    std::cout << "PUSHING FRONT..." << std::endl;
    slist.push_front(0);
    slist.push_front(5);
    slist.push_front(10);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "front: " << slist.front() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "POPPING FRONT..." << std::endl;
    slist.pop_front();
    slist.pop_front();
    slist.pop_front();

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "PUSHING BACK..." << std::endl;
    slist.push_back(6);
    slist.push_back(4);
    slist.push_back(2);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "back: " << slist.back() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "POPPING BACK..." << std::endl;
    slist.pop_back();
    slist.pop_back();
    slist.pop_back();

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "INSERTING..." << std::endl;
    slist.push_front(5);
    slist.insert_after(0, 6);
    slist.insert_after(1, 7);
    slist.insert_after(2, 8);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "value[0]: " << slist.value_at(0) << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    /*
    std::cout << "COPYING..." << std::endl;
    slist2 = slist; // MUST CREATE VALID COPY OPERATORS IN CLASS "SList" AND CLASS "Node"
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "printing slist... \n";
    slist.print();
    std::cout << "printing slist2... \n";
    slist2.print();
    if (slist == slist2) {    // MUST CREATE ==operator in "SList Class"
        std::cout << "copy success!" << std::endl;
    } else {
        std::cout << "copy failure!" << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
    */

    std::cout << "ERASING..." << std::endl;
    slist.erase_after(0);
    slist.erase_after(0);
    slist.erase_after(0);
    slist.pop_front();

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "isempty: " << slist.empty() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "TEST COMPLETE" << std::endl;

    return EXIT_SUCCESS;
}