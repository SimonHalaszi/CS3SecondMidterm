/* ------------------------------------------------ /

DESIGN PATTERNS

* abstract factory - motivation
  - abstract vs. concrete objects
  - factory and factory method
  - abstract vs. concrete factory, abstract vs. concrete method

Notes from Slides:

    Abstract vs. Concrete Objects

        A number of design patterns use abstract and concrete classes
            - abstract class - provides a list of abstract functions
            to be implemented and used by the pattern
            
            - concrete class - provides implementation for the abstract
            functions, does not have any abstract methods
        
        Abstract class pointers may point to concrete objects and the
        abstract functions are overriden by concrete implementations
            - clients may not be concerned with implementations
            - various concrete objects may be assembled into a single container
            and operated uniformly (polymorphism)
                - virtual function would provide customized functionality per
                object

    Factory and Factory Methods

        factory - an object for creating other objects called products
            - important when control over object creation is necessary: e.g.
            instead of just creating an object, factory may dynamically allocate
            it from an object pool, do complex configurations.
            - contains methods for object creation

        factory method (design pattern) - implements the actual object creation
            - usually returns a pointer to created object
            - specifies interface to be implemented (overrideen) by subclasses,
            hence known as virtual constructor
                - why not regular constructor? It cant be overridden
                - overriden interface is the concrete factory method
                - class with this concrete factory method is concrete factory
            - example of a creational pattern, like Singleton
        
        singleton is an example of factory, why?
            - It hides its creation behind an interface, and also handles
            the creation of an object (itself)

    Abstract Factory

        regular factory encodes product class names. May be inconvenient
            - in case need to make modification
            - in case need to re-use for several related factories
        
        *abstract factory design pattern* - seperates interface and implementation
            - abstract factory - specifies creation interface
            - abstract product - specifies product interface to be manipulated by
            abstract factory
            - abstract factory method - product creation interface
            - concrete factory, product, method - implementations of respective
            interfaces
        
        benefit of abstract factory pattern - client may not need to know
        (concrete) implementations to operate objects

        abstract factory is creational pattern

        abstract factory is often designed as a singleton pattern
            - Because lazy instatiation is very convenient for quickly getting
            a product from a concrete factory from the abstract factory pointer.
            Without having to deal with deleting the concrete factory ever due to
            dynamic allocation or what have you.

        a factory may be part abstract/part concrete

In my own words:

    The abstract factory defines an interface for creating an abstract product.
    The abstract product class defines a list of attributes all the concrete products
    will share. The derived concrete products implement a constructor that initializes
    the values of these attributes. The abstract factory defines a abstract factory
    method that returns a pointer of the type of the abstract product class. The derived 
    concrete factories, for which there is one for each derived concrete product. Will
    provide a concrete factory method. Which involves dynamically allocating the 
    respective concrete product and returning it through the abstract product pointer.
    This abstract factory method is called in a template method inside of the abstract
    factory which calls the abstract factory method and returns the value. This interface
    allows for seemless creation of many types of objects through one pointer. Thats
    polymorphism.

/ ------------------------------------------------ */