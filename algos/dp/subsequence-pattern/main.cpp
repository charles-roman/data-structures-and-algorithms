#include <iostream>
#include "subsequence.hpp"

int main(int argc, char* argv[]) {

    // 0/1 Knapsack---------------------------------------------------------------------------

    // INITIALIZE
    std::vector<int> profits = {1, 5, 10, 16};
    std::vector<int> weights = {1, 2, 3, 5};
    int capacity = 6;

    // RECURSION
    std::cout << _01_knapsack(profits, weights, capacity, 0) << std::endl;
    std::cout << _01_knapsack_alt(profits, weights, capacity, 0) << std::endl;
    
    // TOP-DOWN
    std::vector<std::vector<int>> res(profits.size(), std::vector<int>(capacity + 1, -1));
    std::cout << _01_knapsack_top_down(profits, weights, res, capacity, 0) << std::endl;
    
    // BOTTOM-UP
    std::cout << _01_knapsack_bottom_up(profits, weights, capacity) << std::endl;
    std::cout << _01_knapsack_bottom_up_opt(profits, weights, capacity) << std::endl;


    // Unbounded Knapsack---------------------------------------------------------------------

    // INITIALIZE
    profits = {15, 50, 60, 90};
    weights = {1, 3, 4, 5};
    capacity = 10;
    
    // RECURSION
    std::cout << unbounded_knapsack(profits, weights, capacity, 0) << std::endl;
    std::cout << unbounded_knapsack_alt(profits, weights, capacity) << std::endl;
    
    // TOP-DOWN
    std::vector<std::vector<int>> res(profits.size(), std::vector<int>(capacity + 1, -1));
    std::cout << unbounded_knapsack_top_down(profits, weights, res, capacity, 0) << std::endl;
    
    // BOTTOM-UP
    std::cout << unbounded_knapsack_bottom_up(profits, weights, capacity) << std::endl;
    std::cout << unbounded_knapsack_bottom_up_opt(profits, weights, capacity) << std::endl;

    return 0;
}