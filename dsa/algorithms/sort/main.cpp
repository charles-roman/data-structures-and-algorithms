#include <iostream>
#include <vector>
#include "sort.hpp"

int main (int argc, char* argv[]) {

    /* INSERTION SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_insertion = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};

    std::cout << "INSERTION SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_insertion);

    cra::insertion_sort(vec_insertion);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_insertion);

    cra::insertion_sort(vec_insertion, std::greater<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_insertion);
    std::cout << "--------------------------" << std::endl;
    //*/

    /* SELECTION SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_selection = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};

    std::cout << "SELECTION SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_selection);

    cra::selection_sort(vec_selection);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_selection);

    cra::selection_sort(vec_selection, std::greater<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_selection);
    std::cout << "--------------------------" << std::endl;
    //*/

    /* BUBBLE SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_bubble = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};
    
    std::cout << "BUBBLE SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_bubble);

    cra::bubble_sort(vec_bubble);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_bubble);

    cra::bubble_sort(vec_bubble, std::greater<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_bubble);
    std::cout << "--------------------------" << std::endl;
    //*/

    /* MERGE SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_merge = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};
    
    std::cout << "MERGE SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_merge);

    cra::merge_sort(vec_merge.begin(), vec_merge.end() - 1);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_merge);

    cra::merge_sort(vec_merge.begin(), vec_merge.end() - 1, std::greater_equal<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_merge);
    std::cout << "--------------------------" << std::endl;
    //*/

    /* HEAP SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_heap = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};
    
    std::cout << "HEAP SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_heap);

    cra::heap_sort(vec_heap);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_heap);

    cra::heap_sort(vec_heap, std::greater<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_heap);
    std::cout << "--------------------------" << std::endl;
    //*/
    

    /* QUICK SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<int> vec_quick = {2, 4, -1, 3, -4, 0, -2, 5, 0, 1, -3, -5};
    
    std::cout << "QUICK SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_quick);

    cra::quick_sort(vec_quick.begin(), vec_quick.end());

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_quick);

    cra::quick_sort(vec_quick.begin(), vec_quick.end(), std::greater_equal<int>());

    std::cout << "Sorted Array (Descending):" << std::endl;
    utils::print(vec_quick);
    std::cout << "--------------------------" << std::endl;
    //*/

    /* COUNTING SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<unsigned int> vec_count = {2, 4, 1, 3, 5, 1, 3, 3, 3, 6};
    
    std::cout << "COUNTING SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_count);

    cra::counting_sort(vec_count);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_count);
    std::cout << "--------------------------" << std::endl;
    //*/
    
    /* RADIX SORT TEST */
    //*---------------------------------------------------------------------------------
    std::vector<unsigned int> vec_radix = {222, 440, 101, 336, 593, 10, 3, 30, 30, 30};
    
    std::cout << "RADIX SORT" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Original Array:" << std::endl;
    utils::print(vec_radix);

    cra::radix_sort(vec_radix);

    std::cout << "Sorted Array (Ascending):" << std::endl;
    utils::print(vec_radix);
    std::cout << "--------------------------" << std::endl;
    //*/
}