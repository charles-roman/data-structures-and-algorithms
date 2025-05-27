#include <iostream>
#include <cstdlib>
#include "hashmap.hpp"

int main(int argc, char* argv[]) {

    std::cout << "TEST BEGIN" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "DEFAULT CONSTRUCTOR..." << std::endl;

    crs::HashMap<std::string, int> dmap;

    std::cout << "size: " << dmap.size() << std::endl;
    std::cout << "empty: " << dmap.empty() << std::endl;
    std::cout << "bucket count: " << dmap.bucket_count() << std::endl;
    std::cout << "load factor: " << dmap.load_factor() << std::endl;
    std::cout << "printing...\n";
    dmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "PARAMETERIZED CONSTRUCTOR..." << std::endl;

    crs::HashMap<std::string, int> pmap(10);

    std::cout << "size: " << pmap.size() << std::endl;
    std::cout << "empty: " << pmap.empty() << std::endl;
    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "load factor: " << pmap.load_factor() << std::endl;
    std::cout << "printing...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "INSERTING..." << std::endl;

    pmap.insert(std::make_pair("apple", 1));
    pmap.insert(std::make_pair("orange", 2));
    pmap.insert(std::make_pair("banana", 3));

    std::cout << "size: " << pmap.size() << std::endl;
    std::cout << "empty: " << pmap.empty() << std::endl;
    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "load factor: " << pmap.load_factor() << std::endl;
    std::cout << "printing...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "COPY CONSTRUCTOR..." << std::endl;

    crs::HashMap<std::string, int> cmap(pmap);

    std::cout << "size: " << cmap.size() << std::endl;
    std::cout << "empty: " << cmap.empty() << std::endl;
    std::cout << "bucket count: " << cmap.bucket_count() << std::endl;
    std::cout << "load factor: " << cmap.load_factor() << std::endl;
    std::cout << "printing new map...\n";
    cmap.print();
    std::cout << "printing copied map...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MOVE CONSTRUCTOR..." << std::endl;

    crs::HashMap<std::string, int> mmap(std::move(pmap));

    std::cout << "size: " << mmap.size() << std::endl;
    std::cout << "empty: " << mmap.empty() << std::endl;
    std::cout << "bucket count: " << mmap.bucket_count() << std::endl;
    std::cout << "load factor: " << mmap.load_factor() << std::endl;
    std::cout << "printing new map...\n";
    mmap.print();
    std::cout << "printing moved map...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "COPY ASSIGNMENT OPERATOR..." << std::endl;

    pmap = mmap;

    std::cout << "size: " << pmap.size() << std::endl;
    std::cout << "empty: " << pmap.empty() << std::endl;
    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "load factor: " << pmap.load_factor() << std::endl;
    std::cout << "printing copied to map...\n";
    pmap.print();
    std::cout << "printing copied from map...\n";
    mmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "MOVE ASSIGNMENT OPERATOR..." << std::endl;

    dmap = std::move(mmap);

    std::cout << "size: " << dmap.size() << std::endl;
    std::cout << "empty: " << dmap.empty() << std::endl;
    std::cout << "bucket count: " << dmap.bucket_count() << std::endl;
    std::cout << "load factor: " << dmap.load_factor() << std::endl;
    std::cout << "printing moved to map...\n";
    dmap.print();
    std::cout << "printing moved from map...\n";
    mmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "ERASING..." << std::endl;

    cmap.erase("apple");
    cmap.erase("orange");
    cmap.erase("banana");

    std::cout << "size: " << cmap.size() << std::endl;
    std::cout << "empty: " << cmap.empty() << std::endl;
    std::cout << "bucket count: " << cmap.bucket_count() << std::endl;
    std::cout << "load factor: " << cmap.load_factor() << std::endl;
    std::cout << "printing...\n";
    cmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "ADDITIONAL TESTS..." << std::endl;

    std::cout << "size: " << pmap.size() << std::endl;
    std::cout << "empty: " << pmap.empty() << std::endl;
    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "load factor: " << pmap.load_factor() << std::endl;
    std::cout << "max load factor: " << pmap.max_load_factor() << std::endl;
    std::cout << "count of key = apple: " << pmap.count("apple") << std::endl;

    std::pair<std::string, int> pair = pmap.find("apple");

    std::cout << "value for key = apple: " <<  pair.second << std::endl;

    std::string boolean = "false";
    if (pmap.contains("apple")) boolean = "true";

    std::cout << "contains key = apple: " <<  boolean << std::endl;

    size_t bucket = pmap.bucket("apple");

    std::cout << "bucket which contains key = apple: " <<  bucket << std::endl;
    std::cout << "bucket size of bucket " << bucket << ": " << pmap.bucket_size(bucket) << std::endl;
    std::cout << "resetting max load factor...\n";

    pmap.max_load_factor(2.0f);

    std::cout << "max load factor: " << pmap.max_load_factor() << std::endl;
    std::cout << "printing...\n";

    pmap.print();

    std::cout << "rehashing...\n";

    pmap.rehash(4);

    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "printing...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "CLEARING..." << std::endl;
    
    pmap.clear();

    std::cout << "size: " << pmap.size() << std::endl;
    std::cout << "empty: " << pmap.empty() << std::endl;
    std::cout << "bucket count: " << pmap.bucket_count() << std::endl;
    std::cout << "load factor: " << pmap.load_factor() << std::endl;
    std::cout << "printing...\n";
    pmap.print();
    std::cout << "-----------------------------------------" << std::endl;

    exit(EXIT_SUCCESS);
}