#include <iostream>
using namespace std;

int tailFactorial(int n, int acc = 1)
{
    if (n == 0) return acc;
    return tailFactorial(n - 1, n * acc);
}

int main ()
{
    cout << tailFactorial(5);
    return 0;
}