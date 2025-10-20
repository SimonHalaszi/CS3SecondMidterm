/*

STL ALGORITHMS

CALLBACKS

* funciton adapters (binders)

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void func(int i, char j) {
    std::cout << i << " " << j << std::endl;
}

int main() {
    std::cout << "void func(int i, char j) {" << std::endl;
    std::cout << "    std::cout << i << " " << j << std::endl;" << std::endl;
    std::cout << "}" << std::endl;
    
    std::cout << "func(1, 'a');" << std::endl;
    // normal call of func
    func(1, 'a');
    
    std::cout << "auto bindfunc = std::bind(func, std::placeholders::_1, 'a'); bindfunc(1);" << std::endl;
    // bindfunc to bind 'a' to second parameter
    auto bindfunc = std::bind(func, std::placeholders::_1, 'a');
    // call bindfunc
    bindfunc(1);
    
    std::cout << "auto bindfunc2 = std::bind(func, 1, std::placeholders::_1); bindfunc2('a');" << std::endl;
    // bindfunc2 to bind '1' to first parameter
    auto bindfunc2 = std::bind(func, 1, std::placeholders::_1);
    // call bindfunc2
    bindfunc2('a');
    
    std::cout << "auto bindfunc3 = std::bind(func, std::placeholders::_2, std::placeholders::_1); bindfunc3('a', 1);" << std::endl;
    // bindfunc3 to swap the parameters of func
    auto bindfunc3 = std::bind(func, std::placeholders::_2, std::placeholders::_1);
    // call bindfunc3
    bindfunc3('a', 1);

    std::vector<int> v = {10, 20, 30, 40, 50};

    // find first element greater than 20 with lambda
    std::vector<int>::iterator itr = std::find_if(
        v.begin(), 
        v.end(), 
        [](int& e)-> bool { return e > 20; }
    );

    std::cout << *itr << std::endl;

    // but what if I want to use predefined functor for this?
    
    // CANT DO THIS. So how?
    // itr = std::find_if(
    //     v.begin(), 
    //     v.end(), 
    //     std::greater<int>()(e, 20)
    // );
    
    // find first element greater than 20 with binded predefined functor
    std::vector<int>::iterator bitr = std::find_if(
        v.begin(), 
        v.end(), 
        std::bind(
            std::greater<>(),
            std::placeholders::_1,
            20
        )
    );

    std::cout << *bitr << std::endl;

}