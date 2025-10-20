/* ------------------------------------------------ /

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* reverse iterators

Notes from slides:

    Iterator Adapters: Reverse

        - Declared in #include <iterator>
        - std::contaier<element_type::reverse_iterator - iterates
        in reverse order, increment advanced backward
            - rbegin() - returns reverse iterator starting at the 
            last element of container
            - rend() - returns iterator before the first element
            - base() - returns underlying iterator iterator plus 
            one - useful to determine distance to beginning

        - crbegin() and crend() also exist for const_reverse_iterator

/ ------------------------------------------------ */