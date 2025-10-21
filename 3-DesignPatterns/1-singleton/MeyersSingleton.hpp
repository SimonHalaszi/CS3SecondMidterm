#ifndef MEYERS_SINTON_HPP_
#define MEYERS_SINTON_HPP_

#include <iostream>

class MeyersSingleton {
    public:
        // Static method for getting static instance belonging to function w/ lazy instantiation
        static MeyersSingleton* getInstance() {
            static MeyersSingleton onlyInstance;
            return &onlyInstance;
        }

        // Getters
        int getI() const { return i; }
        char getC() const { return c; }

        // Setters
        void setI(const int& _i) { i = _i; }
        void setC(const char& _c) { c = _c; }

        // Deleted copy and move, assignment and construction
        MeyersSingleton& operator=(const MeyersSingleton&) = delete;
        MeyersSingleton(const MeyersSingleton&) = delete;
        MeyersSingleton& operator=(const MeyersSingleton&&) = delete;
        MeyersSingleton(const MeyersSingleton&&) = delete;
    private:
        // Private constructor
        MeyersSingleton() : i(0), c('0') {
            // Print for educational value
            std::cout << "First call of MeyersSingleton getInstance() happended" << std::endl;
        }
        
        // Payload, not static
        int i;
        char c;
};  

#endif