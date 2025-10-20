/*

STL ALGORITHMS

CALLBACKS

* lambda expressions
    - capture block, context, capture variables

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Declaring some variables
    int x = 3;
    char y = 'p';
    double z = 3.14;

    // Call lambda in place using extra set of parentheses
    int var = [&]()-> int { x -= 1; return x; }();
    std::cout << var << std::endl;

    // Declaring a function pointer that points to lambda with same signature

    // This lambda captures nothing, takes in an int by value, x, and double by reference, z,
    // returns an int and adds 1 to z and returns x + z
    int (*funcptr)(int, double&) = [](int x, double& z)-> int { z += 1; return x + z; };

    // Called function pointer that points to our lambda
    std::cout << funcptr(x, z) << std::endl;
    std::cout << z << std::endl;

    // Making and populating vector
    std::vector<int> v;
    for(int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    /*

    Passing in a lambda into an algorithm. std::for_each() will traverse 
    inputted range of iterators calling the lambda on every element. std::for_each()
    expects a callback that takes in the type of elemnt of the container by any paradigm.
    The current value of the element std::for_each will be passed into callback.

    Our lamba takes uses its capture block to take in the entire context by value, and takes
    in the current element e by a const reference. It then prints e and y which was captured
    into the context by the capture block.
    
    */
    std::for_each(v.begin(), v.end(), [=](const int& e) { std::cout << e << " " << y << std::endl;});
}