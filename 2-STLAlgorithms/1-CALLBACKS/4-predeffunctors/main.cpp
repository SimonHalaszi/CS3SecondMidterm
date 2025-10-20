/*

STL ALGORITHMS

CALLBACKS

* predefined functors
    - arithmetic, comparison, logical

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>

// need 
#include <functional> // contains the predefined functors

int main() {
    // ------------------------------------------ //
    // arithmetic functors
    
    std::cout << "arithmetic functors" << std::endl << std::endl;
    
    std::plus<int> adder;
    
    std::cout << "std::plus<int> adder; ";
    std::cout << "adder(5, 5) = " << adder(5, 5) << std::endl;
    std::cout << "5 + 5 = " << 5 + 5 << std::endl;

    std::minus<int> subtractor;
    
    std::cout << "std::minus<int> subtractor; ";
    std::cout << "subtractor(5, 2) = " << subtractor(5, 2) << std::endl;
    std::cout << "5 - 2 = " << 5 - 2 << std::endl;    

    std::multiplies<int> multiplier;
    
    std::cout << "std::multiplies<int> multiplier; ";
    std::cout << "multiplier(5, 2) = " << multiplier(5, 2) << std::endl;   
    std::cout << "5 * 2 = " << 5 * 2 << std::endl;    

    std::divides<double> divider;
    
    std::cout << "std::divides<double> divider; ";
    std::cout << "divider(5.1, 2.3) = " << divider(5.1, 2.3) << std::endl;    
    std::cout << "5.1 / 2.3 = "  << 5.1 / 2.3 << std::endl;
    
    std::modulus<int> modulizer;

    std::cout << "std::modulus<int> modulizer; ";
    std::cout << "modulizer(3, 2) = " << modulizer(3, 2) << std::endl;    
    std::cout << "3 % 2 = "  << (3 % 2) << std::endl;
    
    // ------------------------------------------ //

    // ------------------------------------------ //
    // comparison functors

    std::cout << std::endl << "comparison functors" << std::endl << std::endl;
    
    std::equal_to<int> equater;
    
    std::cout << "std::equal_to<int> equater; ";
    std::cout << "equater(5, 5) = " << equater(5, 5) << std::endl;
    std::cout << "5 == 5 = " << (5 == 5) << std::endl;

    std::not_equal_to<int> notequater;
    
    std::cout << "std::not_equal_to<int> notequater; ";
    std::cout << "notequater(5, 5) = " << notequater(5, 5) << std::endl;
    std::cout << "5 != 5 = " << (5 != 5) << std::endl;

    std::less<double> lesser;
    
    std::cout << "std::less<double> lesser; ";
    std::cout << "lesser(5.1, 5.1) = " << lesser(5.1, 5.1) << std::endl;
    std::cout << "5.1 < 5.1 = " << (5.1 < 5.1) << std::endl;
        
    std::greater<double> greater;
    
    std::cout << "std::greater<double> greater; ";
    std::cout << "greater(5.1, 5.1) = " << greater(5.1, 5.1) << std::endl;
    std::cout << "5.1 > 5.1 = " << (5.1 > 5.1) << std::endl;

    std::less_equal<double> lesserequal;
    
    std::cout << "std::less_equal<double> lesserequal; ";
    std::cout << "lesserequal(5.1, 5.1) = " << lesserequal(5.1, 5.1) << std::endl;
    std::cout << "5.1 <= 5.1 = " << (5.1 <= 5.1) << std::endl;
        
    std::greater_equal<double> greaterequal;
    
    std::cout << "std::greater_equal<double> greaterequal; ";
    std::cout << "greaterequal(5.1, 5.1) = " << greaterequal(5.1, 5.1) << std::endl;
    std::cout << "5.1 >= 5.1 = " << (5.1 >= 5.1) << std::endl;

    // ------------------------------------------ //
    // logical functors

    std::cout << std::endl << "logical functors" << std::endl << std::endl;

    std::logical_and<bool> ander;
    
    std::cout << "std::logical_and<bool> ander; ";
    std::cout << "ander(true, true) = " << ander(true, true) << std::endl;
    std::cout << "true && true = " << (true && true) << std::endl;
    
    std::logical_or<bool> orer;
    
    std::cout << "std::logical_or<bool> orer; ";
    std::cout << "orer(true, true) = " << orer(true, true) << std::endl;
    std::cout << "true || true = " << (true || true) << std::endl;
    
    std::logical_not<bool> noter;
    
    std::cout << "std::logical_not<bool> noter; ";
    std::cout << "noter(true) = " << noter(true) << std::endl;
    std::cout << "!true = " << (!true) << std::endl;    
}