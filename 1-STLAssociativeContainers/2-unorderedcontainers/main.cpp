/*

STL ASSOCIATIVE CONTAINERS

* unordered containers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// need
#include <unordered_map>
#include <unordered_set>

int main() {

    std::cout << "-- unordered_map<int, char> --" << std::endl;

    std::unordered_map<int, char> unordmap;
    
    for(int i = 0; i < 10; i++) {
        unordmap.insert({i, ('a' + i)}); // {0, 'a'}, {1, 'b'}...
    }

    std::cout << "unordmap.bucket_count(): " << unordmap.bucket_count() << std::endl; // Get amount of buckets in hash table

    std::cout << "unordmap.size(): " << unordmap.size() << std::endl;   // Get amount of hashed to buckets in hash table

    std::cout << "unordmap.load_factor(): " << unordmap.load_factor() << std::endl; // Get size()/bucket_count()

    // Just to show that fact is true
    if(unordmap.load_factor() == static_cast<float>(unordmap.size())/unordmap.bucket_count()) {
        std::cout << "load_factor() does equal size()/bucket_count()" << std::endl;
    }

    std::cout << "max_load_factor(): " << unordmap.max_load_factor() << std::endl;  // Getting current max_load_factor()

    std::cout << "max_load_factor(0.7);" << std::endl;  // Setting max_load_factor with 0.7
    unordmap.max_load_factor(0.7);

    std::cout << "unordmap.load_factor(): " << unordmap.load_factor() << std::endl; // Wont retroactively rehash and expand

    unordmap.insert({10, ('a' + 10)});

    std::cout << "unordmap.load_factor(): " << unordmap.load_factor() << std::endl; // Not hash table is rehashed and expanded

    size_t bucketInd = unordmap.bucket(0);  // Get bucket index that has element with key 0, not nessearily bucket 0
    std::cout << "unordmap.bucket(0): " << bucketInd << std::endl;

    // local_iterator is an iterator that iterates through the inside of a bucket
    std::unordered_map<int, char>::local_iterator lit = unordmap.begin(bucketInd); // Get local iterator to element with key 0
    std::cout << "{" << lit->first << ", " << lit->second << "}" << std::endl;

    std::cout << "----" << std::endl;

    std::unordered_map<int, char>::iterator itr; // Normal iterators still do exist for unordered containers
    
    // But notice in output this wont have an order, these iterators just iterate in the order of buckets
    // Thats why local_iterators exist, to get meaningful access to elements
    for(itr = unordmap.begin(); itr != unordmap.end(); ++itr) {
        std::cout << "{" << itr->first << ", " << itr->second << "}" << std::endl;
    }

    std::cout << "-- unordered_multiset<int> --" << std::endl;

    // Example of an unordered_multiset

    std::unordered_multiset<int> unmultiset;

    for(int i = 0; i < 10; i++) {
        unmultiset.insert(i); // 0 0 0, 1 1 1...
        unmultiset.insert(i);
        unmultiset.insert(i);
    }

    // I want to iterate on elements with key 0. How do I do this?

    // Use local iterators
    // auto useful

    auto litstart = unmultiset.begin(unmultiset.bucket(0));
    auto litend = unmultiset.end(unmultiset.bucket(0));

    while(litstart != litend) {
        std::cout << *litstart << std::endl;
        ++litstart;
    }

    std::cout << "----" << std::endl;

    // Using normal iterator, not necessarily in order, but elements with same key will be
    // together still, since they share the same bucket.
    std::unordered_multiset<int>::iterator umsitr;
    for(umsitr = unmultiset.begin(); umsitr != unmultiset.end(); ++umsitr) {
        std::cout << *umsitr << std::endl;
    }
}