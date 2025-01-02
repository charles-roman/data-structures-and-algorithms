// UNORDERED_MAPS:

/*
Unordered Maps are unordered associative containers that contain key-value pairs w/
unique keys (aka unsorted hashmaps with unique keys)

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

std::unordered_map<key_type, mapped_type, hasher=, key_equal=, allocator_type=> umap;