#include <iostream>
using namespace std;
#define nl cout << '\n'
// class Base
// {
// public:
//     void normalFunction() // Static Binding
//     {
//         cout << "Base Normal Function\n";
//     }
//     virtual void virtualFunction() // Dynamic Binding
//     {
//         cout << "Base Virtual Function\n";
//     }
// };

// class Derived : public Base
// {
// public:
//     void normalFunction()
//     {
//         cout << "Derived Normal Function\n";
//     }
//     virtual void virtualFunction()
//     {
//         cout << "Derived Virtual Function\n";
//     }
// };
// Base *ptr;
// Derived obj;
// ptr = &obj;
// ptr->normalFunction();
// ptr->virtualFunction();
// output:
// Base Normal Function
// Derived Virtual Function

// Abstract Base Class
class Shape {
private:
    string name;
public:
    Shape(const string& shapeName = "") : name(shapeName) {}
    // Virtual Destructor
    virtual ~Shape() {}
    // Pure Virtual Function (Abstract Method)
    virtual double area() const = 0; 
    // Operator Overloading & Helper Functions
    virtual void print() const { cout << name << " of area " << area() << endl; }
};

// Derived Class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const string& name, double r) : Shape(name), radius(r) {}
    // Override Pure Virtual Function
    double area() const override { return 3.14159 * radius * radius; }
};

int main() {
    Shape* a = new Circle("circle", 3); // Legal
    a->print();
    // Shape* b = new Shape("circle"); // Illegal! (Cannot instantiate Abstract Class)
    delete a;
    return 0;
}