// FORWARD_LISTS:

/* 
Forward_Lists are singly-linked lists

    Main advantage of using a forward list compared to a standard
    list is the savings that could be achieved in memory

    Main disadvantage is that it can only be traversed in one direction
    and is more limited in functionality

Supports forward iterators

Supports default ctor, several parameterized ctors,
copy/move ctors, and copy/move assignment oprs

Access/Modify -> O(n)
Insert/Delete -> O(1)
Search -> O(n)
*/

#include <forward_list>

std::forward_list<type> my_flist;