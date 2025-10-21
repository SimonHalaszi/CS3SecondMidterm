/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* functors

Notes from slides:

    Function Objects (Functors)
        
        - functor - object that may be invoked as a standalone function
        
        - done by overloading function call operator: operator() for a class, 
        may have any number of arguments and return any value

        class Functor {
            public:
                Functor(int x = 0) : x_(x) {}
                int operator()(int y = 0) { return x_ + y; }
            private:
                int x_;
        };

        - then invoke like a standalone function
            Functor obj(2);
            obj(3); // returns 5

        - may also call like this
            Functor()(2); // returns 2
            or...
            Functor()() // returns 0
        
        - may keep state between calls
            - use this with caution for algorithms as implementations of
            algorithms are free copy/invoke out of order/invoke concurrently
        
        - lambdas provide a convenient alternative

/ ------------------------------------------------ */