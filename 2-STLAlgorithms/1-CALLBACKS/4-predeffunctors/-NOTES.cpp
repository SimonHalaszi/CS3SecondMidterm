/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* predefined functors
    - arithmetic, comparison, logical

Notes from slides:

    Predefined Functors, Arithmetic
        
        - STL provides a number of predefined functors
        
        - defined in <functional>
        
        - in std namespace (need to be imported or scope resolved)
        
        - have to be instantiated with type
            - plus<int> myPlus; myPlus(3, 4); // 7
        
        - may be used in algorithms as callbacks
            - int sum = accumulate(v.begin(), v.end(), 0, plus<int>());
        
        - regular operators cannot be used as callbacks, functors
        are adapters that wrap around regular arithmetic operators
        
        - transparent functors (C++14): angle brackets are empty,
        type is deduced - this variant is preffered

    -- arithmetic, comparison, logical --

        - arithmetic functors:
            - plus, minus, multiplies, divides, modulus
        
        - comparison functors:
            - equal_to, not_equal_to, less, greater, less_equal, greater_equal
                - less is used as default comparison in priority_queue container
                adapter
                
                - this can be changed, although you will have to specify container
                
                - EX:
                    priority_queue<string>, vector<string>, greater<>> rpq;
                    // dont need to make instance of greater because this isnt
                    // an using it, just declaring that type as being used.
        
        - logical functors: 
            - logical_and, logical_or, logical_not

            - EX:
                bool allTrue = accumulate(v.begin(), v.end(), true, logical_and<>());

/ ------------------------------------------------ */