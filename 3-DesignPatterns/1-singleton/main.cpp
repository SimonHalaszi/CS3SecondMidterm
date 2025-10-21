/*

DESIGN PATTERNS

* singleton
    - motivation (why use the pattern)
    - static features
    - atexit()
    - forbidding object copying: delete vs. making private
    - idioms vs. design patterns vs. frameworks
    - singleton meyers vs. class implementation

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// Custom Singletons
#include "ClassicSingleton.hpp"
#include "MeyersSingleton.hpp"

int main() {

    // This will intialize our ClassicSingleton, its the first call of its getInstance function
    ClassicSingleton::getInstance();

    // This will intialize our MeyersSingleton, its the first call of its getInstance function
    MeyersSingleton::getInstance();

    std::cout << std::endl;

    // |-------------------------------------------|
    std::cout << "ClassicSingleton Payload Accessing" << std::endl;
    std::cout << "ClassicSingleton::getInstance()->getI(): " << ClassicSingleton::getInstance()->getI() << std::endl;
    std::cout << "ClassicSingleton::getInstance()->getC(): " << ClassicSingleton::getInstance()->getC() << std::endl;
    
    std::cout << "ClassicSingleton::getInstance()->setI(2)" << std::endl; ClassicSingleton::getInstance()->setI(2);
    std::cout << "ClassicSingleton::getInstance()->setC('b')" << std::endl; ClassicSingleton::getInstance()->setC('b');

    std::cout << "ClassicSingleton::getInstance()->getI(): " << ClassicSingleton::getInstance()->getI() << std::endl;
    std::cout << "ClassicSingleton::getInstance()->getC(): " << ClassicSingleton::getInstance()->getC() << std::endl;
    std::cout << std::endl;
    // |-------------------------------------------|

    // |-------------------------------------------|
    std::cout << "MeyersSingleton Payload Accessing" << std::endl;
    std::cout << "MeyersSingleton::getInstance()->getI(): " << MeyersSingleton::getInstance()->getI() << std::endl;
    std::cout << "MeyersSingleton::getInstance()->getC(): " << MeyersSingleton::getInstance()->getC() << std::endl;
    
    std::cout << "MeyersSingleton::getInstance()->setI(1)" << std::endl; MeyersSingleton::getInstance()->setI(2);
    std::cout << "MeyersSingleton::getInstance()->setC('a')" << std::endl; MeyersSingleton::getInstance()->setC('b');

    std::cout << "MeyersSingleton::getInstance()->getI(): " << MeyersSingleton::getInstance()->getI() << std::endl;
    std::cout << "MeyersSingleton::getInstance()->getC(): " << MeyersSingleton::getInstance()->getC() << std::endl;
    std::cout << std::endl;
    // |-------------------------------------------|
}