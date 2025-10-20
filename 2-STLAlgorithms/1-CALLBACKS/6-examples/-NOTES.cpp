/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* using above constructs to form callbacks with examples of
    find_if, generate, for_each, two forms of accumulate

// Key for understanding
std::algorithm_name(parameters)
    - Operator overloades used internally
    - Description
    - Return type
    - Expected parameters
        - Parameter description(s)
    - Expects a callback of form
        - callback return type
        - describe arguments
    - in #include <>

Notes:

    std::find_if(start_itr, end_itr, unary_predicate)
        - Returns iterator to first element that meets predicate condition
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
            - A unary predicate
        - Expects a unary predicate callback
            - boolean return type (predicate)
            - element_type parameter that will be current element being analyzed
        - in #include <algorithm> 
    
    std::generate(start_itr, end_itr, nullary_callback)
        - Overwrites elements in range with values from callback
        - Return type is void
        - Expected parameters
            - Two iterators forming a half open range
            - A nullary callback
        - Expects nullary callback
            - Containers element type return type
            - No arguments (nullary)
        - in #include <algorithm>

    std::for_each(start_itr, end_itr, unary_callback)
        - Executes the given callback on every element in the range
        - Returns the callback function (we dont really talk about this)
        - Expected parameters
            - Two iterators forming a half open range
            - A unary callback
        - Expects a unary callback
            - Any return value but returned value is ignored
            - Expects a parameter of containers element type
        - in #include <algorithm>

    // Form one
    std::accumulate(start_itr, end_itr, initial_value)
        - Uses operator+(initial_value_type, containers_elements_type)
        - Uses operator+ to accumulate starting from initial_value
        - Returns type is same as inital values type
        - Expected parameters
            - Two iterators forming a half open range
            - An initial value to accumulate onto
        - Expects no callback
        - in #include <numeric>      

    // Form two
    std::accumulate(start_itr, end_itr, initial_value, binary_callback)
        - Uses given callback to accumulate starting from initial_value
        - Returns type is same as inital values type
        - Expected parameters
            - Two iterators forming a half open range
            - An initial value to accumulate onto
            - A binary callback
        - Expects a binary callback
            - Return type same as initial values type
            - Takes in the accumulating value as first parameter
            - Takes in the current element as second parameter
        - in #include <numeric> 

/ ------------------------------------------------ */