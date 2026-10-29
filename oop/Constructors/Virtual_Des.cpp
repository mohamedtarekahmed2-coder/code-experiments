#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Base {
public:
    Base() { 
        cout << "[Base] Constructor called\n"; 
    }
    virtual ~Base() { 
        cout << "[Base] Destructor called\n"; 
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[100]; 
        cout << "[Derived] Constructor called (Memory Allocated)\n";
    }

    ~Derived() {
        delete[] data; 
        cout << "[Derived] Destructor called (Memory Freed)\n";
    }
};

int main() {
    cout << "--- Creating Object via Base Pointer ---\n";
    Base* ptr = new Derived();

    cout << "\n--- Deleting Object ---\n";
    delete ptr; 

    return 0;
}