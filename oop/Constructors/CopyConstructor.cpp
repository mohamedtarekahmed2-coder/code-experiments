#include <iostream>
using namespace std;

class Var
{
private:
    int *ptr = nullptr;

public:
    Var() 
    {
        ptr = nullptr;
    }
    Var(int num) 
    {
        ptr = new int(num);
    }
    Var(const Var &other)
    {
        this->ptr = new int(*other.ptr);
    }

    void Print()
    {
        cout << ptr << ' ' << *ptr << '\n';
    }
    Var& operator=(const Var& other)
    {
        this->ptr = new int(*other.ptr);
        return *this;
    }
    
    ~Var()
    {
        delete ptr;
    }
};

int main()
{
    int num = 99;
    Var ob1(num);
    ob1.Print();

    Var ob2 = ob1;
    ob2.Print();
    
    Var ob3(ob1);
    ob3.Print();
    
    Var ob4;
    ob4 = ob1;
    ob4.Print();
    
    return 0;
}