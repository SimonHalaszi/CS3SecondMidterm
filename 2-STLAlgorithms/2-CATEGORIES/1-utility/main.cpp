/*

STL ALGORITHMS

CATEGORIES

* utility

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <algorithm>

int main() {
    int x = 25;
    int y = 30;

    std::cout << "x: " << x << " " << "y: " << y << std::endl;

    // std::min(x, y)
    // utility algorithms callback parameter is defaulted to std::less
    std::cout << "std::min(x, y): " << std::min(x, y) << std::endl;
    
    // putting a std::greater or equivalant callback will cause a flip in logic
    std::cout << "std::min(x, y, [](int i, int j)-> bool { return i > j; }): " 
    << std::min(x, y, [](int i, int j)-> bool { return i > j; }) << std::endl;

    // std::max(x, y)
    std::cout << "std::max(x, y): " << std::max(x, y) << std::endl;
    std::cout << "std::max(x, y, std::greater<>()): " 
    << std::max(x, y, std::greater<>()) << std::endl;

    // std::minmax(x, y)
    std::cout << "std::minmax(x, y): " << std::minmax(x, y).first << " " << std::minmax(x, y).second << std::endl;
    std::cout << "std::minmax(x, y, std::greater<>()): " 
    << std::minmax(x, y, std::greater<>()).first << " " << std::minmax(x, y, std::greater<>()).second << std::endl;

    // std::swap(x, y) // wont accept a callback and is void
    std::cout << "x: " << x << " " << "y: " << y << std::endl;
    std::cout << "std::swap(x, y)" << std::endl; 
    std::swap(x, y);
    std::cout << "x: " << x << " " << "y: " << y << std::endl;
    
}