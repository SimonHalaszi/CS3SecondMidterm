/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* utility

// Key for understanding
std::algorithm_name(parameters)
    - Operator overloads used internally
    - Description
    - Return type
    - Expected Parameters
    - Expects a callback of form
        - callback return type
        - describe arguments
    - in #include <>

|-----------------------------------------------------------------------------------------|

Short List:
    Utility Algorithms
        itr = std::min(x, y)
        itr = std::max(x, y)
        pair<itr, itr> = std::minmax(x, y)
        void std::swap(x, y)
    
|-----------------------------------------------------------------------------------------| 

Notes from slides:

    Utility Algorithms

        - min, max, minmax, swap
        - operate on a couple of elements
        - use operator<
        - use function templates

        std::min(x, y)
            - Uses operator<
            - Returns smaller value of the two
            - Return type is same type of x and y
            - Expects an x and y of same type, type must have operator<() overloaded
            - May accept binary predicate
            - in #include <algorithm>

        std::max(x, y)
            - Uses operator<
            - Returns bigger value of the two
            - Return type is same type of x and y
            - Expects an x and y of same type, type must have operator<() overloaded
            - May accept binary predicate
            - in #include <algorithm>      
            
        std::minmax(x, y)
            - Uses operator<
            - Returns a pair of the min and max, min is pair.first, max is pair.second
            - Return type is std::pair<xy_type, xy_type>
            - Expects an x and y of same type, type must have operator<() overloaded
            - May accept binary predicate
            - in #include <algorithm>     

        std::swap(x, y)
            - Uses operator=
            - Swaps the values inside of x and y
            - Is a void function
            - Expects an x and y of same type, type must have operator=() overloaded
            - No expected callback
            - in #include <algorithm>                

        - By default the min, max, and minmax algorithms use operator<() but you may
        call them with a binary predicate callback to change this
        
/ ------------------------------------------------ */
