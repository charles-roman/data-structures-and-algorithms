#include <vector>

// 0/1 Knapsack

// RECURSION_____________________________________________________________________________________________ O(2^n)
int _01_knapsack(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr);

// RECURSION(ALTERNATIVE)________________________________________________________________________________ O(2^n)
int _01_knapsack_alt(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr);

// TOP-DOWN______________________________________________________________________________________________ O(c*n)
int _01_knapsack_top_down(std::vector<int> &profits, std::vector<int> &weights, 
    std::vector<std::vector<int>> &res, int capacity, int curr);

// BOTTOM-UP_____________________________________________________________________________________________ O(c*n)
int _01_knapsack_bottom_up(std::vector<int> &profits, std::vector<int> &weights, int capacity);

// BOTTOM-UP (OPTIMIZED)_________________________________________________________________________________ O(c*n)
int _01_knapsack_bottom_up_opt(std::vector<int> &profits, std::vector<int> &weights, int capacity);


// Unbounded Knapsack

// RECURSION_____________________________________________________________________________________________ O(2^n)
int unbounded_knapsack(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr);

// RECURSION (ALTERNATIVE)_______________________________________________________________________________ O(2^n)
int unbounded_knapsack_alt(std::vector<int> &profits, std::vector<int> &weights, int capacity);

// TOP-DOWN______________________________________________________________________________________________ O()
int unbounded_knapsack_top_down(std::vector<int> &profits, std::vector<int> &weights, 
    std::vector<std::vector<int>> &res, int capacity, int curr);

// BOTTOM-UP_____________________________________________________________________________________________ O()                                                                                        
int unbounded_knapsack_bottom_up(std::vector<int> &profits, std::vector<int> &weights, int capacity);

// BOTTOM UP (OPTIMIZED)_________________________________________________________________________________ O()                                                             
int unbounded_knapsack_bottom_up_opt(std::vector<int> &profits, std::vector<int> &weights, int capacity);