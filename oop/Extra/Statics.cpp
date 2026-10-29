#include <iostream>
using namespace std;

class Count
{
private:
    static int counter;
    int data = 0;
public:
    Count() { counter++; }
    int GetCounter() { return counter; }
    // static int GetData() { return data; } // Error, can only use static members
    static void Print() { cout << counter << '\n'; }
};
int Count::counter = 0;

int main()
{
    Count c1, c2, c3;
    cout << c1.GetCounter() << '\n';
    Count::Print();
    return 0;
}