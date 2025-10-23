/* ------------------------------------------------ /

STL ALGORITHMS

CALLBACKS

* lambda expressions
    - capture block, context, capture variables

Notes from slide:

    Lambda Expressions

        - anonymous function
        
        - defined in C++11
        
        - syntax:
            [capture_block](parameters)-> return_type { body; };
    
        - capture - passing discipline and (optionally) name of variables
        taken form outside of scope (called context) of the lambda expressions
            - [] no variables defined. Attempting to use any external variables
            in the lambda body is an error.
            
            - [x, &y] x is captured by value, y is captured by reference.
            
            - [&] any external variable is implicitly captured by reference.
            
            - [=] any external variable is implicitly captured by value
                - obviously can be very wasteful.
            
            -variables are captured at the time of lambda definition. (not invocation)
        
        - if return_type is omitted and there is a single return statement in body,
        compiler will deduce return_type on basis of the return statement.

        - if no parameters, parentheses are optional.

        - so lambda may look like this
            []{ return 1; };            // Many omissions of the syntax but valid
            []()->int { return 1; };    // Same thing equally as valid

        - can be used as parameters for other functions, have to conform to expected signature.
            - say STL algorithms ;)

        - can be pointed to by function pointers.

        - can call lambda in place using more parenthesis
            [capture_block](parameters)->return_type { body; }(arguments);

/ ------------------------------------------------ */