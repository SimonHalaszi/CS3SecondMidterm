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
valgrind ./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include "Shape.hpp"

int main() {
    // Template Method Pattern can be used to interface with any derived class
    Shape* myShape;

    myShape = new Rectangle(10, 30, 'o');

    myShape->renderToConsole(); 

    delete myShape;

    myShape = new Square(20, 'c');

    myShape->renderToConsole(); 

    delete myShape;

    // Or can use rectangle to interface with square

    Rectangle* myRectangle;

    myRectangle = new Square(10, 'e');

    myRectangle->renderToConsole(); 
    
    delete myRectangle;

    // Or can just make a square if I wanted

    Square mySquare = Square(20, 'd');

    mySquare.draw();
    std::cout << mySquare.area() << std::endl;

    // Square has dynamic variables that will get freed correctly despite being lowest level of
    // inheritance. This is using base class destructor idiom
}