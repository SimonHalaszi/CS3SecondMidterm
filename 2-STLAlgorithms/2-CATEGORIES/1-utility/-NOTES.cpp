/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* utility

// Key for understanding
std::algorithm_name(parameters)
    - Description
    - Return type
    - Expected Parameters
    - Expects a callback of form
        - callback return type
        - describe arguments
    - in #include <>

Notes from slides:

    Utility Algorithms

        - min, max, minmax, swap
        - operate on a couple of elements
        - use operator<
        - use function templates

        std::min(x, y)
            - Returns smaller value of the two
            - Return type is same type of x and y
            - Expects an x and y of same type, type must have operator<() overloaded
            - No expected callback
            - in #include <algorithm>

        std::max(x, y)
            - Returns bigger value of the two
            - Return type is same type of x and y
            - Expects an x and y of same type, type must have operator<() overloaded
            - No expected callback
            - in #include <algorithm>      
            
        std::minmax(x, y)
            - Returns a pair of the min and max, min is pair.first, max is pair.second
            - Return type is std::pair<xy_type, xy_type>
            - Expects an x and y of same type, type must have operator<() overloaded
            - No expected callback
            - in #include <algorithm>     

        std::swap(x, y)
            - Swaps the values inside of x and y
            - Is a void function
            - Expects an x and y of same type, type must have operator=() overloaded
            - No expected callback
            - in #include <algorithm>                

        - By default the min, max, and minmax algorithms use operator<() but you may
        call them with a binary predicate callback to change this
        
/ ------------------------------------------------ */