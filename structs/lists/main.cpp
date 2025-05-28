#include <iostream>
#include "slist.hpp"

int main (int argc, char* argv[]) {
    
    crs::SList<int> slist;
    crs::SList<int> slist2(3, 0);

    std::cout << "TEST BEGIN" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "INITIAL SLIST..." << std::endl;
    std::cout << "slist: ";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "INITIAL SLIST2..." << std::endl;
    std::cout << "slist2: ";
    slist2.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "PUSHING FRONT..." << std::endl;
    slist.push_front(0);
    slist.push_front(5);
    slist.push_front(10);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "empty: " << slist.empty() << std::endl;
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
    std::cout << "empty: " << slist.empty() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "PUSHING BACK..." << std::endl;
    slist.push_back(6);
    slist.push_back(4);
    slist.push_back(2);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "empty: " << slist.empty() << std::endl;
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
    std::cout << "empty: " << slist.empty() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "INSERTING..." << std::endl;
    slist.push_front(5);
    slist.insert_after(0, 6);
    slist.insert_after(1, 7);
    slist.insert_after(2, 8);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "at(0): " << slist.at(0) << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "empty: " << slist.empty() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "ERASING..." << std::endl;
    slist.erase_after(0);

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "empty: " << slist.empty() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "REVERSING..." << std::endl;
    slist.reverse();

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "COPYING..." << std::endl;
    crs::SList<int> slist_copy = slist;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "printing slist... \n";
    slist.print();
    std::cout << "printing slist_copy... \n";
    slist_copy.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "CLEARING..." << std::endl;
    slist.clear();

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "size: " << slist.size() << std::endl;
    std::cout << "empty: " << slist.empty() << std::endl;
    std::cout << "printing... \n";
    slist.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "TEST COMPLETE" << std::endl;

    exit(EXIT_SUCCESS);
}