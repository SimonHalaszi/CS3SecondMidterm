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

            - In #include <iterator>
            
            - declared as such
                std::kind_insert_iterator<container<element_type>> id;

            -insert_iterator() - calls insert(position, element)
                                 For associative container calls hint insert, insert(iterator, element)
                - Typical insert like insert(iterator, element) on
                container, returns iterator to next position, and inserts
                before iterator
                - Inserter is initialized with container, position
                - inserter(iterator, position) returns insert_iterator
                on this position
                - Inserter inserts before underlying position given to it
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
        - Increment/Decrement/Dereferncing have no effect on inserters

Notes from me:

    Algorithms we study where inserters are very useful

    Elements created during these algrothims will be inserted at insert iterator (inserter)

    All return the same type of inserter that was given in
        - Call with insert_iterator will return insert_iterator that will insert past last element inserted
        - Call with back_insert_iterator or front_insert_iterator will return the respective inserter

        - But inserters keep themselves valid so re-assigning the inserter to the function call is not
        necessary/as useful as getting the return value of the normal iterator call or normal container inserts
    
    - Modifying (If two sources, expects source2 to be of same or greater size as source1)
        inserter = std::transform(source_start_itr, source_end_itr, inserter, unary_callback)
        inserter = std::transform(source1_start_itr, source1_end_itr, source2_start_itr, inserter, binary_callback)
        inserter = std::copy(source_start_itr, source_end_itr, inserter)
        inserter = std::copy_if(source_start_itr, source_end_itr, inserter, unary_predicate)
        inserter = std::remove_copy(source_start_itr, source_end_itr, inserter, value_to_ignore)
        inserter = std::remove_copy_if(source_start_itr, source_end_itr, inserter, unary_predicate) // Where true for predicate will ignore
        inserter = std::move(source_start_itr, source_end_itr, inserter) // Will use move semantics
        inserter = std::generate_n(inserter, n, nullary_callback)
        
    - Sorting (Expect sorted container)
        inserter = std::merge(source1_start_itr, source1_end_itr, source2_start_itr, source2_end_itr, inserter)
        
    - Set (Expect sorted container with unique elements)
        inserter = std::set_union(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, inserter)
        inserter = std::set_intersection(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, inserter)
        inserter = std::set_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, inserter)
        inserter = std::set_symmetric_difference(set1_start_itr, set1_end_itr, set2_start_itr, set2_end_itr, inserter)  

/ ------------------------------------------------ */