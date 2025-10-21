/*

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* iterator movement

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <deque>
#include <algorithm>

int main() {
 
    std::deque<int> d;
    d = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::deque<int>::iterator itr;

    itr = d.begin();
    std::cout << "itr = d.begin(); " << "*itr: " << *itr << std::endl;

    // advance works with positive and negative numbers (for bi-directional iterators)
    std::advance(itr, 5);
    std::cout << "std::advance(itr, 5); " << "*itr: " << *itr << std::endl;

    std::advance(itr, -2);
    std::cout << "std::advance(itr, -2); " << "*itr: " << *itr << std::endl;

    std::deque<int>::iterator new_itr;

    // next works with positive and negative numbers (for bi-directional iterators)
    new_itr = std::next(itr, 5);
    std::cout << "new_itr = std::next(itr, 5); " << "*new_itr: " << *new_itr << std::endl;

    new_itr = std::next(itr, -2);
    std::cout << "new_itr = std::next(itr, -2); " << "*new_itr: " << *new_itr << std::endl;   

    std::cout << "std::next(itr, neg_n) == std::prev(itr, pos_n)" << std::endl;
    
    // prev works with positive and negative numbers (for bi-directional iterators)
    new_itr = std::prev(itr, 2);
    std::cout << "new_itr = std::prev(itr, 2); " << "*new_itr: " << *new_itr << std::endl;

    new_itr = std::prev(itr, -5);
    std::cout << "new_itr = std::prev(itr, -5); " << "*new_itr: " << *new_itr << std::endl; 
    
    std::cout << "std::prev(itr, neg_n) == std::next(itr, pos_n)" << std::endl;

    // distance, works even in wrong order, gets distance between two iterators
    int distance;

    distance = std::distance(itr, new_itr);
    std::cout << "distance = std::distance(itr, new_itr); " << distance << std::endl;

    distance = std::distance(new_itr, itr);
    std::cout << "distance = std::distance(itr, new_itr); " << distance << std::endl;

}