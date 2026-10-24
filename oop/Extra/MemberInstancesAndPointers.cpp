#include <iostream>
using namespace std;
class Engine {
public:
    void start() { cout << "Vroom!\n"; }
};

// 1. Member Instance (Recommended)
class CarInstance {
    Engine e; // Managed automatically
public:
    void drive() { e.start(); }
};

// 2. Member Pointer (Requires manual control)
class CarPointer {
    Engine* e;
public:
    CarPointer() { e = new Engine(); }  // Manual allocation
    ~CarPointer() { delete e; }        // Manual cleanup
    void drive() { e->start(); }
};

int main() {
    CarInstance c1;
    c1.drive();

    CarPointer c2;
    c2.drive();
}