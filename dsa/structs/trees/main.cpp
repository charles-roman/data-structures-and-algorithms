#include <vector>
#include "bstree.hpp"
#include "../../utils/utils.hpp"

int main(int argc, char* argv[]) {

    std::cout << "TEST BEGIN" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "DEFAULT CONSTRUCTOR..." << std::endl;

    crs::BSTree<int, std::string> dtree;

    std::cout << "Standard Tree" << std::endl;
    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();

    crs::BSTree<int, std::string, std::greater<int>> rtree;

    std::cout << "Reversed Tree" << std::endl;
    std::cout << "size: " << rtree.size() << std::endl;
    std::cout << "empty: " << rtree.empty() << std::endl;
    std::cout << "printing...\n";
    rtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "INSERTING..." << std::endl;

    dtree.insert(std::make_pair(13, "blueberry"));
    dtree.insert(std::make_pair(11, "tangerine"));
    dtree.insert(std::make_pair(7, "grapefruit"));
    dtree.insert(std::make_pair(3, "orange"));
    dtree.insert(std::make_pair(5, "banana"));
    dtree.insert(std::make_pair(22, "cherry"));
    dtree.insert(std::make_pair(1, "apple"));

    std::cout << "attempting to insert duplicate..." << std::endl;
    auto pair = dtree.insert(std::make_pair(1, "apple"));
    bool inserted = pair.second;

    std::string val = "false";
    if (inserted) val = "true";

    std::cout << "inserted: " << val << std::endl;
    std::cout << "Standard Tree" << std::endl;
    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();

    rtree.insert(std::make_pair(13, "blueberry"));
    rtree.insert(std::make_pair(11, "tangerine"));
    rtree.insert(std::make_pair(7, "grapefruit"));
    rtree.insert(std::make_pair(3, "orange"));
    rtree.insert(std::make_pair(5, "banana"));
    rtree.insert(std::make_pair(22, "cherry"));
    rtree.insert(std::make_pair(1, "apple"));

    std::cout << "Reversed Tree" << std::endl;
    std::cout << "size: " << rtree.size() << std::endl;
    std::cout << "empty: " << rtree.empty() << std::endl;
    std::cout << "printing...\n";
    rtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "COPY CONSTRUCTOR..." << std::endl;

    crs::BSTree<int, std::string> ctree = dtree;

    std::cout << "size: " << ctree.size() << std::endl;
    std::cout << "empty: " << ctree.empty() << std::endl;
    std::cout << "printing new tree...\n";
    ctree.print();
    std::cout << "printing copied tree...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MOVE CONSTRUCTOR..." << std::endl;

    crs::BSTree<int, std::string> mtree = std::move(ctree);

    std::cout << "size: " << mtree.size() << std::endl;
    std::cout << "empty: " << mtree.empty() << std::endl;
    std::cout << "printing new tree...\n";
    mtree.print();
    std::cout << "printing moved tree...\n";
    ctree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "COPY ASSIGNMENT OPERATOR..." << std::endl;

    ctree = mtree;

    std::cout << "size: " << rtree.size() << std::endl;
    std::cout << "empty: " << rtree.empty() << std::endl;
    std::cout << "printing copied to tree...\n";
    ctree.print();
    std::cout << "printing copied from tree...\n";
    mtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MOVE ASSIGNMENT OPERATOR..." << std::endl;

    mtree = std::move(ctree);

    std::cout << "size: " << mtree.size() << std::endl;
    std::cout << "empty: " << mtree.empty() << std::endl;
    std::cout << "printing moved to tree...\n";
    mtree.print();
    std::cout << "printing moved from tree...\n";
    ctree.print();
    std::cout << "-----------------------------------------" << std::endl;


    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "ITERATOR FUNCTIONS..." << std::endl;

    auto beg = dtree.begin();
    auto end = dtree.end();
    auto root = dtree.root();

    std::string state;
    if (end == nullptr) state = "nullptr";

    std::cout << "begin: {" << beg->first << ", " << beg->second << "}" << std::endl;
    std::cout << "end: " << state <<  std::endl;
    std::cout << "root: {" << root->first << ", " << root->second << "}" << std::endl;
    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "LOOKUP FUNCTIONS..." << std::endl;

    std::cout << "searching for key 5...\n";

    auto banana = dtree.search(5);
    auto banana_r = dtree.search_r(5, root);

    std::cout << "search: {" << banana->first << ", " << banana->second << "}" << std::endl;
    std::cout << "recursive search: {" << banana_r->first << ", " << banana_r->second << "}" << std::endl;

    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "TRAVERSALS..." << std::endl;

    std::cout << "in-order traversal using auxiliary stack approach...\n";
    std::vector<std::pair<const int, std::string>> in_order = dtree.in_order();
    utils::print_associative_contents(in_order.begin(), in_order.end());

    std::cout << "in-order traversal using morris approach...\n";
    std::vector<std::pair<const int, std::string>> in_order_mor = dtree.in_order_mor();
    utils::print_associative_contents(in_order_mor.begin(), in_order_mor.end());

    std::cout << "in-order traversal using successor approach...\n";
    std::vector<std::pair<const int, std::string>> in_order_suc = dtree.in_order_suc();
    utils::print_associative_contents(in_order_suc.begin(), in_order_suc.end());

    std::cout << "in-order traversal using recursive approach...\n";
    std::vector<std::pair<const int, std::string>> in_order_vec;
    dtree.in_order_r(in_order_vec, root);
    utils::print_associative_contents(in_order_vec.begin(), in_order_vec.end());

    std::cout << "pre-order traversal using auxiliary stack approach...\n";
    std::vector<std::pair<const int, std::string>> pre_order = dtree.pre_order();
    utils::print_associative_contents(pre_order.begin(), pre_order.end());

    std::cout << "pre-order traversal using recursive approach...\n";
    std::vector<std::pair<const int, std::string>> pre_order_vec;
    dtree.pre_order_r(pre_order_vec, root);
    utils::print_associative_contents(pre_order_vec.begin(), pre_order_vec.end());

    std::cout << "post-order traversal using auxiliary stack approach...\n";
    std::vector<std::pair<const int, std::string>> post_order = dtree.post_order();
    utils::print_associative_contents(post_order.begin(), post_order.end());

    std::cout << "post-order traversal using recursive approach...\n";
    std::vector<std::pair<const int, std::string>> post_order_vec;
    dtree.post_order_r(post_order_vec, root);
    utils::print_associative_contents(post_order_vec.begin(), post_order_vec.end());

    std::cout << "level-order traversal using auxiliary stack approach...\n";
    std::vector<std::pair<const int, std::string>> level_order = dtree.level_order();
    utils::print_associative_contents(level_order.begin(), level_order.end());

    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "ERASING..." << std::endl;

    std::cout << "erasing root..." << std::endl;
    auto root_successor = dtree.erase(root);

    std::cout << "erasing key 7..." << std::endl;
    size_t count7 = dtree.erase(7);

    std::cout << "attempting to erase non-existent key..." << std::endl;
    size_t count69 = dtree.erase(69);

    std::cout << "successor of root: {" << dtree.root()->first << ", " << dtree.root()->second << "}" << std::endl;
    std::cout << "count erased with key 7: " << count7 << std::endl;
    std::cout << "count erased with key 69: " << count69 << std::endl;
    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "ITERATING..." << std::endl;

    for (auto it = dtree.begin(); it != dtree.end(); ++it) {
        it->second = "apple";
    }

    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "CLEARING..." << std::endl;

    dtree.clear();

    std::cout << "size: " << dtree.size() << std::endl;
    std::cout << "empty: " << dtree.empty() << std::endl;
    std::cout << "printing...\n";
    dtree.print();
    std::cout << "-----------------------------------------" << std::endl;

    exit(EXIT_SUCCESS);
}