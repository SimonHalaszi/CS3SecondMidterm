/*

STL ALGORITHMS

CALLBACKS

* using above constructs to form callbacks with examples of
    function pointers, functors, pre defined functors, function adapters (binders)
    find_if, generate, for_each, two forms of accumulate

c++ main.cpp
./a.out > output.txt
rm ./a.out

*/

#include <iostream>
#include <vector>
#include <algorithm>    // for most algorithms
#include <functional>   // for std::placeholders
#include <numeric>      // for std::accumulate

// User defined functors and functions to demonstrate functors and function pointers

// nullary user defined functor ( for generate )
template<typename T>
class NullaryFunctor {
    public: 
        NullaryFunctor(T i) : i_(i) {}
        T operator()() { return i_; }
    private:
        T i_;
};

// nullary user defined function ( for generate )
template<typename T>
T NullaryFunction() {
    return T() + 40;
}

// unary user defined functor (for find_if)
template<typename T>
class UnaryFunctorPredicate {
    public: 
        UnaryFunctorPredicate(T j) : j_(j) {}
        bool operator()(const T& i) { return i > j_; }    
    
    private:
        T j_;
};

// unary user defined function (for find_if)
template<typename T>
bool UnaryFuntionPredicate(const T& i) {
    return i > (T() + 40);
}

// another unary user defined functor (for for_each)
template<typename T>
class UnaryFunctor {
    public:
        void operator()(const T& t) { std::cout << t << " "; }
};

// another unary user defined function (for for_each)
template<typename T>
void UnaryFunction(const T& t) {
    std::cout << t << " ";
}

// binary user defined functor ( for find_if )
template<typename T>
class BinaryFunctorPredicate {
    public:
        bool operator()(T i, T j) { return i > j; }
};

// binary user defined function ( for find_if )
template<typename T>
bool BinaryFunctionPredicate(const T& i, const T& j) {
    return i > j;
}

// another binary user defined functor ( for accumulate )
template<typename T>
class BinaryFunctorGenerator {
    public:
        T operator()(T i, T j) { return i *= j; }
};

// another binary user defined function ( for accumulate )
template<typename T>
T BinaryFunctionGenerator(const T& i, const T& j) {
    return i * j;
}

/*
* using above constructs to form callbacks with examples of
    function pointers, lambdas, functors, pre defined functors, function adapters (binders)
    find_if, generate, for_each, two forms of accumulate
*/

