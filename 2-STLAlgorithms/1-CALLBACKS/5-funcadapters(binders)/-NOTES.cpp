/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* funciton adapters (binders)

Notes from slides:

    Function Adapters (Binders)

        - binder (function adapter) - a specialized function that
        creates a function by assigning (binding) a value of
        parameter of another function
        
        - std::bind() a C++11 feature - most flexible binder
            newFunction = bind(oldFunction, arguments)
            
            where...
            - newFunction - function pointer to new function with bound
            parameters

            - oldFunction - function being bound

            - arguments - arguments to old function, in old-function
            parameter order
                - free specified as _1, _2, etc. These keywords are
                defined in std::placeholders namespace and you need
                to #include <functional>
                - arguments given as specified value are bound to that
                value

        - auto is useful as type of newFunction, otherwise it can be
        complicated to understand what function pointer you need

        - behavior of oldFunction not changed

        - EX:
            // binds second parameter to value of str
            auto f1 = std::bind(myFunc, std::placeholders::_1, str);
            // swaps parameters
            auto f2 = std::bind(myFunc, std::placeholders::_2, std::placeholders::_1);

    Using Binders to Form Callbacks

        - binders useful in forming callbacks for algorithims inline
        
        - for example, find_if() expects a callback that has one parameter
        but std::greater<>() functor has two inputs. So if I want to use
        std::greater<>() as a callback for find_if() I have to bind the
        right parameter to make it a one parameter functor.

        -EX:
            std::vector<int> v = {10, 20, 30, 40, 50};
            // will get itr to element that has value 30
            std::vector<int>::iterator itr = std::find_if(v.begin(), v.end(), std::bind(std::greater<>(), std::placeholders::_1, 20));

/ ------------------------------------------------ */