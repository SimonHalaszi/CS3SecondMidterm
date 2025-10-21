/*

STL ALGORITHMS

CALLBACKS

* predefined functors

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <vector>
#include <string>
#include <functional> // Needed for std::placeholders

// Templated lesser than functor. (Predefined one of these already exist)
template<typename T>
class LesserThan {
    public:
        LesserThan() {}
        // Overloaded function call operator
        bool operator()(const T& lhs, const T& rhs) { 
            if(lhs < rhs) {
                std::cout << lhs << " is less than " << rhs << std::endl;
            }
            return lhs < rhs; 
        }
};

// Fun little functor less practical
class Functor {
    public:
        Functor(char c = '0') : c_(c) {}
        // Overloaded function call operator
        char operator()() { return c_++; } 
    private:
        int c_;
};

int main() {
    // Declaring a LesserThan object
    LesserThan<int> ltints;
    bool result = ltints(3, 5);
    if(result) {
        std::cout << "true" << std::endl;
    }

    // Declaring and populating a vector v
    std::vector<int> v;
    for(int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    // What rhs in LesserThan will be binded to
    int checkLessThanThis = 4;
    // More on std::bind() later
    auto func = std::bind(LesserThan<int>(), std::placeholders::_1, checkLessThanThis);
    // Binded because for_each expects a callback that only has one parameter and that is
    // the current element in the range its going through
    std::for_each(v.begin(), v.end(), func);

    // Declaring a string str, strings are actually containers
    std::string str = "Hello";

    // Using for_each to print the string using a lambda
    std::for_each(str.begin(), str.end(), [](char c)->void { std::cout << c << " "; });
    std::cout << std::endl;

    // Declaring Functor with char 'a'
    Functor functy('a');
    // generate expects a callback with no parameters and a return type of the type
    // of elements inside the container
    std::generate(str.begin(), str.end(), functy);

    // Using for_each to print the string using a lambda
    std::for_each(str.begin(), str.end(), [](char c)->void { std::cout << c << " "; });
    std::cout << std::endl;

    std::cout << Functor()() << std::endl;
}