#include <iostream>
#include <queue>
using namespace std;

class BinaryTree
{
private:
    struct Node
    {
        int item;
        Node *left;
        Node *right;
        Node()
        {
            item = 0;
            left = right = nullptr;
        }
    };

public:
    BinaryTree()
    {
    }
    void preOrder(Node *root)
    {
        if (root)
        {
            cout << root->item << ' ';
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node *root)
    {
        if (root)
        {
            inOrder(root->left);
            cout << root->item << ' ';
            inOrder(root->right);
        }
    }

    void postOrder(Node *root)
    {
        if (root)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->item << ' ';
        }
    }

    void levelOrder(Node *root)
    {
        if (!root) return;

        queue<Node *> travel;
        travel.push(root);

        while (!travel.empty())
        {
            Node *current = travel.front();
            travel.pop();

            cout << current->item << ' ';

            if (current->left)
                travel.push(current->left);
            if (current->right)
                travel.push(current->right);
        }
    }
};
