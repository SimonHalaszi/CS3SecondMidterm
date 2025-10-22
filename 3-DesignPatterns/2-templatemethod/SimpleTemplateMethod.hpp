#ifndef SIMPLE_TEMPLATE_METHOD_HPP_
#define SIMPLE_TEMPLATE_METHOD_HPP_

// A abstract base class
class AbstractBase {
    public:
        // Abstract class intializing its own member variables
        AbstractBase() : AbstractBase(1) {} // Constructor delegation
        AbstractBase(int val) : aVar1_(new int[val]) {}

        // The template method, a concrete function that calls abstract methods
        void TemplateMethod() { // Body uses abstract methods
            // Specifics of algorithm template method does not relevant to this example, this is just random code
            if(aVar1_[0] < 1) {
                AbstractMethod1();
                AbstractMethod2();
            } else {
                AbstractMethod3();
            }
            AbstractMethod1();
        }

        // Virtual destructor idiom, should delete dynamic variables specific to abstract class
        virtual ~AbstractBase() { delete [] aVar1_; }

    protected:
        // Abstract methods (Primitives/Pure Virtuals) used in concrete template method, Should be protected
        virtual void AbstractMethod1() = 0;
        virtual void AbstractMethod2() = 0;
        virtual void AbstractMethod3() = 0;

    private:
        // Members
        int* aVar1_;
};

// A concrete derived class
class ConcreteClass : public AbstractBase {
    public:
        // Concrete class intializing its own member variables
        ConcreteClass() : ConcreteClass(1) {} // Constructor delegation
        ConcreteClass(int val) : aVar2_(new int[val]) {}

        // Override abstract methods for per ConcreteClass functionality
        void AbstractMethod1() override {
            // something
        }
        void AbstractMethod2() override {
            // something
        }
        void AbstractMethod3() override {
            // something
        }

        // Overridden destructor that manages dynamically variables specific to ConcreteClass
        ~ConcreteClass() override { delete [] aVar2_; }
    
    private:
        // Members
        int* aVar2_;

    // ConcreteClass inherits aVar1_ but cant not access it directly, must be done through some
    // operation in AbstractBase
};

#endif