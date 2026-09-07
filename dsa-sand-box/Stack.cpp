#include <iostream>
#include <vector>
using namespace std;

// Stack using Linked List
template <class all>
class StackLinkedList
{
private:
    struct node
    {
        all item;
        node *next;

        node()
        {
            next = nullptr;
        }
    };
    node *Top = nullptr;

public:
    void push(all newItem)
    {
        node *newItemPtr = new node;
        newItemPtr->item = newItem;
        newItemPtr->next = Top;
        Top = newItemPtr;
    }

    void pop()
    {
        if (!isEmpty())
        {
            node *temp = Top;
            Top = Top->next;
            delete temp;
        }
        else
            throw out_of_range("Stack is empty.");
    }

    all top()
    {
        if (isEmpty())
            throw out_of_range("Stack is empty.");
        else
            return Top->item;
        return 0;
    }

    bool isEmpty()
    {
        return Top == nullptr;
    }

    void print()
    {
        node *current = Top;
        while (current != nullptr)
        {
            cout << current->item << ' ';
            current = current->next;
        }
        cout << '\n';
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

// Stack using dynamic array

template<class all>
class StackVector
{
private:
    vector<all> v;

public:
    void push(all val)
    {
        v.push_back(val);
    }

    void pop()
    {
        if (!isEmpty())
            v.pop_back();

    }

    all top()
    {
        if (!isEmpty())
            return v.back();
        throw out_of_range("Stack is empty.");
    }

    bool isEmpty()
    {
        return v.empty();
    }

    void print()
    {
        for (int i = (int)v.size() - 1; i >= 0; i--)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
};


int main()
{
    StackLinkedList<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    cout << st.top();
    return 0;
}