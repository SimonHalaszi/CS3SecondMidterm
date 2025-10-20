/*

STL ALGORITHMS

CALLBACKS

* function pointers

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

int exampleFunc(char c) {
    return static_cast<int>(c);
}

int main() {
    // Printing out exampleFunc definition
    std::cout << "int exampleFunc(char c) {" << std::endl;
    std::cout << "return static_cast<int>(c);" << std::endl;
    std::cout << "}" << std::endl << std::endl;

    // Calling exampleFunc
    std::cout << "exampleFunc('a'): " << exampleFunc('a') << std::endl << std::endl;

    int (*funcPtr)(char);   // Declaring funcPtr with same signature as exampleFunc
    std::cout << "int (*funcPtr)(char);" << std::endl;
    funcPtr = exampleFunc;  // Setting funcPtr to exampleFunc
    std::cout << "funcPtr = exampleFunc;" << std::endl << std::endl;

    // Same call as exampleFunc same result
    std::cout << "funcPtr('a'): " << funcPtr('a') << std::endl << std::endl;

    void (*wrongFuncPtr)(bool);   // Declaring funcPtr with same signature as exampleFunc
    std::cout << "void (*wrongFuncPtr)(bool);" << std::endl;
    // wrongFuncPtr = exampleFunc; 
    // WONT COMPILE SIGNATURES DONT MATCH
    std::cout << "wrongFuncPtr = exampleFunc;" << std::endl;
    std::cout << "// WONT COMPILE SIGNATURES DONT MATCH" << std::endl << std::endl;

    // More on lambdas later but can make function pointers point to them
    // Set wrongFuncPtr to lambda with same signature, that is, no context, takes a bool, returns void
    wrongFuncPtr = [](bool b)->void { std::cout << b << std::endl; };
    std::cout << "wrongFuncPtr = [](bool b)->void{ std::cout << b << std::endl; };" << std::endl;

    std::cout << "wrongFuncPtr(true);" << std::endl;
    wrongFuncPtr(true);

    /*
    
    Pointed to lambda is not dynamically allocated or anything, lambda exist
    in the programs text segment, but if I pointer wrongFuncPtr else where there
    would be no way back to my lambda similar to dynamically allocated variable.    
    
    */
}