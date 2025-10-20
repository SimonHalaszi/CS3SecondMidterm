/*

STL ALGORITHMS

CATEGORIES

* set

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <algorithm>
#include <deque>

int main() {
    std::deque<int> set1;
    std::deque<int> set2;
    std::deque<int> target_set;

    // ----------------------------------------------------------------------- //
    std::cout << "Set" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // includes
    std::cout << std::endl << "includes" << std::endl << std::endl;

    set1 = {10, 20, 30, 40, 50};
    set2 = {10, 20, 30};

    bool includes;
    
    std::cout << "set1: ";
    std::for_each(set1.begin(), set1.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "set2: ";
    std::for_each(set2.begin(), set2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // includes
    // bool includes(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr) {...}
    includes = std::includes(
        set1.begin(), 
        set1.end(),
        set2.begin(),
        set2.end()
    );
    std::cout << "includes = std::includes(set1.begin(), set1.end(), set2.begin(), set2.end());" << std::endl;
    std::cout << "includes: " << includes << std::endl;

    // ----------------------------------------------------------------------- //
    // set_union
    std::cout << std::endl << "set_union" << std::endl << std::endl;

    set1 = {10, 20, 30, 40, 50, 80};
    set2 = {10, 20, 30, 60, 70, 80};

    std::deque<int>::iterator set_union_itr;
    
    std::cout << "set1: ";
    std::for_each(set1.begin(), set1.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "set2: ";
    std::for_each(set2.begin(), set2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "target_set.resize(set1.size(), set2.size());" << std::endl; target_set.resize(set1.size() + set2.size());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // set_union
    // iterator set_union(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr) {...}
    set_union_itr = std::set_union(
        set1.begin(), 
        set1.end(),
        set2.begin(),
        set2.end(),
        target_set.begin()
    );
    std::cout << "set_union_itr = std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), target_set.begin());" << std::endl;
    std::cout << "*set_union_itr: " << *set_union_itr << std::endl;

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::cout << "set_union_itr = target_set.erase(set_union_itr, target_set.end())" << std::endl;
    set_union_itr = target_set.erase(set_union_itr, target_set.end());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    if(set_union_itr == target_set.end()) {
        std::cout << "set_union_itr now at target_set.end()" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    // set_intersection
    std::cout << std::endl << "set_intersection" << std::endl << std::endl;

    set1 = {10, 20, 30, 40, 50, 80};
    set2 = {10, 20, 30, 60, 70, 80};

    std::deque<int>::iterator set_intersection_itr;
    
    std::cout << "set1: ";
    std::for_each(set1.begin(), set1.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "set2: ";
    std::for_each(set2.begin(), set2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "target_set.resize(set1.size(), set2.size());" << std::endl; target_set.resize(set1.size() + set2.size());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // set_intersection
    // iterator set_intersection(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr) {...}
    set_intersection_itr = std::set_intersection(
        set1.begin(), 
        set1.end(),
        set2.begin(),
        set2.end(),
        target_set.begin()
    );
    std::cout << "set_intersection_itr = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), target_set.begin());" << std::endl;
    std::cout << "*set_intersection_itr: " << *set_intersection_itr << std::endl;

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::cout << "set_intersection_itr = target_set.erase(set_intersection_itr, target_set.end())" << std::endl;
    set_intersection_itr = target_set.erase(set_intersection_itr, target_set.end());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    if(set_intersection_itr == target_set.end()) {
        std::cout << "set_union_itr now at target_set.end()" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    // set_difference
    std::cout << std::endl << "set_difference" << std::endl << std::endl;

    set1 = {10, 20, 30, 40, 50, 80};
    set2 = {10, 20, 30, 60, 70, 80};

    std::deque<int>::iterator set_difference_itr;
    
    std::cout << "set1: ";
    std::for_each(set1.begin(), set1.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "set2: ";
    std::for_each(set2.begin(), set2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "target_set.resize(set1.size(), set2.size());" << std::endl; target_set.resize(set1.size() + set2.size());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // set_difference
    // iterator set_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr) {...}
    set_difference_itr = std::set_difference(
        set1.begin(), 
        set1.end(),
        set2.begin(),
        set2.end(),
        target_set.begin()
    );
    std::cout << "set_difference_itr = std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), target_set.begin());" << std::endl;
    std::cout << "*set_difference_itr: " << *set_difference_itr << std::endl;

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::cout << "set_difference_itr = target_set.erase(set_difference_itr, target_set.end())" << std::endl;
    set_difference_itr = target_set.erase(set_difference_itr, target_set.end());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    if(set_difference_itr == target_set.end()) {
        std::cout << "set_union_itr now at target_set.end()" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    // set_symmetric_difference
    std::cout << std::endl << "set_symmetric_difference" << std::endl << std::endl;

    set1 = {10, 20, 30, 40, 50, 80};
    set2 = {10, 20, 30, 60, 70, 80};

    std::deque<int>::iterator set_symmetric_difference_itr;
    
    std::cout << "set1: ";
    std::for_each(set1.begin(), set1.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "set2: ";
    std::for_each(set2.begin(), set2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    std::cout << "target_set.resize(set1.size(), set2.size());" << std::endl; target_set.resize(set1.size() + set2.size());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // set_symmetric_difference
    // iterator set_symmetric_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr) {...}
    set_symmetric_difference_itr = std::set_symmetric_difference(
        set1.begin(), 
        set1.end(),
        set2.begin(),
        set2.end(),
        target_set.begin()
    );
    std::cout << "set_symmetric_difference_itr = std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), target_set.begin());" << std::endl;
    std::cout << "*set_symmetric_difference_itr: " << *set_symmetric_difference_itr << std::endl;

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    std::cout << "set_symmetric_difference_itr = target_set.erase(set_symmetric_difference_itr, target_set.end())" << std::endl;
    set_symmetric_difference_itr = target_set.erase(set_symmetric_difference_itr, target_set.end());

    std::cout << "target_set: ";
    std::for_each(target_set.begin(), target_set.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    if(set_symmetric_difference_itr == target_set.end()) {
        std::cout << "set_union_itr now at target_set.end()" << std::endl;
    }

}