#ifndef BABIES_HPP_
#define BABIES_HPP_

#include <string>
#include <cstdlib>
#include <deque>

// abstract product
class Baby {
    public:
        int getBday() const { return bday_; }
        char getGender() const { return gender_; }
        std::string getName() const { return name_; }
    protected:
        int bday_;
        char gender_;
        std::string name_;
};

// boy concrete product
class Boy : public Baby {
    public:
        Boy();
};

// boy constructor
Boy::Boy() {
    bday_ = rand() % 365 + 1;
    gender_ = 'm';
    static std::deque<std::string> names = {"Simon", "Chuck", "Wesley", "Preston", "Jacob"};
    name_ = names[rand() % names.size()];
}

// girl concrete product
class Girl : public Baby {
    public:
        Girl();
};

// girl constructor
Girl::Girl() {
    bday_ = rand() % 365 + 1;
    gender_ = 'f';
    static std::deque<std::string> names = {"Simone", "Chelsea", "Willow", "Paige", "Jill"};
    name_ = names[rand() % names.size()];
}

// abstract factory
class BabyFactory {
    public:
        BabyFactory(std::string location, int babyCount) 
        : location_(location), babyCount_(babyCount) {}

        virtual BabyFactory* getFactory() = 0; // in UML diagram. Only really useful if factories are singletons
        /*
            Useful for if factories were singleton, then you could do
            ConcreteFactory::getFactory()->makeProduct() would get and use
            the same factory instance everytime for object creation. Currently
            we do not use singletons so this function is quite redundant. Since
            instances are currently made on demand or accessed through some container
            holding them. Meaning we already have direct access to the instance through
            a BabyFactory* anyway.
        */

        Baby* getBaby();    // a template method
        int getBabyCount() const { return babyCount_; }
        std::string getLocation() const { return location_; }

        virtual ~BabyFactory() {}

    protected:
        virtual Baby* makeBaby() = 0; // abstract factory method

    private:
        std::string location_;
        int babyCount_;
};

Baby* BabyFactory::getBaby() {
    ++babyCount_;
    return makeBaby();
}

// boy concrete factory
class BoyFactory : public BabyFactory {
    public:
        BoyFactory(std::string location, int babyCount) 
        : BabyFactory(location, babyCount) {}

        BabyFactory* getFactory() override { return this; }

        ~BoyFactory() override {}
    protected:
        Baby* makeBaby() override final; // concrete factory method
};

// concrete factory method
Baby* BoyFactory::makeBaby() {
    return new Boy();
}

// girl concrete factory
class GirlFactory : public BabyFactory {
    public:
        GirlFactory(std::string location, int babyCount) 
        : BabyFactory(location, babyCount) {}

        BabyFactory* getFactory() override { return this; }

        ~GirlFactory() override {}
    protected:
        Baby* makeBaby() override final; // concrete factory method
};

// concrete factory method
Baby* GirlFactory::makeBaby() {
    return new Girl();
}

#endif