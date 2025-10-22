/* ------------------------------------------------ /

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* reverse iterators

Notes from slides:

    Iterator Adapters: Reverse

        - Declared in #include <iterator>
        - std::contaier<element_type>::reverse_iterator - iterates
        in reverse order, increment advanced backward
            - rbegin() - returns reverse iterator starting at the 
            last element of container. 
            normal itr = end() - 1
            - rend() - returns iterator before the first element
            normal itr = begin() - 1
            - base() - returns underlying iterator plus 
            one - gets normal iterator version of corresponding
            reverse_iterator. If reverse_iterator is x number of spots
            from c.rend() then the base of that reverse_iterator will
            be x number of spots from c.begin().
            Why? Because then base(c.rend()) will give you the normal
            c.begin() and base(c.rbegin) will give you the normal c.end(),
            useful for swapping between the two and maintaining concistenccy
            in iterator usage

        - crbegin() and crend() also exist for const_reverse_iterator

/ ------------------------------------------------ */