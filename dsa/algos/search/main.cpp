#include <iostream>
#include <vector>
#include "search.hpp"

int main (int argc, char* argv[]) {

    std::vector<int> vec = {2, 4, 8, 13, 24};

    int i = cra::lsearch(vec, 24);
    int j = cra::lsearch(vec, 2);
    int k = cra::lsearch(vec, 8);
    int z = cra::lsearch(vec, 69);

    std::cout << "Location of (24): " << i << std::endl;
    std::cout << "Location of (2): " << j << std::endl;
    std::cout << "Location of (8): " << k << std::endl;
    std::cout << "Location of (69): " << z << std::endl;

    int i = cra::bsearch(vec, 24);
    int j = cra::bsearch(vec, 2);
    int k = cra::bsearch(vec, 8);
    int z = cra::bsearch(vec, 69);

    std::cout << "Location of (24): " << i << std::endl;
    std::cout << "Location of (2): " << j << std::endl;
    std::cout << "Location of (8): " << k << std::endl;
    std::cout << "Location of (69): " << z << std::endl;

}