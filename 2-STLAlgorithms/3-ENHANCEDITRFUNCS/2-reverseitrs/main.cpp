/*

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* reverse iterators

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
    
    std::cout << "std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; })" << std::endl;
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; })" << std::endl;
    std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::deque<int>::reverse_iterator r_itr;

    r_itr = d.rbegin();
    std::cout << "r_itr = d.rbegin(); *r_itr: " << *r_itr << std::endl;
    
    ++r_itr;
    std::cout << "++r_itr; *r_itr: " << *r_itr << std::endl;

    ++r_itr;
    std::cout << "++r_itr; *r_itr: " << *r_itr << std::endl;

    --r_itr;
    std::cout << "--r_itr; *r_itr: " << *r_itr << std::endl;

    r_itr += 2;
    std::cout << "r_itr += 2; *r_itr: " << *r_itr << std::endl;

    std::deque<int>::iterator itr = r_itr.base();
    std::cout << "std::deque<int>::iterator itr = r_itr.base(); *itr: " << *itr << std::endl;

    int distance = std::distance(d.begin(), itr);
    std::cout << "int distance = std::distance(d.begin(), itr); distance: " << distance << std::endl;

    distance = std::distance(d.rbegin(), r_itr);
    std::cout << "distance = std::distance(d.rbegin(), r_itr); distance: " << distance << std::endl;

    distance = std::distance(r_itr, d.rend());
    std::cout << "distance = std::distance(r_itr, d.rend()); distance: " << distance << std::endl;

    *r_itr = 1000;
    std::cout << "*r_itr = 1000;" << std::endl;

    std::cout << "std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; })" << std::endl;
    std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::deque<int>::const_reverse_iterator c_r_itr = d.crbegin();
    std::cout << "std::deque<int>::const_reverse_iterator c_r_itr = d.crbegin(); *c_r_itr: " << *c_r_itr << std::endl;

    // *c_r_itr = 1000;
    std::cout << "cant do: *c_r_itr = 1000;" << std::endl;

    std::cout << "std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; })" << std::endl;
    std::for_each(d.rbegin(), d.rend(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;
}