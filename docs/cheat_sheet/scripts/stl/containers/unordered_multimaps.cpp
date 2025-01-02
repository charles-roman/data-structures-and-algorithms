// UNORDERED_MULTIMAPS:

/*
Unordered Multimaps are unordered associative containers that contain key-value pairs &
support equivalent keys (aka unsorted hashmaps that support equivalent keys)

They are implemented using open hashing (aka hashing with chaining)

Support forward iterators

Support default ctor, several parameterized ctors, itr ctors,
copy/move ctors, initializer list ctors, range-based ctors,
copy/move assignment oprs, and initializer list assignment opr

Access -> N/A
Search -> O(1)*
Insert -> O(1)*
Delete -> O(1)*
    *on average, worst case O(n)
*/ 
    
#include <unordered_map>

std::unordered_multimap<key_type, mapped_type, hasher=, key_equal=, allocator_type=> ummap;