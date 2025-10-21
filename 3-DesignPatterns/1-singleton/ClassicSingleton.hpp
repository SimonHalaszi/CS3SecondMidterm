#ifndef CLS_SINTON_HPP_
#define CLS_SINTON_HPP_

#include <cstdlib>
#include <iostream>

class ClassicSingleton {
    public:
        // Static method for getting static instance w/ lazy instantiation
        static ClassicSingleton* getInstance() {
            if(!onlyInstance_) {
                onlyInstance_ = new ClassicSingleton;
            }
            return onlyInstance_;
        }

        // Getters
        int getI() const { return i; }
        char getC() const { return c; }

        // Setters
        void setI(const int& _i) { i = _i; }
        void setC(const char& _c) { c = _c; }

        // Deleted copy and move, assignment and construction
        ClassicSingleton& operator=(const ClassicSingleton&) = delete;
        ClassicSingleton(const ClassicSingleton&) = delete;
        ClassicSingleton& operator=(const ClassicSingleton&&) = delete;
        ClassicSingleton(const ClassicSingleton&&) = delete;

    private:
        // Private constructor
        ClassicSingleton() : i(0), c('0') {
            // Print for educational value
            std::cout << "First call of ClassicSingleton getInstance() happended" << std::endl;
            std::atexit(cleanUp);
        }
        
        // Static instance
        static ClassicSingleton* onlyInstance_;

        // Destructor must be made private
        ~ClassicSingleton() {}
        
        // atexit expects function signature (static void (*)())
        static void cleanUp() {
            delete onlyInstance_;
            onlyInstance_ = nullptr;
        }

        // Payload, not static
        int i;
        char c;
};  

// Static member variables must be declared outside of class
ClassicSingleton* ClassicSingleton::onlyInstance_ = nullptr;

#endif