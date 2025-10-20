/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* non-modifying

// Key for understanding
std::algorithm_name(parameters)
    - Operator overloads used internally
    - Description
    - Return type
    - Expected parameters
        - Parameter description(s)
    - Expects a callback of form
        - callback return type
        - describe arguments
    - in #include <>

Notes from slides:

    Non-Modifying Search Algorithms 

    std::find_if(start_itr, end_itr, unary_predicate)
        - Overloads not used
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
        
    std::find_if_not(start_itr, end_itr, unary_predicate)
        - Overloads not used
        - Returns iterator to first element that does not meet predicate condition
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
            - A unary predicate
        - Expects a unary predicate callback
            - boolean return type (predicate)
            - element_type parameter that will be current element being analyzed
        - in #include <algorithm>   
        
    std::min_element(start_itr, end_itr)
        - Uses operator<
        - Returns iterator to minimum element
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
        - May accept a binary predicate callback
        - in #include <algorithm>   

    std::max_element(start_itr, end_itr)
        - Uses operator<
        - Returns iterator to maximum element
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
        - May accept a binary predicate callback
        - in #include <algorithm>   

    std::minmax_element(start_itr, end_itr)
        - Uses operator<
        - Returns pair of iterators
            - pair.first is iterator to minimum element
            - pair.second is iterator to maximum element
        - Returns pair of iterators of std::pair<std::container<element_type>::iterator, std::container<element_type>::iterator>
        - Expected parameters
            - Two iterators forming a half open range
        - May accept a binary predicate callback
        - in #include <algorithm>   

    std::adjacent_find(start_itr, end_itr)
        - Uses operator==
        - Returns iterator such that iterator and ++iterator have elements of the same value
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::find_first_of(start_itr, end_itr, candidates_start_itr, candidates_end_itr)
        - Uses operator==
        - Returns first iterator such that element exist inside of candidates range
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Another two iterators forming a range of candidates
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::search(start_itr, end_itr, find_start_itr, find_end_itr)
        - Uses operator==
        - Returns an iterator to the start of a found subsequence in source range equal to find range sequence
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Another two iterators form a range that contains a sequence to find
        - May accept a binary predicate callback
        - in #include <algorithm>
    
    std::search_n(start_itr, end_itr, n, value)
        - Uses operator==
        - Returns an iterator to start of subsequence of n number of elements equal to value in a row
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - An integer n which will be the number of consecutive equal elements
            - Value that elements will be equal to
        - May accept a binary predicate callback
        - in #include <algorithm>
        
    std::binary_search(start_itr, end_itr, value)
        - Uses operator< and operator==
        - Expects sorted range of elements, returns true if an element equals value
        - Returns boolean
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Value that element will be equal to
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::lower_bound(start_itr, end_itr, value)
        - Uses operator< and operator==
        - Expects sorted range of elements
        - Returns an iterator to first element equal to or greater than value
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Value that element will be equal to or greater than
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::upper_bound(start_itr, end_itr, value)
        - Uses operator<
        - Expects sorted range of elements
        - Returns an iterator to first element greater than value
            - If not found returns end_itr
        - Returns iterator of std::container<element_type>::iterator
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Value that element will be greater than
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::equal_range(start_itr, end_itr, value)
        - Uses operator< and operator==
        - Expects sorted range of elements
        - Returns a pair of iterators
            - pair.first will be an iterator to first element equal to or greater than value
            - pair.second will be an iterator to element greater than value
            - If value not found may be end_itr
        - Returns pair of iterators of std::pair<std::container<element_type>::iterator, std::container<element_type>::iterator>
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Value to search for
        - May accept a binary predicate callback
        - in #include <algorithm>    

    Non-Modifying Quantifier Algorithms

    std::all_of(start_itr, end_itr, unary_predicate)
        - Overloads not used
        - Returns true if all elements satisfy the predicate
        - Returns boolean
        - Expected parameters
            - Two iterators forming a half open range 
            - A unary Predicate
        - Expects a unary predicate callback
            - Boolean return type (predicate)
            - Parameter of same type as containers element type
        - in #include <algorithm>

    std::any_of(start_itr, end_itr, unary_predicate)
        - Overloads not used
        - Returns true if any elements satisfy the predicate
        - Returns boolean
        - Expected parameters
            - Two iterators forming a half open range 
            - A unary Predicate
        - Expects a unary predicate callback
            - Boolean return type (predicate)
            - Parameter of same type as containers element type
        - in #include <algorithm>    

    std::none_of(start_itr, end_itr, unary_predicate)
        - Overloads not used
        - Returns true if all elements fail to satisfy the predicate
        - Returns boolean
        - Expected parameters
            - Two iterators forming a half open range 
            - A unary Predicate
        - Expects a unary predicate callback
            - Boolean return type (predicate)
            - Parameter of same type as containers element type
        - in #include <algorithm> 

    Non-Modifying Comparison Algorithms 
    
    std::equal(start_itr, end_itr, start_itr_two, end_itr_two)
        - Uses operator==
        - Returns true if ranges are equal
        - Returns boolean
        - Expected parameters
            - Two iterators forming a half open range
            - Two iterators forming another half open range
        - May accept a binary predicate callback
        - in #include <algorithm>
    
    std::mismatch(start_itr, end_itr, start_itr_two, end_itr_two)
        - Uses operator==
        - Returns a pair of iterators to first pair of mismatched elements in the ranges
            - pair.first iterator to first mismatched element in first range
            - pair.second iterator to second mismatched element in second range
            - if the ranges are equal then the pair would be {end_itr, end_itr_two}
        - Returns a pair of iterators of std::pair<std::container<element_type>::iterator, std::container<element_type>::iterator>
        - Expected parameters
            - Two iterators forming a half open range
            - Two iterators forming another half open range
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::lexicographical_compare(start_itr, end_itr, start_itr_two, end_itr_two)
        - Uses operator<
        - Returns true if first range is lexicograpically smaller than second
        - Returns boolean
        - Expected parameters
            - Two iterators forming a half open range
            - Two iterators forming another half open range
        - May accept a binary predicate callback
        - in #include <algorithm>        

    Non-Modifying Operational Algorithms 

    // Can actually be modifying if the callback takes element by reference

    std::for_each(start_itr, end_itr, unary_callback)
        - Overloads not used
        - Executes the given callback on every element in the range
        - Returns the callback function (we dont really talk about this)
        - Expected parameters
            - Two iterators forming a half open range
            - A unary callback
        - Expects a unary callback
            - Any return value but returned value is ignored
            - Expects a parameter of containers element type
        - in #include <algorithm>

    Non-Modifying Numerical Processing Algorithms 

    std::count(start_itr, end_itr, value)
        - Uses operator==
        - Returns number of elements equal to value
        - Returns integer
        - Expected parameters
            - Two iterators forming a half open range
            - Value to count the number of occurence of
        - Expects no callback
        - in #include <algorithm>
    
    std::count_if(start_itr, end_itr, unary_predicate)
        - Overloads not used
        - Returns number of elements that meet predicate condition
        - Returns integer
        - Expected parameters
            - Two iterators forming a half open range
            - Unary predicate callback
        - Expects a unary predicate
            - Returns a bool (predicate)
            - Parameter is of the same type as the containers elements
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
        - Overloads not used
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