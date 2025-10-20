/*

STL ALGORITHMS

CATEGORIES

* modifying
    - remove-erase idiom
    - source and target range

c++ remove_and_erase.cpp
./a.out > remove_and_erase.txt
rm ./a.out

*/

#include <iostream>
#include <deque>
#include <algorithm> // needed for algorithms

int main() {
    std::deque<int> d;

    // ----------------------------------------------------------------------- //
    std::cout << "Modifying: Remove (and Erase)" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // remove
    std::cout << std::endl << "remove" << std::endl << std::endl;

    d = {20, 10, 20, 30, 30, 40, 50, 0, 20};

    std::deque<int>::iterator remove_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // remove
    // iterator remove(start_itr, end_itr, value) {...}
    remove_itr = std::remove(
        d.begin(), 
        d.end(), 
        20
    );
    std::cout << "remove_itr = std::remove(d.begin(), d.end(), 20);" << std::endl;
    std::cout << "*remove_itr: " << *remove_itr << std::endl;
    std::cout << "std::distance(d.begin(), remove_itr): " << std::distance(d.begin(), remove_itr) << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    // Remove-erase-idiom
    std::cout << "remove_itr = d.erase(remove_itr, d.end())" << std::endl; remove_itr = d.erase(remove_itr, d.end());
    if(remove_itr == d.end()) {
        std::cout << "remove_itr now at the end of d" << std::endl;
    }

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;      

    // Just showing off another algorithm we learn
    std::cout << "bool all_not_twenty = std::all_of(d.begin(), d.end(), [](const int& i)-> bool { return i != 20; });" << std::endl;
    bool all_not_twenty = std::all_of(d.begin(), d.end(), [](const int& i)-> bool { return i != 20; });

    std::cout << "if(all_not_twenty)" << std::endl;
    if(all_not_twenty) {
        std::cout << "    We got rid of all the twenties" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    // remove_if
    std::cout << std::endl << "remove_if" << std::endl << std::endl;

    d = {20, 10, 20, 30, 30, 40, 50, 0, 20};

    std::deque<int>::iterator remove_if_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;    

    // remove_if
    // iterator remove_if(start_itr, end_itr, unary_predicate) {...}
    remove_if_itr = std::remove_if(
        d.begin(), 
        d.end(), 
        [](const int& i)-> bool { return i >= 20; }
    );
    std::cout << "remove_if_itr = std::remove(d.begin(), d.end(), [](const int& i)-> bool { return i >= 20; });" << std::endl;
    std::cout << "*remove_if_itr: " << *remove_if_itr << std::endl;
    std::cout << "std::distance(d.begin(), remove_if_itr): " << std::distance(d.begin(), remove_if_itr) << std::endl;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;   

    // Remove-erase-idiom
    std::cout << "remove_if_itr = d.erase(remove_if_itr, d.end())" << std::endl; remove_if_itr = d.erase(remove_if_itr, d.end());
    if(remove_if_itr == d.end()) {
        std::cout << "remove_if_itr now at the end of d" << std::endl;
    }

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;      

    // Just showing off another algorithm we learn
    std::cout << "bool all_less_than_twenty = std::all_of(d.begin(), d.end(), [](const int& i)-> bool { return i < 20; });" << std::endl;
    bool all_less_than_twenty = std::all_of(d.begin(), d.end(), [](const int& i)-> bool { return i < 20; });

    std::cout << "if(all_less_than_twenty)" << std::endl;
    if(all_less_than_twenty) {
        std::cout << "    We got rid of everything greater than or equal to 20" << std::endl;
    }

    // ----------------------------------------------------------------------- //
    std::cout << std::endl << "Modifying Algorithms that Operate on a Single Range" << std::endl;
    // ----------------------------------------------------------------------- //

    // ----------------------------------------------------------------------- //
    // unique
    std::cout << std::endl << "unique" << std::endl << std::endl;

    d = {20, 10, 20, 30, 30, 40, 50, 0, 20};

    std::deque<int>::iterator unique_itr;

    std::cout << "d: ";
    std::for_each(d.begin(), d.end(), [](const int& i)-> void { std::cout << i << " "; }); std::cout << std::endl;  
    
    std::cout << "std::sort(d.begin(), d.end());" << std::endl; std::sort(d.begin(), d.end());

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
    
}