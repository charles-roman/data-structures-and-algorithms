#include <iostream>
#include <vector>
#include "sort.hpp"

int main (int argc, char* argv[]) {

    std::vector<int> vec = {2, 4, 1, 3, 5};

    /*
    std::vector<int> vec2 = vec;

    std::cout << "INSERTION SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec2);

    cra::isort(vec2);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec2);

    cra::isort(vec2, utils::DescendingOrder);

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec2);
    std::cout << "--------------------------" << std::endl;
    */

    /*
    std::vector<int> vec2 = vec;

    std::cout << "SELECTION SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec2);

    cra::ssort(vec2);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec2);

    cra::ssort(vec2, utils::DescendingOrder);

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec2);

    std::cout << "--------------------------" << std::endl;
    */

    /*
    std::vector<int> vec2 = vec;
    
    std::cout << "MERGE SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec2);

    cra::msort(vec2.begin(), vec2.end());

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec2);
    std::cout << "--------------------------" << std::endl;
    */

    std::vector<int> vec2 = vec;
    
    std::cout << "BUBBLE SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec2);

    cra::bubble_sort(vec2);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec2);

    cra::bubble_sort(vec2, utils::DescendingOrder);

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec2);

    std::cout << "--------------------------" << std::endl;

}