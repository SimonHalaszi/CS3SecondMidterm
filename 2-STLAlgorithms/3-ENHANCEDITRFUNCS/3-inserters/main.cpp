/*

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* back inserter and front inserter

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::deque<int> d;
    
    std::insert_iterator<std::deque<int>> ins_itr = std::inserter(d, d.begin());
    std::cout << "std::insert_iterator<std::deque<int>> ins_itr = std::inserter(d, d.begin());" << std::endl;

    ins_itr = 40; // can directly assign inserters, self updates
    std::cout << "ins_itr = 40;" << std::endl;
    ins_itr = (ins_itr = 50); // can manually update it like normal iterators if you want but no use really
    std::cout << "ins_itr = (ins_itr = 50);" << std::endl;
    ins_itr = 60; 
    std::cout << "ins_itr = 60;" << std::endl;

    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::back_insert_iterator<std::deque<int>> back_ins_itr = std::back_inserter(d);
    std::cout << "std::back_insert_iterator<std::deque<int>> back_ins_itr = std::back_inserter(d);" << std::endl;

    back_ins_itr = 70;
    std::cout << "back_ins_itr = 70;" << std::endl;

    std::front_insert_iterator<std::deque<int>> front_ins_itr = std::front_inserter(d);
    std::cout << "std::back_insert_iterator<std::deque<int>> back_ins_itr = std::back_inserter(d);" << std::endl;

    front_ins_itr = 30;
    std::cout << "front_ins_itr = 30;" << std::endl;

    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // need to revalidate base insert_iterators if you dont do these inserts back to back, else could be invalidated

    std::deque<int>::iterator find_50 = std::lower_bound(d.begin(), d.end(), 50);
    std::cout << "std::deque<int>::iterator find_50 = std::lower_bound(d.begin(), d.end(), 50);" << std::endl;

    ins_itr = std::inserter(d, find_50);
    std::cout << "ins_itr = std::inserter(d, find_50);" << std::endl;
    
    ins_itr = 45;
    std::cout << "ins_itr = 45;" << std::endl;

    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

}