// FORWARD_LISTS:

/* 
Main advantage of using a forward list compared to a standard
list is the savings that could be achieved in memory

Support forward iterators

Access/Modify -> O(n)
Insert/Delete -> O(1)
Search -> O(n)
*/

#include <forward_list>

// Declaring a Forward List
std::forward_list<type> flist;

// Forward List Operations
// Member Functions
    flist.assign();
    flist1 = flist2;    // =operator copies list to another

    // Element Access
    flist.front();

    // Iterators    (Forward Iterators only!)
    flist.begin();
    flist.end();

    // Capacity
    flist.empty();
    flist.max_size();

    // Modifiers
    flist.push_front();
    flist.emplace_front();
    flist.pop_front();
    flist.insert_after();
    flist.emplace_after();
    flist.erase_after();
    flist.clear();
    flist.swap();

    // Operations
    flist.merge();
    flist.remove();
    flist.remove_if();
    flist.splice_after();
    flist.reverse();
    flist.sort();
    flist.unique();
    