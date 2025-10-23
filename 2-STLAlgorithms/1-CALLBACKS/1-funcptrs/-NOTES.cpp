/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* function pointers

Notes from slide:
    
    Function Pointers

        - function pointer: holds address to start of functions code
        
        - can be used to invoke a funciton indirectly, have array of
        functions, pass function as a parameter
        
        - function name is a function poiinter

        - declare
            return_type (*funcptr_name)(parameters);

            - paratheses around funcptr_name because star operator
            has lower precedence than function call operator (). Same
            reason arrow operator exist for short hand of (*ptr).func()

            - Also so funcptr_name doesnt get interpretted as a function
            that returns a pointer but as a function pointer
        
        - intialize and reassign
            funcptr_name = otherfunc_name; // Must have same signature
        
        - used same as normal function
            funcptr_name(55); // calls funcptr_name

Side notes:

    Think like how a C-style arrays identifier is actually a pointer
    to the start of that array. So yes we interact with C-style arrays
    with the identifier but its actually a pointer. Same deal with functions
    and we can use pointers to interface with functions.

/ ------------------------------------------------ */