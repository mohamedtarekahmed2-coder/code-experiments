#include <iostream>
using namespace std;
#define nl cout << '\n'
class Base
{
public:
    void normalFunction() // Static Binding
    {
        cout << "Base Normal Function\n";
    }
    virtual void virtualFunction() // Dynamic Binding
    {
        cout << "Base Virtual Function\n";
    }
};

class Derived : public Base
{
public:
    void normalFunction()
    {
        cout << "Derived Normal Function\n";
    }
    virtual void virtualFunction()
    {
        cout << "Derived Virtual Function\n";
    }
};

int main()
{
    Base *ptr;
    Derived obj;
    ptr = &obj;
    ptr->normalFunction();
    ptr->virtualFunction();
    // output:
    // Base Normal Function
    // Derived Virtual Function
    return 0;
}