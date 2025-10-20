/* ------------------------------------------------ /

STL ALGORITHMS

ENHANCED ITERATOR FUNCTIONS

* back inserter and front inserter

Notes from slides:

    Iterator Adapters: Insert

        - Insert iterators - special type of output iterators
        designed for algorithms (such as copy_if or transform) to
        insert rather than overwrite elements in the target range.
        Therefore we do not need to be aware of the target range
        size to ensure safe operation.

            -insert_iterator() - calls insert(position, element)
                - Typical insert like insert(position, element) on
                container, returns iterator to next position
                - Inserter is initialized with container, position
                - inserter(container, position) returns insert_iterator
                on this position
                - Useful for associative containers whose keys are
                usually not modifiable on iteration
                - insert_iterator will update is own position no need
                for reassignment of it. Keeps itself valid
            - back_insert_iterator() - calls push_back() on container
                - back_inserter(container) returns back_insert_iterator
                for this container
            - front_insert_iterator() - calls push_front()
                - Container must have underlying push_front so 
                no front inserter for say vector
        - Elements are inserted sequentially, may be ineffcient
        - Increment/Decrement have no effect on inserters

/ ------------------------------------------------ */