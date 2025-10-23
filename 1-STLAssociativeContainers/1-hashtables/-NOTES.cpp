/* ------------------------------------------------ /

STL ASSOCIATIVE CONTAINERS

* hash tables    

Notes from slide:

    Hash Tables

    - an array of buckets of elements
    
    - hash function translates (hashes) key to bucket index
    
    - collision - hashing different keys to same bucket
        - usually resolved through pointer to linked list of elements
    
    - implements amortized O(1) element lookup/insertion/deletion
        - Insertion amortized because hash array needs rehashed sometimes when 
        array needs to expand
        
        - Lookup amortized to O(1) because in case of collision we must
        do O(N) search through potential linked list of elements in
        bucket

/ ------------------------------------------------ */