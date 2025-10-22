#include <cstdlib>

class Classic{
    public:
        // Static function for accessing static pointer member
        static Classic* instance() {
            // Lazy instatiation done through checking if onlyInstance_ is nullptr or not
            if(onlyInstance_ == nullptr) {
                onlyInstance_ = new Classic;
            }
            return onlyInstance_;
        }

        /*
        
        Functions to access and alter payload here

        */

        // Prevent all copying from happening
        // If you need these for controlled internal operation of singleton make them private
        Classic(const Classic&) = delete;
        Classic& operator=(const Classic&) = delete;
        Classic(const Classic&&) = delete;
        Classic& operator=(const Classic&&) = delete;        
    
    private:
        // Private Constructor
        Classic();

        // Private Destructor, so client cant brick singleton, singleton controls its own lifetime
        ~Classic() {
            // Get rid of dynamically allocated payload variables
        }

        // Static void function to be registered in atexit
        static void cleanUp(); // cleanUp for atexit()        

        // Private static Singleton* to hold dynamically allocated instance
        static Classic* onlyInstance_;

        /*
        
        Payload here, that would be intialized with constructor
        
        */
};

// Constructor will intiate payload and register cleanUp in atexit
Classic::Classic() {
    atexit(cleanUp);
}

// cleanUp definition, cleanUp deallocates static pointers memory
void Classic::cleanUp() {
    delete onlyInstance_;
    onlyInstance_ = nullptr;
}

// Static variable must be intiated outside of class
Classic* Classic::onlyInstance_ = nullptr;

// |------------------------------------------------------------------------------------|

class Meyers {
    public:
        // static getInstance that belows to all objects of Meyers. 
        // Only time constructor is called is to make static Meyers belonging to
        // all invocations of getInstance(). Enforing only one object of class.
        static Meyers* getInstance() {
            // Lazy instatiation done through static feature
            static Meyers onlyInstance;
            return &onlyInstance;
        }

        /*
        
        Functions to access and alter payload here

        */

        // Prevent all copying from happening
        // If you need these for controlled internal operation of singleton make them private
        Meyers(const Meyers&) = delete;
        Meyers& operator=(const Meyers&) = delete;
        Meyers(const Meyers&&) = delete;
        Meyers& operator=(const Meyers&&) = delete;
    
    private:
        // Private Constructor
        Meyers() { 
            // For initializing payload in Meyers, called on getInstance first call
        }

        // Private Destructor, so client cant brick singleton, singleton controls its own lifetime
        ~Meyers() {
            // Get rid of dynamically allocated payload variables
        }

        /*
        
        Payload here, that would be intialized with constructor
        
        */        
};