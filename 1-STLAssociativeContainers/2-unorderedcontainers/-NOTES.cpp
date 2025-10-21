/* ------------------------------------------------ /

STL ASSOCIATIVE CONTAINERS

* unordered containers

Notes from slide:

    Unordered Containers

    - unordered map - needs <unordered_map> and using std::unordered_map
        - same interface as map
            - no lower_bound() or upper_bound() - container is not ordered
            so these bounds dont make sense
        
        - plus: transparent memory implementation
            - bucket_count() - returns number of buckets in hash table
            
            - load_factor() - same as size()/bucket_count() 
                - returns a 0-1 decimal of how full the hash table is.
            
            - max_load_factor() - returns or sets maximum load factor before
            bucket count increase (1 by default)
                - so when load_factor() reaches 1 the hash table array will
                be expanded and rehashed
                - max_load_factor(0.n) - sets the maximum load
                - max_load_factor() - gets the value
            
            - bucket(key) - gets bucket index for bucket that contains
            elements with that key

            - begin(bucket_index), end(bucket_index) - returns local_iterator for 
            the chain of elements in a bucket
                - a local_iterator is an iterator that iterates through
                the inside of a hash table bucket

            - equal_range(key) - still exist for getting a pair of iterators
            to the range of elements with that key

    - unordered set - needs <unordered_set> and using std::unordered_set
        - same interface as set and above bucket functions

    - unordered multimap and multiset also exist with expected interfaces

/ ------------------------------------------------ */