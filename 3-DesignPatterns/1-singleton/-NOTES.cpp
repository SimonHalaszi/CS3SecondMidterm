/* ------------------------------------------------ /

DESIGN PATTERNS

* singleton
    - motivation (why use the pattern)
    - static features
    - atexit()
    - forbidding object copying: delete vs. making private
    - idioms vs. design patterns vs. frameworks
    - singleton meyers vs. classic implementation

Notes from slides:

    Static Features

        - Static features are allocated per class rather than per object
        - Static features are shared between objects of the same class
        - Static variables
            - Only declared in-class, have to intialized elsewhere 
            (pre-C++11)

        class Student {
            public:
                Student();
                int number() const;
                static int getCurrent() { return currentNumber_; }
            private:
                int number_;
                static int currentNumber_; // Declaration
        };

        - Static methods may access only static member variables
        - Static methods are invoked with scope resolution:
            Student::getCurrent();
        
    Specifying Behavior at Program Shutdown

        - If needed to execute code once program terminates
            - EX: prevent resource leaks
        - Standalone function atexit()
            - declared in #include <cstdlib>
            - signature: int atexit (void (*func)());
                - The invoked function returns void and does not take
                parameters
                - Returns zero if successful, nonzero otherwise
                - Expects a void nullary callback
            - EX:
                atexit(cleanup);
                void cleanup() { delete somePointer; }

    Forbidding Object Copying

        - Why?
            - To ensure a single instance
            - To prevent wasting of resources (when copying)
        - How? - Make copy constructor and overloaded assignment
        non-public (private or protected) or deleted
            - If non-public can still be invoked by other member
            functions
            - Effect: compile-time error on attempt to use outside
            of member functions
        - EX:

        class Student {
            public:
                Student(long);
            private:
                Student(const Student&)(); // Private empty copy constructor
                Student& operator=(const Student&); // Private empty assignment
                long number_;
        };

        - To forbid all instantiations - make all constructors private
        - C++11 variant - delete
            Student(const Student&) = delete;
            - Method does not exist in any form and cant be invoked at all

    Idioms vs Patterns vs Frameworks

        - All techniques of solving commonly occuring tasks

        - idiom - low-level language specific technique
        - (design) patterns - mid-level, contains: name, problem,
        solution, consequences (benefits/side-effects, etc), language
        independent
        - framework - abstract, high-level, uses serveral desgin
        patterns, leaves client (programmers) to provide code to
        specify behavior

    Design Pattern Categories

        - creational - create objects for the client
        - behavioral - abstract the object behavior (code),
        concerned with communication between objects
        - structural - concerned with class and object composition;
        uses inheritance to compose interfaces and define ways to
        compose objects to obtain new functionality

    Singleton Design Pattern

        - Ensures that there is a single instance of a class
        in a given program
            - Must have global access: more than a single
            function/method should be able to manipulate
            singleton
            - Instantiation
                - Id it does not exist, should create on
                first invocation (lazy instantiation)
                - If it does exist, should return a reference
                or pointer to the instance
            - Destruction
                - Should deallocate resource on program
                termination
            - Multithreading (not considered) - Needs to be
            thread-safe
        - A creational pattern - it deals with object creation
        - Payload - useful, manipulatable content of the Singleton
        - Two implementations approaches
            - Meyer's Singleton
            - Classic Singleton

    Meyer's Singleton

        - instance() may return a reference or a pointer
        - Lazy instantiation acheived through local static variable
        that is allocated at first invocation
        - Automatically deallocated with all global variables

        class Singleton {
            public:
                static Singleton& instance() {
                    static Singleton s;
                    return s;
                }
            private:
                // copying, construction, and assignment prohibited
                Singleton() {}
                Singleton(const Singleton&) {}
                Singleton& operator=(const Singleton&) {}
        };

    Classic Singleton

        - Private static attribute pointer - points to dynamically
        allocated instance
            - if zero/null_ptr unallocated
        - instance() static method returns pointer to instance, lazy
        instantiation allocate when first accessed
            - Object accessed through instance()
                - EX:
                Singleton::instance()->public_method();
        - Prohibit creation and copying - all constructors and
        assignment are private or deleted (C++11)
        - To ensure proper destruction - use atexit()

        class Singleton{
            public:
                static Singleton* instance() {
                    if(onlyInstance_ == nullptr) {
                        onlyInstance_ = new Singleton;
                    }
                    return onlyInstance_;
                }

                // copying prohibited
                Singleton(const Singleton&) = delete;
                Singleton& operator=(const Singleton&) = delete
            private:
                Singleton(){} // constructor hidden
                static Singleton* onlyInstance_;
                static void cleanUp(); // cleanUp for atexit()
        };

        void Singleton::cleanUp() {
            delete onlyInstance;
            onlyInstance = nullptr;
        }

        Singleton::Singleton() {
            atexit(cleanUp);
        }

        Singleton* Singleton::onlyInstance_ = nullptr;

    Why Classic Singleton is the Way It Is

        - Why can't we just use static member functions/variables?
            - Its a possibility; however, if object is seldom used
            or is large its better to use dynamic allocation
        - Why care about destroying singleton? There does not seem to
        be a memory leak?
            - No there does not: since with singleton there is not
            continous allocation and losing references, modern Operating
            Systems make sure process memory is deallocated upon completion
            - However, singleton may hold resources that need to be released
            at end of program - OS-dependent mutexes, sockets, inter-process
            shared memory, etc. Better to destroy
                - If not, relying on OS-based cleanup may be best

        - Why need atexit()? Can't we use destructors?
            - In our design destructor is never invoked
            - Careful with atexit(): even though it is in standard,
            not all compilers implement it correctly


/ ------------------------------------------------ */