#include <iostream>
using namespace std;

bool IsOdd(int);

bool IsEven(int n)
{
    if (n == 0)
        return true;
    else
    {
        return IsOdd(n - 1);
    }
}

bool IsOdd(int n)
{
    return !IsEven(n - 1);
}

int main()
{
    cout << IsEven(2) << ' ' << IsEven(3) << '\n';
    cout << IsOdd(2) << ' ' << IsOdd(3) << '\n';
    return 0;
}