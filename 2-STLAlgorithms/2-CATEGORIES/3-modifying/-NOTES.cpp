/* ------------------------------------------------ /

STL ALGORITHMS

CATEGORIES

* modifying
    - remove-erase idiom
    - source and target range

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

|-----------------------------------------------------------------------------------------|

Short List:
    Modifying: Remove (and Erase)
        itr = std::remove(start_itr, end_itr, element_value)
        itr = std::remove_if(start_itr, end_itr, unary_predicate)
        
    Modifying Algorithms
        itr_in_target = std::transform(source_start_itr, source_end_itr, target_start_itr, unary_callback) // form one
        itr_in_target = std::transform(source_start_itr, source_end_itr, second_source_start_itr, target_start_itr, binary_callback) // form two
        itr_in_target = std::copy(source_start_itr, source_end_itr, target_start_itr)
        itr_in_target = std::copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        itr_in_target = std::remove_copy(source_start_itr, source_end_itr, target_start_itr, source_element_value)
        itr_in_target = std::remove_copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        itr_in_target = std::move(source_start_itr, source_end_itr, target_start_itr)

    Modifying Algorithms that Operate on a Single Range
        void std::replace(start_itr, end_itr, value_to_replace, replace_with_value)
        void std::replace_if(start_itr, end_itr, unary_predicate, replace_with_value)
        void std::reverse(start_itr, end_itr)
        itr = std::unique(start_itr, end_itr)
        void std::generate(start_itr, end_itr, nullary_callback)
        void std::generate_n(start_itr, n, nullary_callback)
        
    
|-----------------------------------------------------------------------------------------|  

Notes from slides:

    Modifying: Remove (and Erase)

    'Remove' in the context of these algorithms means to shift all wanted
    data to the front of the container and to overwrite the unwanted values
    with present data. This leaves the back of the container with undefined
    values.

    say...
    
    d contains {10, 20, 30, 40, 50, 40, 30}

    itr = std::remove(d.begin(), d.end(), 30)

    d contains {10, 20, 40, 50, 40, ??, ??}
                                    ^
                                    itr is iterator to unwanted back elements

    std::remove(start_itr, end_itr, element_value)
        - Uses operator== and operator=
        - Returns iterator to first of unwanted back elements, unwanted elements
        are elements that are equal to given element_value
            - If nothing 'removed'/unwanted returns end_itr and changes nothing
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
            - A element_value of the same type as containers elements
        - Expects no callback
        - in #include <algorithm>

    std::remove_if(start_itr, end_itr, unary_predicate)
        - Uses operator=
        - Returns iterator to first of unwanted back elements, unwanted elements
        are elements that meet the predicates conditions
            - If nothing 'removed'/unwanted returns end_itr and changes nothing
        - Returns iterator of std::container<element_type>::iterator
        - Expected parameters
            - Two iterators forming a half open range
            - A unary predicate callback
        - Expects unary predicate callback
            - Boolean return type (predicate)
            - Parameter of container elements type to pass in current element
        - in #include <algorithm>

    - Both of these algorithms are considered so called modifying algorithms

    - Do not erase elements from containers (do not know if whole or full range)
        - Instead move wanted elements forward
        - Return iterator past last wanted element
        - Aka return iterator to first unwanted element

    - remove-erase-idiom - Get the returned iterator and then use the containers
    erase() function to eliminate removed elements
        - Can be done in a single line
        - EX:
            d contains {10, 20, 30, 40, 50, 40, 30}

            d.erase(std::remove(d.begin(), d.end(), 30), d.end());

            d contains {10, 20, 40, 50, 40}

    - Remove function is linear O(n) invocation. For random access containers
    memory reorganization to keep continous, so large objects with no move
    semantics can cause remove to be slow. Lots of copying will take place
    during reorganization of continous elements. Results in quadratic complexity

    Modifying Algorithms

    - Usually operate on two ranges
        - source range
        - destination (target) range

        - Ranges may be unrelated, overlapping or the same

        - WARNING: Source range must be as long or less long than latter supplied ranges

    // Form one
    std::transform(source_start_itr, source_end_itr, target_start_itr, unary_callback)
        - Uses operator= where target_element = source_element
        - Applies unary callback on element in source range and writes the return
        value of that callback into the target range.
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last written element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
            - A unary callback
        - Expects unary callback
            - Return type of target range container elements type
            - Parameter of same type as source container elements type to pass in current element in source range
        - in #include <algorithm>    

    // Form two
    std::transform(source_start_itr, source_end_itr, second_source_start_itr, target_start_itr, binary_callback)
        - Uses operator= where target_element = source_element
        - Applies binary callback on elements of the two source ranges and writes the return
        value of that callback into the target range.
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last written element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of another source range
            - An iterator marking the start of the target range
            - A binary callback
        - Expects binary callback
            - Return type of target range container elements type
            - Left parameter of same type as source container elements type to pass in current element in first source range
            - Right parameter of same type as source container elements type to pass in current element in second source range
        - in #include <algorithm>

    std::copy(source_start_itr, source_end_itr, target_start_itr)
        - Uses operator= where target_element= source_element
        - Copies elements of source range to target range
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last copied element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
        - Does not expect a callback
        - in #include <algorithm> 
    
    std::copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        - Uses operator= where target_element = source_element
        - Copies elements of source range to target range if the elements meet the callback condition
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last copied element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
            - A unary predicate
        - Expects unary predicate callback
            - Return bool (predicate)
            - Parameter of same type as source container elements type to pass in current element in source range
        - in #include <algorithm> 

    std::remove_copy(source_start_itr, source_end_itr, target_start_itr, source_element_value)
        - Uses operator= where target_element = source_element
          Uses operator== where source_element == source_element_value
        - Copies elements of source range to target range if the elements arent equal to source_element_value
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last copied element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
            - A value of a source range element
        - Does not expect a callback
        - in #include <algorithm> 

    std::remove_copy_if(source_start_itr, source_end_itr, target_start_itr, unary_predicate)
        - Uses operator= where target_element = source_element
        - Copies elements of source range to target range if the elements *fail* to meet the callback condition
          Or in other words
          Does not copy elements of source range to target range if they meet the callback condition
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last copied element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
            - A unary predicate
        - Expects unary predicate callback
            - Return bool (predicate)
            - Parameter of same type as source container elements type to pass in current element in source range
        - in #include <algorithm> 

    std::move(source_start_itr, source_end_itr, target_start_itr)
        - Uses move semantics operator= where target_element = source_element
        - Moves elements of source range into target range, leaves source elements in legal but undefined state
        - Returns iterator of std::container<element_type>::iterator
            - Iterator to just past last moved element in target range
        - Expected parameters
            - Two iterators forming a half open source range
            - An iterator marking the start of the target range
        - Does not expect a callback
        - in #include <algorithm> 

        - NOTE: There is no move_if

    Modifying Algorithms that Operate on a Single Range

    std::replace(start_itr, end_itr, value_to_replace, replace_with_value)
        - Uses operator=
        - Replaces value_to_replace elements with replace_with_value
        - Returns nothing, is void
        - Expected parameters
            - Two iterators forming a half open range
            - A value to replace
            - A value to replace values that need replace with
        - Does not expect a callback
        - in #include <algorithm>

    std::replace_if(start_itr, end_itr, unary_predicate, replace_with_value)
        - Uses operator=
        - Replaces elements that meet predicate condition with replace_with_value
        - Returns nothing, is void
        - Expected parameters
            - Two iterators forming a half open range
            - A unary predicate
            - A value to replace values that need replace with
        - Expects unary predicate callback
            - Return bool (predicate)
            - Parameter of same type as container elements type to pass in current element
        - in #include <algorithm>
    
    std::reverse(start_itr, end_itr)
        - Uses operator=
        - Reverse the order of the elements in the range
        - Returns nothing, is void
        - Expected parameters
            - Two iterators forming a half open range
        - Does not expect a callback
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

    std::generate(start_itr, end_itr, nullary_callback)
        - Uses operator=
        - Overwrites elements in range with values from callback
        - Return type is void
        - Expected parameters
            - Two iterators forming a half open range
            - A nullary callback
        - Expects nullary callback
            - Containers element type return type
            - No arguments (nullary)
        - in #include <algorithm>

    std::generate_n(start_itr, n, nullary_callback)
        - Uses operator=
        - Overwrites elements in range with values from callback n number of times
        - Return type is void
        - Expected parameters
            - An iterator marking the start of a range
            - An integer number of times to call callback
            - A nullary callback
        - Expects nullary callback
            - Containers element type return type
            - No arguments (nullary)
        - in #include <algorithm>    

/ ------------------------------------------------ */