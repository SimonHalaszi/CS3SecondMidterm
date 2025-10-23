/* ------------------------------------------------ /

DESIGN PATTERNS

* template method
    - motivation (why use the pattern)
    - virtual function implementation and use
    - override and final
    - pure virtual functions and abstract classes
    - virtual destructors
    - constructor delegation
    - primitive vs. hook operations
    - template method function

Notes from Slides:

    Access Methods

        inherit by:     public    protected   private
        in base class          in derived class
        
        public:         public    protected   inaccessible
        protected:      protected protected   inaccessible
        private:        private   private     inaccessible

        protected access is like an "inside joke" between a
        base class and its derived class. Inaccessible to everything
        else, accessible to the both of them.

        inheriting by private will make all inherited members of parent class
        private in the child class. (Client cant reach base operation)

        inheriting by public makes the access modifiers a one to one
        relationship in terms of access specifiers (Client can reach base operations if they were public)

        inheriting by protected will make all inherited members of parent class
        protected in child class. (Client cant reach base operation)

    Overloading vs. Overriding

        function overloading - using the same function name with different
        signatures in the same scope, compiler will resolve

        function overriding - replacing base-class functions with derived
        class functions, signatures and names match, resolution is done at
        run-time.
            - Done with virtual functions

    Virtual Functions

        What if necessary to manipulate objects regardless of specifics
        of derived class?
            - For example shapes need drawn regardless of what type of shape
        
        Can be done through pointers to objects, through polymorphism
            Figure* fig1 = new Square(3);
            Figure* fig2 = new Triangle(4);;
            fig1->draw();
            fig2->draw();

        Which function (base or derived class) is invoked? Depends...

        Early (compile-time) binding - resolved during compile
            Figure::draw() would be invoked
        
        Late (run-time) binding - resolving function by program itself
        on the basis of object class pointed-to
            Square::draw() and Triangle::draw() would be invoked
        
        To enable late binding, declare the base class function as virtual
            virtual void draw();
            - The technique of doing this is called *polymorphism*
        
        Virtual function may be a destructor but not a constructor

    override and final (C++11)

        Function overriding a virtual remains virtual: May be further overriden
        in latter derived classes.
            do not need to specify virtual in overriding functions is not necessary
        
        override specifier following function head signifies that this function
        must override a virtual base class function, if not, compile time error

        final specifier following a function head signifies that derived classes
        must not and will not override this function further, if not, compile
        time error. Effectively saying virtual function is no longer virtual.

            class Shape {
                virtual void draw() = 0; // Pure virtual (abstract) function
                void redraw();
            };

            class Square : public Shape {
                void draw() override final; // Can do
                void redraw() override; // Cant override non virtual function
                void something() override; // No virtual function to override
            };

            class Side : public Square {
                void draw() override; // Cant do it was finalized in Square
            };

    Abstract Functions

        abstract function (method/operation) - defines only signature but not 
        implementation of virtual function
            - Pure virtual function - virtual function, prototype followed by = 0
            - To be implemented in future derived class
            - Must be public / protected
        
        Concrete operation (method/function) - function whose implementation is
        provided, can be virtual but doesnt have to be.

        abstract class - class that has at least one abstract function
            - Instance of this class wont exist only pointers and references
            to derived classes
        
        concrete class - has no abstract functions
            - If derived from abstract class, has to implement all abstract functions
                - if not, remains abstract

    Virtual Destructors

        Destructors are executed in reverse order of constructors (derived first)

        Always declare destructors as virtual or destructors are bound at compile-time
        and derived destructor may not be executed leaking memory

        default base abstract class destructor idiom
            virtual ~Figure() {}

    Constructor Delegation

        C++11 feature, one constructor may invoke another in initialization list,
        avoids code duplication or having to use default parameters in same cases

        Class Shape {
            public: 
                Shape() : Shape(1) {} // Delegates to Shape(int) constructor
                Shape(int size) : size_(size) {}
            private:
                int size_;
        };

    Template Method Pattern

        Specify an abstract class that outlines expected functionality
        of all derivees

        Primitive operations - functions to be implemented (overriden) in
        concrete classes. A pure virtual function (abstract function)

        Hook operations - *may* be overridden by concrete classes, provide
        default behavior. A virtual function that isnt pure. A virtual concrete method.

        template method - Conrete method of base class that uses primitive operations
        (in effect, concrete implmentations) to accomplish a certain task.

            - Motivation: To have a universal functionality via a concrete method in the base
            class that uses abstract methods to provide similar but overriden behavior
            when using base classes via polymorphism.

            EX: Is the getProduct method of an abstract factory

        is a behavioral pattern - deals with class behavior
        
        Template method is used to design frameworks - the base class invokes
        subclass methods

/ ------------------------------------------------ */
