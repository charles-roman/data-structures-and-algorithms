#include <vector>
#include "select.hpp"

int main (int argc, char* argv[]) {

    /* MIN ELEMENT TEST */
    //*-------------------------------------------------------------------------------------
    std::vector<int> min_vec = {-3, -2, -1, 0, 0, 1, 2, 3};

    std::cout << "MIN ELEMENT" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Vector: ";
    utils::print_container(min_vec);

    auto min = *cra::minimum(min_vec.begin(), min_vec.end());

    std::cout << "min: " << min << std::endl;
    std::cout << "-----------------------------" << std::endl;
    //*/

    /* MAX ELEMENT TEST */
    //*-------------------------------------------------------------------------------------
    std::vector<int> max_vec = {-3, -2, -1, 0, 0, 1, 2, 3};

    std::cout << "MAX ELEMENT" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Vector: ";
    utils::print_container(max_vec);

    auto max = *cra::maximum(max_vec.begin(), max_vec.end());

    std::cout << "max: " << max << std::endl;
    std::cout << "-----------------------------" << std::endl;
    //*/

    /* MIN/MAX ELEMENT TEST */
    //*-------------------------------------------------------------------------------------
    using it = std::vector<int>::iterator;

    std::cout << "MIN_MAX ELEMENT" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::vector<int> odd_vec = {2, -3, 0, 6, -4, 8, 12};

    std::cout << "Vector w/ odd number of elements: ";
    utils::print_container(odd_vec);

    std::pair<it, it> odd_min_max = cra::min_max_elements(odd_vec.begin(), odd_vec.end());

    std::cout << "min: " << *odd_min_max.first << std::endl;
    std::cout << "max: " << *odd_min_max.second << std::endl;

    std::vector<int> even_vec = {2, -3, 6, 0, -4, 8, 12, 5};

    std::cout << "Vector w/ even number of elements: ";
    utils::print_container(even_vec);

    std::pair<it, it> even_min_max = cra::min_max_elements(even_vec.begin(), even_vec.end());

    std::cout << "min: " << *even_min_max.first << std::endl;
    std::cout << "max: " << *even_min_max.second << std::endl;
    std::cout << "-----------------------------" << std::endl;
    //*/

    /* SELECT */
    //*-------------------------------------------------------------------------------------
    std::vector<int> select_vec = {-3, -2, -1, 0, 0, 1, 2, 3};
    unsigned int i = 5U;

    std::cout << "SELECT ith ORDER STATISTIC" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Vector: ";
    utils::print_container(select_vec);

    auto ith = *cra::select(select_vec.begin(), select_vec.end(), i);

    std::cout << i << "th Order Statistic: " << ith << std::endl;
    //*/

    exit(EXIT_SUCCESS);
}