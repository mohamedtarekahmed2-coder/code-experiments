#include <iostream>
using namespace std;
#define nl cout << '\n'

// class ClassC {
// private:
//     int secretC = 100;
//     friend class ClassB; 
// };

// class ClassB {
// private:
//     int secretB = 50;
//     friend class ClassA; 
// public:
//     void showC(ClassC c) {
//         cout << "ClassB accesses C: " << c.secretC << endl; 
//     }
// };

// class ClassA {
// public:
//     void showB(ClassB b) {
//         cout << "ClassA accesses B: " << b.secretB << endl; 
//     }

//     void showC(ClassC c) {
//         // cout << c.secretC; // Error
//     }
// };


// class ClassB; // Forward Declaration

// class ClassA {
// private:
//     int privateA = 10;
//     friend class ClassB; 
// };

// class ClassB {
// private:
//     int privateB = 20;
// public:
//     void accessA(ClassA a) {
//         cout << "ClassB accesses ClassA: " << a.privateA << endl; 
//     }

//     void tryAccessBFromA(ClassA a) {
//         // ClassA can't access ClassB
//     }
// };

class Parent {
private:
    int parentSecret = 1;
    friend void friendFunction(Parent p);
};

class Child : public Parent {
private:
    int childSecret = 2;
};

void friendFunction(Parent p) {
    cout << "Parent secret: " << p.parentSecret << endl; 
}

void tryAccessChild(Child c) {
    // cout << c.childSecret; // Child can't see Parent friend function
}

int main() {
    Parent p;
    friendFunction(p);
    return 0;
}