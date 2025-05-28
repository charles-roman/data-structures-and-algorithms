#include <vector>

// RECURSION______________________________________ O(2^n)
int fib(int n);

// TOP-DOWN_______________________________________ O(n)
int fib_top_down(int n, std::vector<int>& res);

// BOTTOM-UP______________________________________ O(n)
int fib_bottom_up(int n);

// BOTTOM-UP (OPTIMIZED)__________________________ O(n)
int fib_bottom_up_opt(int n);

// MATRIX EXPONENTIATION__________________________ O(logn)