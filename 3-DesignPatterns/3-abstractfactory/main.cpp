/*

DESIGN PATTERNS

* abstract factory - motivation
  - abstract vs. concrete objects
  - factory and factory method
  - abstract vs. concrete factory, abstract vs. concrete method

c++ main.cpp
valgrind ./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <deque>
#include <algorithm>
#include "Babies.hpp"

int main() {
    std::deque<BabyFactory*> mothers;

    mothers.push_back(new BoyFactory("Columbus", 0));
    mothers.push_back(new GirlFactory("Cleveland", 0));

    for(int i = 0; i < 5; ++i) {
        BabyFactory* factory = mothers[rand() % mothers.size()];
        const Baby* newBaby = factory->getBaby();
        
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Baby info:" << std::endl;
        std::cout << "bday: " << newBaby->getBday() << std::endl;
        std::cout << "gender: " << newBaby->getGender() << std::endl;
        std::cout << "name: " << newBaby->getName() << std::endl;
        std::cout << std::endl;

        std::cout << "From: " << factory->getLocation() << std::endl;
        std::cout << "Which has made " << factory->getBabyCount() << " amount of babies." << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << std::endl; 

        // Deallocate baby
        delete newBaby;
    }

    // Deallocate factories
    std::for_each(
        mothers.begin(),
        mothers.end(),
        [](BabyFactory* bf)-> void { delete bf; }
    );
}