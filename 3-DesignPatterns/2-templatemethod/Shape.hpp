#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <iostream>

// Template Method Pattern, abstract class
class Shape {
    public:
        Shape() : Shape(1, 1, 'w') {}   // Constructor delegation to Shape(int)
        Shape(int height, int width, char color) : height_(height), width_(width), color_(color) {}

        int getSize() const { return height_; } // Concrete method
        
        // Providing a definition to a non final virtual method makes it a hook
        virtual void sayName() const { std::cout << "Shape"; } // Virtual function

        // Providing no definition to a virtual method makes it a primitive
        virtual void draw() const = 0; // Pure virtual
        virtual double area() const = 0; // Pure virtual

        virtual ~Shape() {}

        // The template method is a function of the base class that uses primitives, to accomplish a task
        void renderToConsole() {    // This is the Template Method as referred to by the design pattern
            sayName(); std::cout << std::endl;
            draw();
            std::cout << area() << std::endl;
            std::cout << std::endl;
        }

    protected:
        int height_;
        int width_;
        char color_;
};

class Rectangle : public Shape {
    public:
        Rectangle() : Shape(1, 1, 'w') {}   // Constructor delegation to Rectangle(int)
        Rectangle(int height, int width, char color) : Shape(height, width, color) {}

        // Square does not have same name so not final
        void sayName() const override { std::cout << "Rectangle"; }

        // Square can use same logic so this is final
        void draw() const override final {           
            for(int i = 0; i < height_; ++i) {
                for(int i = 0; i < width_; ++i) {
                    std::cout << color_ << "  ";
                }
                std::cout << std::endl;
            }
        }

        // Square can use same logic so this is final
        double area() const override final {
            return height_ * width_;
        }

        ~Rectangle() override {}
};

class Square : public Rectangle {
    public:
        Square() : Rectangle(1, 1, 'w') {}   // Constructor delegation to Rectangle(int)
        Square(int height, char color) : Rectangle(height, height, color), p_(new int[1000]) {}

        // No further shape derived from square so this is final
        void sayName() const override final { std::cout << "Square"; }

        ~Square() override { delete [] p_; }
    private:
        int* p_;    // Only exist to hold garbage to show off destructor
};

#endif