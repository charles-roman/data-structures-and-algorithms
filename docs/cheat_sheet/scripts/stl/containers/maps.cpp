// MAPS:

/*
Maps are ordered associative containers that contain key-value pairs w/
unique keys (aka sorted hashmaps with unique keys)

They are implemented using RB-trees

Support bi-directional iterators

Support default ctor, several parameterized ctors, itr ctors,
copy/move ctors, initializer list ctors, range-based ctors,
copy/move assignment oprs, and initializer list assignment opr

Access -> N/A
Search -> O(logn)
Insert -> O(logn)
Delete -> O(logn)*
    *amortized O(1)
*/ 
    
#include <map>

std::map<key_type, mapped_type, key_compare=, allocator_type=> map;