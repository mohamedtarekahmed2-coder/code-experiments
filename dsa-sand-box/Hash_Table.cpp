#include <iostream>
#include <vector>
using namespace std;

struct HashNode
{
    int key;
    string val;
    HashNode *next;

    HashNode(int k, string v)
    {
        key = k;
        val = v;
        next = nullptr;
    }
};

class HashTable
{
private:
    int arraySize = 10;
    int totalelement = 0;
    HashNode **Table;

    int hashFunction(int key)
    {
        return (key % arraySize + arraySize) % arraySize;
    }

    void rehash(int newSize)
    {
        HashTable newTable(newSize);
        for (int i = 0; i < arraySize; i++)
        {
            HashNode *current = Table[i];
            while (current != nullptr)
            {
                newTable.set(current->key, current->val);
                current = current->next;
            }
        }
        swap(this->Table, newTable.Table);
        swap(this->arraySize, newTable.arraySize);
        swap(this->totalelement, newTable.totalelement);
    }

public:
    HashTable()
    {
        Table = new HashNode *[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            Table[i] = nullptr;
        }
    }
    HashTable(int size)
    {
        arraySize = size;
        Table = new HashNode *[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            Table[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < arraySize; i++)
        {
            HashNode *current = Table[i];
            while (current != nullptr)
            {
                HashNode *prev = current;
                current = current->next;
                delete prev;
            }
        }

        delete[] Table;
    }

    void set(int key, string val)
    {
        int index = hashFunction(key);

        HashNode *current = Table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->val = val;
                return;
            }
            current = current->next;
        }

        HashNode *newNode = new HashNode(key, val);
        newNode->next = Table[index];
        Table[index] = newNode;

        totalelement++;

        float loadFactor = (float)totalelement / arraySize;
        if (loadFactor >= 0.75)
            rehash(arraySize * 2);
    }

    string get(int key)
    {
        int index = hashFunction(key);
        HashNode *current = Table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->val;
            }
            current = current->next;
        }
        return "Not Found";
    }

    void printTable()
    {
        for (int i = 0; i < arraySize; i++)
        {
            cout << "Index " << i << ": ";
            HashNode *current = Table[i];

            while (current != nullptr)
            {
                cout << "[" << current->key << ":" << current->val << "] -> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        HashNode *current = Table[index];
        HashNode *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    Table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                cout << "Deleted key: " << key << "\n";
                totalelement--;
                float loadFactor = (float)totalelement / arraySize;
                if (loadFactor <= 0.25 && arraySize > 10)
                {
                    rehash(arraySize / 2);
                }
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Key not found to delete!\n";
    }
};

int main()
{
    cout << "==========================================\n";
    cout << "       HASH TABLE TEST CASES START        \n";
    cout << "==========================================\n\n";

    HashTable ht;

    // ---------------------------------------------------------
    cout << "--- [Test Case 1]: Basic Insertion & Retrieval ---\n";
    ht.set(1, "Apple");
    ht.set(2, "Banana");
    ht.set(3, "Cherry");
    
    cout << "Key 1: " << ht.get(1) << " (Expected: Apple)\n";
    cout << "Key 2: " << ht.get(2) << " (Expected: Banana)\n";
    cout << "Key 3: " << ht.get(3) << " (Expected: Cherry)\n\n";

    // ---------------------------------------------------------
    cout << "--- [Test Case 2]: Updating an Existing Key ---\n";
    ht.set(2, "Blueberry"); // Update key 2
    cout << "Key 2 after update: " << ht.get(2) << " (Expected: Blueberry)\n\n";

    // ---------------------------------------------------------
    cout << "--- [Test Case 3]: Collision Handling ---\n";
    // Assuming initial size is 10, keys 5, 15, and 25 will collide at index 5
    ht.set(5, "Dog");
    ht.set(15, "Cat");
    ht.set(25, "Bird");
    
    cout << "Key 5: " << ht.get(5) << " (Expected: Dog)\n";
    cout << "Key 15: " << ht.get(15) << " (Expected: Cat)\n";
    cout << "Key 25: " << ht.get(25) << " (Expected: Bird)\n";
    cout << "\nTable state after collisions (Notice chaining at index 5):\n";
    ht.printTable();
    cout << "\n";

    // ---------------------------------------------------------
    cout << "--- [Test Case 4]: Rehashing (Grow / Expansion) ---\n";
    // Current elements: 1, 2, 3, 5, 15, 25 (6 elements)
    // To trigger loadFactor >= 0.75 in a size 10 table, we need 8 elements.
    ht.set(7, "Elephant");
    ht.set(8, "Fox"); // 8th element -> Should trigger rehash to size 20!
    
    cout << "Added 2 more elements. Table should have rehashed to size 20.\n";
    ht.printTable(); // You should see indices up to 19 now
    cout << "Key 15 after rehash: " << ht.get(15) << " (Expected: Cat)\n\n";

    // ---------------------------------------------------------
    cout << "--- [Test Case 5]: Missing Keys (Get and Remove) ---\n";
    cout << "Get key 99: " << ht.get(99) << " (Expected: Not Found)\n";
    cout << "Try to remove key 99: ";
    ht.remove(99); // Expected: Key not found to delete!
    cout << "\n";

    // ---------------------------------------------------------
    cout << "--- [Test Case 6]: Deletion & Rehashing (Shrink) ---\n";
    // Current size: 20. Current elements: 8.
    // To trigger loadFactor <= 0.25 (which is 5 elements), we need to delete 3 elements.
    ht.remove(15);
    ht.remove(25);
    ht.remove(7);
    
    cout << "\nRemoved 3 elements. Table should have shrunk back to size 10.\n";
    ht.printTable(); // You should see indices up to 9 again
    
    // Verify deleted keys are gone
    cout << "Get deleted Key 15: " << ht.get(15) << " (Expected: Not Found)\n";

    cout << "\n==========================================\n";
    cout << "       ALL TEST CASES COMPLETED           \n";
    cout << "==========================================\n";

    return 0;
}