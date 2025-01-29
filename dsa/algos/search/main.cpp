#include <iostream>
#include <vector>
#include "search.hpp"

int main (int argc, char* argv[]) {

    std::vector<int> vec = {2, 4, 8, 13, 24};

    int i = cra::linear_search(vec, 24);
    int j = cra::linear_search(vec, 2);
    int k = cra::linear_search(vec, 8);
    int z = cra::linear_search(vec, 69);

    std::cout << "Location of (24): " << i << std::endl;
    std::cout << "Location of (2): " << j << std::endl;
    std::cout << "Location of (8): " << k << std::endl;
    std::cout << "Location of (69): " << z << std::endl;

    i = cra::binary_search(vec, 24);
    j = cra::binary_search(vec, 2);
    k = cra::binary_search(vec, 8);
    z = cra::binary_search(vec, 69);

    std::cout << "Location of (24): " << i << std::endl;
    std::cout << "Location of (2): " << j << std::endl;
    std::cout << "Location of (8): " << k << std::endl;
    std::cout << "Location of (69): " << z << std::endl;

}