/*

STL ALGORITHMS

CALLBACKS

* std::function

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <functional>   // need for std::function and std::placeholders
#include <algorithm>    // for std::for_each

// A unary functor
template<typename T>
class UnaryFunctor {
    public:
        void operator()(const T& t) { std::cout << t << " "; }
};

// A unary function
template<typename T>
void UnaryFunction(const T& t) {
    std::cout << t << " ";
}

// A unary function
template<typename T>
void BinaryFunction(const T& t, const char& tt) {
    std::cout << t << tt;
}

int main() {
    // std::function declaration
    std::function<void(int)> function_void_int;

    // assigning to normal function
    std::cout << "assigning to normal function" << std::endl;
    function_void_int = UnaryFunction<int>;
    function_void_int(10);
    std::cout << std::endl;

    // assigning to lambda
    std::cout << "assigning to lambda" << std::endl;
    function_void_int = [](const int& i)-> void { std::cout << i << " "; };
    function_void_int(10);
    std::cout << std::endl;

    // saving a lambda for a later trick
    void (*lambdaHolder)(int) = [](int i)-> void { std::cout << i << " "; };

    // assigning to function pointer
    std::cout << "assigning to function pointer" << std::endl;
    void (*unaryFuncPtr)(const int&) = UnaryFunction<int>;
    function_void_int = unaryFuncPtr;
    function_void_int(10);
    std::cout << std::endl;

    // assigning to functor
    std::cout << "assigning to functor" << std::endl;
    function_void_int = UnaryFunctor<int>();
    function_void_int(10);
    std::cout << std::endl;

    // assigning to binded function
    std::cout << "assigning to binded function" << std::endl;
    auto bindedFunctor = std::bind(BinaryFunction<int>, std::placeholders::_1, ' ');
    function_void_int = bindedFunctor;
    function_void_int(10);
    std::cout << std::endl;

    // The flexibility of std::function allows for stuff like this

    // a vector holding all sorts of callbacks, 5 different types in its entirety!
    std::cout << "a vector holding all sorts of callbacks, 5 different types in its entirety!" << std::endl;

    std::vector<std::function<void(int)>> vector_of_std_functions;
    vector_of_std_functions.push_back(UnaryFunction<int>);
    vector_of_std_functions.push_back(lambdaHolder);
    vector_of_std_functions.push_back(unaryFuncPtr);
    vector_of_std_functions.push_back(UnaryFunctor<int>());
    vector_of_std_functions.push_back(bindedFunctor);

    std::vector<int> v = {10, 20, 30, 40, 50};

    for(const auto& f : vector_of_std_functions) {
        static int index = 0;
        std::cout << "function index: " << index << std::endl;
        std::for_each(
            v.begin(),
            v.end(),
            f
        );
        std::cout << std::endl;
        ++index;
    }

}