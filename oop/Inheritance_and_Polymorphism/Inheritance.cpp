#include <iostream>
using namespace std;

class Base
{
public:
    void print() { cout << "From Base.\n"; }
};

class Derived : public Base
{
public:
    void print() { cout << "From Derived.\n"; }
};
// Output: Derived obj; obj.print();
//  From Derived.

class Point
{
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    Point a(1, 1);
    Point b(2, 2);
    b = a;
    Point c(b);
    cout << a.getX() << ' ' << a.getY() << '\n';
    cout << b.getX() << ' ' << b.getY() << '\n';
    cout << c.getX() << ' ' << c.getY() << '\n';
    return 0;
}