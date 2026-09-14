#include <iostream>
using namespace std;

class LinkedList
{
private:
    // Node
    struct Node
    {
        int item;
        Node *next;
        Node()
        {
            item = 0;
            next = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *current = head;
            head = head->next;
            delete current;
        }
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    // insertion
    void push_front(int val)
    {
        Node *new_node = new Node();
        new_node->item = val;

        new_node->next = head;
        head = new_node;
        if (size == 0)
            tail = new_node;
        size++;
    }
    void push_back(int val)
    {
        Node *new_node = new Node();
        new_node->item = val;

        if (size == 0)
            head = new_node;
        else
            tail->next = new_node;
        tail = new_node;
        size++;
    }
    void insert(int index, int val)
    {
        if (index < 0 || size < index)
        {
            throw out_of_range("out of range");
            return;
        }
        else if (index == 0)
        {
            push_front(val);
            return;
        }
        else if (index == size)
        {
            push_back(val);
            return;
        }

        Node *new_node = new Node();
        new_node->item = val;

        Node *current = head;
        index--; // gat index - 1
        while (index--)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
        size++;
    }

    // Deletion
    void pop_front()
    {
        if (size == 0)
            return;

        Node *current = head;
        if (size == 1)
            head = tail = nullptr;
        else
            head = head->next;

        delete current;
        size--;
    }
    void pop_back()
    {
        if (size == 0)
            return;

        Node *current = head;
        if (size == 1)
            head = tail = nullptr;
        else
        {
            while (current->next != tail)
                current = current->next;
            tail = current;
            tail->next = nullptr;
            current = current->next;
        }
        delete current;
        size--;
    }
    void remove(int val)
    {
        if (is_empty())
            return;
        if (head->item == val)
        {
            pop_front();
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->item != val)
        {
            current = current->next;
        }
        if (current->next != nullptr)
        {
            if (current->next == tail)
            {
                pop_back();
            }
            else
            {
                Node *target = current->next;
                current->next = current->next->next;
                delete target;
                size--;
            }
        }
    }

    void reverse_by_interator()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        tail = head;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Reverse by recursively
    // Node *reverse_by_recursively(Node *head)
    // {
    //     if(head == nullptr) return head;

    //     if(head->next == nullptr) return head;

    //     Node *res = reverse_by_recursively(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return res;
    // }

    // Traversal
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->item << ' ';
            current = current->next;
        }
        cout << '\n';
    }
    int search(int val)
    {
        Node *current = head;
        int index = 0;
        while (current != nullptr)
        {
            if (current->item == val)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }
};

class DoublyLinkedList
{
private:
    struct Node
    {
        Node *prev;
        int item;
        Node *next;
        Node(int val = 0)
        {
            item = val;
            prev = next = nullptr;
        }
    };

    Node *head, *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }
    ~DoublyLinkedList()
    {
        if (head == nullptr)
            return;
        while (head->next != nullptr)
        {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }

    bool is_empty() const
    {
        return head == nullptr;
    }

    void push_front(int val)
    {
        Node *new_node = new Node(val);

        if (is_empty())
            head = tail = new_node;
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }
    void push_back(int val)
    {
        Node *new_node = new Node(val);

        if (is_empty())
            head = tail = new_node;
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }
    void insert(int pos, int val)
    {
        if (pos < 0 || size < pos)
        {
            cout << "out of range.\n";
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
            return;
        }
        else if (pos == size)
        {
            push_back(val);
            return;
        }
        else
        {
            Node *new_node = new Node(val);
            Node *current;
            if (pos < size / 2)
            {
                current = head;
                for (int i = 0; i < pos; i++)
                    current = current->next;
            }
            else
            {
                current = tail;
                for (int i = size - 1; i > pos; i--)
                    current = current->prev;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev = new_node;
            new_node->prev->next = new_node;
            size++;
        }
    }

    void pop_front()
    {
        if (size == 0)
        {
            cout << "no elements to delete.\n";
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            head = head->next;
            head->prev = nullptr;
            delete current;
        }
        size--;
    }
    void pop_back()
    {
        if (size == 0)
        {
            cout << "no elements to delete.\n";
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
        }
        size--;
    }
    void remove_position(int pos)
    {
        if (pos < 0 || size <= pos)
        {
            cout << "out of range.\n";
            return;
        }
        else if (pos == 0)
        {
            pop_front();
            return;
        }
        else if (pos == size - 1)
        {
            pop_back();
            return;
        }
        else
        {
            Node *current;
            if (pos < size / 2)
            {
                current = head;
                for (int i = 0; i < pos; i++)
                    current = current->next;
            }
            else
            {
                current = tail;
                for (int i = size - 1; i > pos; i--)
                    current = current->prev;
            }
            current->next->prev = current->prev;
            current->prev->next = current->next;
            delete current;
        }
        size--;
    }
    void remove_element(int val)
    {
        if (size == 0)
        {
            cout << "no element to delete.\n";
            return;
        }
        else if (val == head->item)
        {
            pop_front();
            return;
        }
        else if (val == tail->item)
        {
            pop_back();
            return;
        }
        else
        {
            Node *current = head->next;
            while (current != nullptr && current->item != val)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                delete current;
                size--;
            }
            else
            {
                cout << "the element isn't here.\n";
            }
        }
    }
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->item << ' ';
            current = current->next;
        }
        cout << '\n';
    }
};

int main()
{
}