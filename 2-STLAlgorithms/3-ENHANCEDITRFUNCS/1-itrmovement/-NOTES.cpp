/* ------------------------------------------------ /

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* iterator movement

Notes from slides:

    Enhanced Iterator Functions

    further enhance the power of algorithms
        - Iterator movement functions - Make iterator operate
        as random access regardless of type of container
        - Reverse iterators - Iterators in reverse direction
        - Inserters - Target range does not have to have same
        size as source range.

    Iterator Movement Functions

    Poor man's iterator arithmetic
    
    Implemented as templates
        - void advance(iterator, n) - move iterator n number of
        elements forward, returns void, inputted iterator will be 
        updated
            - If iterator is random access calls the + operator
            
            - If the iterator is non-random access, move copy of
            iterator by repeatedly calling increment

        - itr = next(iterator, n) - returns an iterator n number of
        elements forward, returns an iterator, inputted iterator
        will not be updated
            - If iterator is random access calls the + operator
            
            - If the iterator is non-random access, move copy of
            iterator by repeatedly calling increment
            
        - itr = prev(iterator, n) - same as next in reverse direction

        - size_t = distance(first_iterator, second_iterator) - returns the
        number of elements between first_iterator and second_iterator.
        If random access, uses subtract, otherwise repeatedly calls 
        increment on first_iterator copy until it equals second_itertor.
        Works if first_iterator is later than second_iterator just 
        returns a negative number

/ ------------------------------------------------ */