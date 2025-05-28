#include "fibonacci.hpp"

/* 
Problem: Compute nth Fibonacci Number

Input: (int) n

Output: (int) nth number

similar problems: climbing stairs, house robber(I/II)
*/

// RECURSION
int fib(int n) {
    if (n <= 1) return n;
    
    return fib(n - 1) + fib(n - 2);
}

// TOP-DOWN
int fib_top_down(int n, std::vector<int>& res) {
    if (n <= 1) return n;
    
    if (res[n] >= 0) return res[n];
    
    res[n] = fib_top_down(n - 1, res) + fib_top_down(n - 2, res);
    
    return res[n];
}

// BOTTOM-UP
int fib_bottom_up(int n) {
    std::vector<int> res(n + 1);
    res[0] = 0;
    res[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n];
}

// BOTTOM-UP (OPTIMIZED)
int fib_bottom_up_opt(int n) {
    int prev1 = 1, prev2 = 0, num = 0;
    for (int i = 2; i <= n; ++i) {
        num = prev1 + prev2;
        prev2 = prev1;
        prev1 = num;
    }
    return num;
}

// MATRIX EXPONENTIATION