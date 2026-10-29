#include <iostream>
using namespace std;

template <typename T>
T add(T value)
{
    return value;
}

template <typename T, typename... Ts>
T add(T head, Ts... rest)
{
    return head + add(rest...);
}

int main()
{
    cout << add(1, 2, 3, 4, 5);
}