int main() {
    // find_if examples, find_if expects a unary predicate
    std::cout << "find_if examples, find_if expects a unary predicate" << std::endl;

    // Most examples will yield 50, its mostly different ways of doing the same thing
    std::vector<int> find_if_v = {0, 10, 20, 30, 40, 50};

    std::vector<int>::iterator find_if_itr; 
    
    // function pointer example
    bool (*unFuncPtrPred)(const int&) = UnaryFuntionPredicate<int>;

    find_if_itr = std::find_if(
        find_if_v.begin(), 
        find_if_v.end(), 
        unFuncPtrPred
    );

    std::cout << *find_if_itr << std::endl;

    // lambda example
    find_if_itr = std::find_if(
        find_if_v.begin(),
        find_if_v.end(), 
        [](const int& e)-> bool {return e > 40;}
    );

    std::cout << *find_if_itr << std::endl;

    // functors example
    find_if_itr = std::find_if(
        find_if_v.begin(),
        find_if_v.end(), 
        UnaryFunctorPredicate<int>(40)
    );

    std::cout << *find_if_itr << std::endl;

    // pre-defined functors example
    
    /*
    Only unary pre-defined functor we study is std::logical_not
    !0 is true so we will get iterator to first element
    */

    find_if_itr = std::find_if(
        find_if_v.begin(),
        find_if_v.end(), 
        std::logical_not<>()
    );

    std::cout << *find_if_itr << std::endl;

    // function adapater (binder)
    find_if_itr = std::find_if(
        find_if_v.begin(),
        find_if_v.end(), 
        std::bind(
            std::greater<>(),
            std::placeholders::_1,
            40
        )
    );

    std::cout << *find_if_itr << std::endl;

    find_if_itr = std::find_if(
        find_if_v.begin(),
        find_if_v.end(), 
        std::bind(
            BinaryFunctionPredicate<int>,
            std::placeholders::_1,
            40
        )
    );

    std::cout << *find_if_itr << std::endl;

    // generate examples, generate expects a nullary with container return type
    std::cout << "generate examples, generate expects a nullary with container return type" << std::endl;

    std::vector<int> generate_v;
    generate_v.resize(5);

    // function pointer example
    int (*nullaryFuncPtrVoid)() = NullaryFunction<int>;

    std::generate(
        generate_v.begin(), 
        generate_v.end(), 
        nullaryFuncPtrVoid
    );

    for(const int& e : generate_v) { std::cout << e << " "; } std::cout << std::endl;

    // lambda example
    std::generate(
        generate_v.begin(),
        generate_v.end(), 
        []()-> int { return 30; }
    );

    for(const int& e : generate_v) { std::cout << e << " "; } std::cout << std::endl;

    // functors example
    NullaryFunctor<int> nullaryFunctor(20);
    std::generate(
        generate_v.begin(),
        generate_v.end(), 
        nullaryFunctor
    );

    for(const int& e : generate_v) { std::cout << e << " "; } std::cout << std::endl;

    // pre-defined functors example // kinda have to also bind this so example for both
    
    auto plusser = std::bind(std::plus<>(), 5, 5);

    std::generate(
        generate_v.begin(),
        generate_v.end(), 
        plusser
    );

    for(const int& e : generate_v) { std::cout << e << " "; } std::cout << std::endl;

    // for_each examples, for_each expects a unary void function
    std::cout << "for_each examples, for_each expects a unary void function" << std::endl;

    std::vector<int> for_each_v = {50, 40, 30, 20, 10};

    // function pointer example
    void (*unaryFuncPtrFE)(const int&) = UnaryFunction<int>;

    std::for_each(
        for_each_v.begin(), 
        for_each_v.end(), 
        unaryFuncPtrFE
    );
    std::cout << std::endl;

    // lambda example
    std::for_each(
        for_each_v.begin(),
        for_each_v.end(), 
        [](const int& i)-> void { std::cout << i << " "; }
    );
    std::cout << std::endl;

    // functors example
    std::for_each(
        for_each_v.begin(),
        for_each_v.end(), 
        UnaryFunctor<int>()
    );
    std::cout << std::endl;

    // pre-defined functors example // There is no void predefined functor we study

    // nothing

    // form one accumulate doesnt expect a callback, so only one example of use
    std::cout << "form one accumulate doesnt expect a callback, so only one example of use" << std::endl;

    std::vector<int> form1_accumulate_v = {50, 40, 30, 20, 10};

    int inty = std::accumulate(
        form1_accumulate_v.begin(),
        form1_accumulate_v.end(),
        0
    );
    std::cout << inty << std::endl;

    // form two accumulate examples 
    std::cout << "form two accumulate examples, expects a binary function with container return type " << std::endl;
    // expects a binary function with value being accumulated return type
    // arg1 is the value being accumulate, value two is the current element
    std::vector<int> form2_accumulate_v = {50, 40, 30, 20, 10};
    int accumulate_me = 0;

    // function pointer example
    int (*binaryFuncPtrInt)(const int&, const int&) = BinaryFunctionGenerator<int>;

    accumulate_me = std::accumulate(
        form2_accumulate_v.begin(), 
        form2_accumulate_v.end(), 
        1,
        binaryFuncPtrInt
    );

    std::cout << accumulate_me << std::endl;

    // lambda example
    accumulate_me = std::accumulate(
        form2_accumulate_v.begin(),
        form2_accumulate_v.end(), 
        1,
        [](const int& i, const int& j)-> int { return i * j; }
    );

    std::cout << accumulate_me << std::endl;

    // functors example
    accumulate_me = std::accumulate(
        form2_accumulate_v.begin(),
        form2_accumulate_v.end(), 
        1,
        BinaryFunctorGenerator<int>()
    );

    std::cout << accumulate_me << std::endl;

    // pre-defined functors example

    accumulate_me = std::accumulate(
        form2_accumulate_v.begin(),
        form2_accumulate_v.end(), 
        1,
        std::multiplies<>()
    );

    std::cout << accumulate_me << std::endl;

}