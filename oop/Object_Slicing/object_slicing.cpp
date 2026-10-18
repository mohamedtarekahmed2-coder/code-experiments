#include <iostream>
using namespace std;

// ==========================================
// Part 1: Object Slicing Demonstration
// ==========================================

class Base {
protected:
    int i;
public:
    Base(int a) : i(a) {}
    virtual void display() {
        cout << "Base object, i = " << i << endl;
    }
};

class Derived : public Base {
    int j;
public:
    Derived(int a, int b) : Base(a), j(b) {}
    virtual void display() {
        cout << "Derived object, i = " << i << ", j = " << j << endl;
    }
};

// Pass Base object by reference
void somefunc(Base& obj) {
    obj.display();
}

void mainTwo() {
// --- Part 1 Execution ---
    Base b(33);
    Base d = Derived(45, 54);

    b.display();
    d.display();

    somefunc(b);
    somefunc(d);

    Base *ptr = new Derived(45, 54);
    ptr->display();
    delete ptr;
}

// ==========================================
// Part 2: Downcasting & dynamic_cast
// ==========================================

class Parent
{
public:
    virtual void show()
    { // runtime polymorphism
        cout << "Parent::show()\n";
    }
};

class Child : public Parent
{
public:
    void show() override
    { // overrides Parent::show()
        cout << "Child::show()\n";
    }
    void childOnly()
    {
        cout << "Child::childOnly()\n";
    }
};

int main()
{
    // --- Part 1 Execution ---
    mainTwo();

    cout << "--------------------------------------------\n";
    // --- Part 2 Execution ---
    Parent *p = new Child();
    p->show(); // Calls Child::show (virtual)

    // p->childOnly(); // Error: 'childOnly' is not a member of Parent

    // --- Safe way (dynamic_cast) ---
    Child *c1 = dynamic_cast<Child *>(p);
    c1->childOnly(); // Safe execution

    // --- Unsafe way (C-style cast) ---
    Child *c2 = (Child *)p; // No runtime check!
    c2->childOnly();        // May crash if 'p' is not actually pointing to a Child

    delete p;
    return 0;
}