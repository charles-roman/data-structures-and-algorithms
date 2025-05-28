#include "subsequence.hpp"

/* SUBSEQUENCE PATTERN
    Objective: determine some optimal subsequence within input which satisfies problem requirements
*/

// 0/1 Knapsack Problem____________________________________________________________________________

/*
    Problem: Determine a subset of items which produces the max profit if each item may only be
             selected once, without going over capacity

    Inputs: 
        - profits array
        - weights array
        - capacity
    
    Output:
        -max profit
    
    similar problems: longest increasing subsequence, partition equal subset sum?,
                      best time to buy and sell stock w/ cooldown, target sum
*/

// RECURSION
int _01_knapsack(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr) {
    if (capacity <= 0 || curr >= profits.size()) return 0;
    
    int include = 0;
    if (capacity >= weights[curr]) {
        include = profits[curr] + _01_knapsack(profits, weights, 
                    capacity - weights[curr], curr + 1);
    }
        
    int skip = _01_knapsack(profits, weights, capacity, curr + 1);
    
    return std::max(include, skip);
}

// RECURSION (ALTERNATIVE)
int _01_knapsack_alt(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr) {
    if (capacity <= 0) return 0;
    
    int max = 0;
    for (int i = curr; i < profits.size(); ++i) {
        if (weights[i] <= capacity) {
            max = std::max(max, profits[i] + 
                    _01_knapsack_alt(profits, weights, capacity - weights[i], i + 1));
        }
    }
    return max;
}

// TOP-DOWN
int _01_knapsack_top_down(std::vector<int> &profits, std::vector<int> &weights, 
    std::vector<std::vector<int>> &res, int capacity, int curr) {
    if (capacity <= 0 || curr >= profits.size()) return 0;
    
    if (res[curr][capacity] >= 0) return res[curr][capacity];
    
    int include = 0;
    if (capacity >= weights[curr]) {
        include = profits[curr] + _01_knapsack_top_down(profits, weights, res,
                    capacity - weights[curr], curr + 1);
    }
        
    int skip = _01_knapsack_top_down(profits, weights, res, capacity, curr + 1);
    
    res[curr][capacity] = std::max(include, skip);
    
    return res[curr][capacity];
}

// BOTTOM-UP
int _01_knapsack_bottom_up(std::vector<int> &profits, std::vector<int> &weights, int capacity) {
    std::vector<std::vector<int>> res(profits.size() + 1, std::vector<int>(capacity + 1, 0));
    for (int i = 1; i <= profits.size(); ++i) {
        for (int c = 1; c <= capacity; ++c) {
            if (weights[i - 1] <= c) {
                res[i][c] = std::max(res[i - 1][c], profits[i - 1] + res[i - 1][c - weights[i - 1]]);
            } else {
                res[i][c] = res[i - 1][c];
            }
        }
    }
    return res[profits.size()][capacity];
}

// BOTTOM-UP (OPTIMIZED)
int _01_knapsack_bottom_up_opt(std::vector<int> &profits, std::vector<int> &weights, int capacity) {
    std::vector<int> res(capacity + 1, 0);
    for (int i = 0; i < profits.size(); ++i) {
        for (int c = capacity; c >= weights[i]; --c) {
            res[c] = std::max(res[c], profits[i] + res[c - weights[i]]);
        }
    }
    return res[capacity];
}

// Unbounded Knapsack Problem____________________________________________________________________________

/*
    Problem: Determine a subset of items which produces the max profit if each item may be selected an
             unlimited number of times, without going over capacity

    Inputs: 
        - profits array
        - weights array
        - capacity
    
    Output:
        -max profit

    similar problems: coin change(I/II), rod cutting
*/

// RECURSION
int unbounded_knapsack(std::vector<int> &profits, std::vector<int> &weights, int capacity, int curr) {
    if (capacity <= 0 || curr >= profits.size()) return 0;
    
    int include = 0;
    if (weights[curr] <= capacity) {
        include = profits[curr] + unbounded_knapsack(profits, weights, capacity - weights[curr], curr);
    }
    
    int skip = unbounded_knapsack(profits, weights, capacity, curr + 1);
    
    return std::max(include, skip);
}

// RECURSION (ALTERNATIVE)
int unbounded_knapsack_alt(std::vector<int> &profits, std::vector<int> &weights, int capacity) {
    if (capacity <= 0) return 0;
    
    int max = 0;
    for (int i = 0; i < profits.size(); ++i) {
        if (weights[i] <= capacity) {
            max = std::max(max, profits[i] + unbounded_knapsack_alt(profits, weights, 
                capacity - weights[i]));
        }
    }
    return max;
}

// TOP-DOWN
int unbounded_knapsack_top_down(std::vector<int> &profits, std::vector<int> &weights, 
    std::vector<std::vector<int>> &res, int capacity, int curr) {
    if (capacity <= 0 || curr >= profits.size()) return 0;
    
    if (res[curr][capacity] >= 0) return res[curr][capacity];
    
    int include = 0;
    if (weights[curr] <= capacity) {
        include = profits[curr] + unbounded_knapsack_top_down(profits, weights, res, 
            capacity - weights[curr], curr);
    }
    
    int skip = unbounded_knapsack_top_down(profits, weights, res, capacity, curr + 1);
    
    res[curr][capacity] = std::max(include, skip);
    
    return res[curr][capacity];
}

// BOTTOM-UP                                                                                        
int unbounded_knapsack_bottom_up(std::vector<int> &profits, std::vector<int> &weights, int capacity) {
    std::vector<std::vector<int>> res(profits.size() + 1, std::vector<int>(capacity + 1, 0));
    for (int i = 1; i <= profits.size(); ++i) {
        for (int c = 1; c <= capacity; ++c) {
            if (weights[i - 1] <= c) {
                res[i][c] = std::max(res[i - 1][c], profits[i - 1] + res[i][c - weights[i - 1]]);
            } else {
                res[i][c] = res[i - 1][c];
            }
        }
    }
    return res[profits.size()][capacity];
}

// BOTTOM UP (OPTIMIZED)                                                               
int unbounded_knapsack_bottom_up_opt(std::vector<int> &profits, std::vector<int> &weights, int capacity) {
    std::vector<int> res(capacity + 1, 0);
    for (int i = 0; i < profits.size(); ++i) {
        for (int c = weights[i]; c <= capacity; ++c) {
            res[c] = std::max(res[c], profits[i] + res[c - weights[i]]);
        }
    }
    return res[capacity];
}