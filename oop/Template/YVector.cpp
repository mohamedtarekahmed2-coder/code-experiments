#include <iostream>
#include <string>
#include <cstdlib> // لـ exit()

using namespace std;

template <class T>
class YousefVector
{
private:
    int size = 5;
    int capacity;
    T *data;

public:
    YousefVector(int cap = 5) : capacity(cap)
    {
        data = new T[capacity];
    }
    ~YousefVector()
    {
        delete[] data; 
    }
    T &operator[](int indx)
    {
        if (indx > size - 1 || indx < 0)
        {
            cout << "An error has occurred, ";
            cout << "index out of range." << endl;
            exit(-1);
        }
        return data[indx];
    }
};

int main()
{
    YousefVector<string> vec(10);

    vec[0] = "Hello";
    vec[1] = "World!";
    cout << "vec[0]: " << vec[0] << endl;
    cout << "vec[1]: " << vec[1] << endl;
    // vec[10] = "Error Test";

    return 0;
}