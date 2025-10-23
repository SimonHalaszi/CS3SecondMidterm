/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* std::function

Notes from slides:

    std::function

        - there is many different constructs for callbacks
        that all do the same thing
            - normal functions
            - function pointers
            - lambdas
            - functors (user-defined and predefined)
            - binded functions
        
        - std::function is a construct that can point to
        ANY of them, under a uniform name as "function objects"

        - inside of #include <functional>

        - signature is in angle brackets

        - EX:
            std::function<return_type(parameters)> function_obj_name;
        
        - Polymorphic construct for callbacks. Always manipulation
        and use of any type of callback as a universal typing. Does
        this through type erasure.

/ ------------------------------------------------ */
