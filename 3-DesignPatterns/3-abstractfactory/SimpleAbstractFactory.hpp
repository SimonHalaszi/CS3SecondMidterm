#ifndef SIMPLE_ABSTRACT_FACTORY_HPP_
#define SIMPLE_ABSTRACT_FACTORY_HPP_

// Abstract product
class AbstractProduct {
    public:
        // No constructor
        int getAttribute() const { return attribute_; }
        virtual void setAttribute(int val) = 0;
    protected:
        // Attributes for all products, should be protected
        int attribute_;
};

// Concrete product
class ConcreteProduct : public AbstractProduct {
    public:
        ConcreteProduct() : ConcreteProduct(1) {} // Constructor Delegation
        // Constructor prototype
        ConcreteProduct(int val);
        // Customized behavior for this product
        void setAttribute(int val) override { attribute_ = val * 2; }
};

// Constructor for product
ConcreteProduct::ConcreteProduct(int val) {
    attribute_ = val;
}

// Abstract factory
class AbstractFactory {
    public:
        // Abstract factory constructors
        AbstractFactory() : AbstractFactory('a', 0) {}
        AbstractFactory(char c, int i) : c_(c), i_(i) {}

        // A very simple example of a template method
        AbstractProduct* getProduct() {
            return makeProduct();
        }

        // virtual destructor idiom
        virtual ~AbstractFactory() {}

    protected:
        // abstract factory method
        virtual AbstractProduct* makeProduct() = 0;

    private:
        // Abstract factory members
        char c_;
        int i_;
};

// Concrete Factory, Concrete Factories may be singletons
// Using Meyers Singleton Here
class ConcreteFactorySingleton : public AbstractFactory {
    public:
        // Concrete Factory, may be singletons
        static AbstractFactory* getFactory() {
            static ConcreteFactorySingleton factory;
            return &factory;
        }

        // Deleted copy and move semantics
        ConcreteFactorySingleton(const ConcreteFactorySingleton&) = delete;
        ConcreteFactorySingleton& operator=(const ConcreteFactorySingleton&) = delete;
        ConcreteFactorySingleton(const ConcreteFactorySingleton&&) = delete;
        ConcreteFactorySingleton& operator=(const ConcreteFactorySingleton&&) = delete;          
    protected:
        // Override of primitive method makeProduct() from base class 
        // concrete factory method
        AbstractProduct* makeProduct() override {
            return new ConcreteProduct();
        }
      
    private:
        // Private constructors, single should manage own lifecycle
        ConcreteFactorySingleton() : ConcreteFactorySingleton('a', 0) {}
        ConcreteFactorySingleton(char c, int i) : AbstractFactory(c, i) {}

        // Private destructor, singleton should manage own lifecycle
        ~ConcreteFactorySingleton() override {}
};

// Concrete Factory, Concrete Factories may not be singletons
class ConcreteFactoryNotS : public AbstractFactory {
    public:
        ConcreteFactoryNotS() : ConcreteFactoryNotS('a', 0) {}
        ConcreteFactoryNotS(char c, int i) : AbstractFactory(c, i) {}   
        
        ~ConcreteFactoryNotS() override {}
      
    protected:
        // Override of primitive method makeProduct() from base class 
        // concrete factory method
        AbstractProduct* makeProduct() override {
            return new ConcreteProduct();
        }
};

/*

With singleton, interface as such:

    ConcreteFactorySingleton::getFactory()->getProduct();

Non singleton interface with polymorphism as so:

    AbstractFactory* factory = new ConcreteFactoryNotS();
    factory->getProduct();
    delete factory; 

    Or more intuitively doing:

    ConcreteFactoryNotS() factory;
    factory.getProduct();

Use singleton if you want all ConcreteFactory to have
the same internal information, and dont want to polymorphism
or to manually create factories. Use non singleton otherwise,
say you need two ConcreteFactories with different internal
information.

*/

#endif