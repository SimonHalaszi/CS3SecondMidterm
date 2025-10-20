/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* set

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

    Set

    - Operate on sorted containers with unique elements that arent
    necessarily std::set containers; in fact, sequential containers
    are recommended

    std::includes(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr)
        - Uses operator==
        - Returns true if first range includes a the second range elements
        - Return a bool (predicate)
        - Expected parameters
            - Two of iterators forming a half open range
            - Two of iterators forming another half open range
        - Does not expect a callback
        - in #include <algorithm>

    std::set_union(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        - Uses operator==, operator< and operator=
        - Puts the union of the two sorce ranges with the duplicates removed into target range
            - Target range must be large enough to hold this union
            - No elements are removed from source ranges or target range
            - Returns iterator past last element put into target ranges
            - Use returned iterator to trim target with erase()
        - Return iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two of iterators forming a half open source range
            - Two of iterators forming another half open source range
            - An iterator marking the start of a target source range
        - Does not expect a callback
        - in #include <algorithm>

    std::set_intersection(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        - Uses operator==, operator< and operator=
        - Puts the intersection of the two sorce ranges with the duplicates removed into target range
            - Target range must be large enough to hold this intersection
            - No elements are removed from source ranges or target range
            - Returns iterator past last element put into target ranges
            - Use returned iterator to trim target with erase()
        - Return iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two of iterators forming a half open source range
            - Two of iterators forming another half open source range
            - An iterator marking the start of a target source range
        - Does not expect a callback
        - in #include <algorithm>

    std::set_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        - Uses operator==, operator< and operator=
        - Puts the difference (compliment) of the two sorce ranges into target range
            - Difference is a new set that is the elements of set1 with in common elements of set2 removed
            - Target range must be large enough to hold this difference (compliment)
            - No elements are removed from source ranges or target range
            - Returns iterator past last element put into target ranges
            - Use returned iterator to trim target with erase()
        - Return iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two of iterators forming a half open source range
            - Two of iterators forming another half open source range
            - An iterator marking the start of a target source range
        - Does not expect a callback
        - in #include <algorithm>

    std::set_symmetric_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, target_start_itr)
        - Uses operator==, operator< and operator=
        - Puts the symmetric difference of the two sorce ranges into target range
            - Symmetric difference is the new set that is all of the elements that arent in common between set1 and set2
            - Target range must be large enough to hold this symmetric difference
            - No elements are removed from source ranges or target range
            - Returns iterator past last element put into target ranges
            - Use returned iterator to trim target with erase()
        - Return iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two of iterators forming a half open source range
            - Two of iterators forming another half open source range
            - An iterator marking the start of a target source range
        - Does not expect a callback
        - in #include <algorithm>

/ ------------------------------------------------ */