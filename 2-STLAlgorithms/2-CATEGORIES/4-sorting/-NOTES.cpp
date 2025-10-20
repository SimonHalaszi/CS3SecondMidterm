/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* sorting

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

Notes:

    Sorting

    std::sort(start_itr, end_itr)
        - Uses operator< and operator=
        - Sorts the elements of a container in ascending order
        - Return type is void 
        - Expected parameters
            - Two iterators forming a half open range
        - May accept a binary predicate in place of operator< operation
        - in #include <algorithm>

    std::merge(source_start_itr, source_end_itr, source2_start_itr, source2_end_itr, targert_start_itr)
        - Uses operator< and operator=
        - Linear merge of two sorted sorted source ranges into target range
            - Target range must be large enough to hold this merging
            - No elements are removed from source ranges or target range
            - Returns iterator to element past last merged in element in target range
            - Use returned iterator to trim target with erase()
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open source range
            - Two iterators forming another half open source range
            - An iterator marking the start of a target range
        - May accept a binary predicate in place of operator< operation
        - in #include <algorithm>

    std::unique(start_itr, end_itr)
        - Uses operator== and operator=
        - Returns iterator to first of unwanted back elements, unwanted elements
        are sequential copies of a preceding element, useful for sorted containers
            - If nothing 'removed'/unwanted returns end_itr and changes nothing
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
        - Expects no callback
        - in #include <algorithm>

        - Note: Similar to remove and remove_if in the moving sense

    std::binary_search(start_itr, end_itr, value)
        - Uses operator< and operator==
        - Expects sorted range of elements, returns true if an element equals value
        - Returns boolean
        - Expect parameters
            - Two iterators forming a half open range of elements to search
            - Value that element will be equal to
        - May accept a binary predicate callback
        - in #include <algorithm>

    std::random_shuffle(start_itr, end_itr)
        - Uses operator=
        - Randomly shuffles containers elements
        - Return type is void 
        - Expected parameters
            - Two iterators forming a half open range
        - Does not expect a callback
        - in #include <algorithm>

        - Note: No longer recommended by the standard, use std::shuffle with an inputted randome number generator


/ ------------------------------------------------ */