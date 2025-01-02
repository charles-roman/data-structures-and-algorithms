// FORWARD_LISTS:

/* 
Forward_Lists are singly-linked lists

Support forward iterators

Supports default ctor, parameterized ctors, itr ctors,
copy/move ctors, initializer list ctors, range-based ctors,
copy/move assignment oprs, and initializer list opr

Access -> O(n)
Insert -> O(1)
Delete -> O(1)
Search -> N/A
*/

#include <forward_list>

std::forward_list<value_type, allocator_type=> flist;