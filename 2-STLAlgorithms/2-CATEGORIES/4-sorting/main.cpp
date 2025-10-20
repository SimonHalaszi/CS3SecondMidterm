/*

STL ALGORITHMS

CATEGORIES

* sorting

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <algorithm>
#include <deque>

int main() {
    std::deque<int> d;

    // ----------------------------------------------------------------------- //
    std::cout << "Sorting" << std::endl;
    // ----------------------------------------------------------------------- //
 
    // ----------------------------------------------------------------------- //
    // sort
    std::cout << std::endl << "sort" << std::endl << std::endl;

    d = {10, 20, 50, 10, 40, 20};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // sort
    // void std::sort(source_start_itr, source_end_itr) {...}
    std::sort(
        d.begin(), 
        d.end()
    );

    std::cout << "std::sort(d.begin(), d.end())" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 
    
    // ----------------------------------------------------------------------- //
    // merge
    std::cout << std::endl << "merge" << std::endl << std::endl;

    d = {10, 20, 30, 40, 50};

    std::deque<int> d2;
    d2 = {10, 20, 30, 40, 50};

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   
    std::cout << "d2: ";
    std::for_each(d2.begin(), d2.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 
    
    std::deque<int> d_target;
    d_target.resize(d.size() + d2.size());

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;  

    std::deque<int>::iterator merge_itr;

    // merge
    // void std::merge(source_start_itr, source_end_itr) {...}
    merge_itr = std::merge(
        d.begin(), 
        d.end(),
        d2.begin(),
        d2.end(),
        d_target.begin()
    );

    std::cout << "std::merge(d.begin(), d.end(), d2.begin(), d2.end(), d_target.begin())" << std::endl;

    std::cout << "d_target: ";
    std::for_each(d_target.begin(), d_target.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl; 
    
    if(merge_itr == d_target.end()) {
        std::cout << "merge_itr is at d_target.end()" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    // unique
    std::cout << std::endl << "unique" << std::endl << std::endl;

    d = {10, 20, 20, 30, 30, 30, 30, 40, 50, 60, 70};

    std::deque<int>::iterator unique_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;  

    // unique
    // iterator unique(start_itr, end_itr) {...}
    unique_itr = std::unique(
        d.begin(), 
        d.end()
    );
    std::cout << "unique_itr = unique(start_itr, end_itr);" << std::endl;
    std::cout << "*unique_itr: " << *unique_itr << std::endl;
    std::cout << "std::distance(d.begin(), unique_itr): " << std::distance(d.begin(), unique_itr) << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    // Remove-erase-idiom
    std::cout << "unique_itr = d.erase(unique_itr, d.end())" << std::endl; unique_itr = d.erase(unique_itr, d.end());
    if(unique_itr == d.end()) {
        std::cout << "unique_itr now at the end of d" << std::endl;
    }

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;  
    
    // ----------------------------------------------------------------------- //
    // binary_search
    std::cout << std::endl << "binary_search" << std::endl << std::endl;

    bool binary_search_bool;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // binary_search
    // bool binary_search(start_itr, end_itr, value) {...}
    binary_search_bool = std::binary_search(
        d.begin(), 
        d.end(),
        20
    );
    std::cout << "binary_search_bool = std::binary_search(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "binary_search_bool: " << binary_search_bool << std::endl;

    // ----------------------------------------------------------------------- //
    // random_shuffle
    std::cout << std::endl << "random_shuffle" << std::endl << std::endl;
    
    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;

    // random_shuffle
    // void random_shuffle(start_itr, end_itr) {...}
    std::random_shuffle(
        d.begin(), 
        d.end()
    );
    std::cout << "std::random_shuffle(d.begin(), d.end());" << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;


}