// This program implements an AVL tree, which is a self-balancing binary search tree.
// Contributed by - Burhanuddin-2001

#include <iostream> //// for standard I/O operations
#include <vector>   //for storing collection of tree node values
#include <string>   //to convert integer to string for concatenation
#include <cstdlib>  //for using absolute function of maths
using namespace std;

// Creation of Binary Search Tree (BST) class
class BinarySearchTree
{
private:
    // Defining the structure of each BST node
    struct Node
    {
        int value;
        int height = 0;
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root = nullptr;

    // Private function to insert a new node into the BST
    Node *insert_inner(Node *temp, int value)
    {
        if (temp == nullptr)
        {
            Node *newnode = new Node();
            newnode->value = value;
            return newnode;
        }
        if (value < temp->value)
        {
            temp->left = insert_inner(temp->left, value);
        }
        else if (value >= temp->value)
        {
            temp->right = insert_inner(temp->right, value);
        }

        // Update the height of the current node and balance the tree if necessary
        temp->height = max(NodeHeight(temp->left), NodeHeight(temp->right)) + 1;
        return selfbalancing(temp);
    }

    // Private function to balance a BST node and its subtrees (Includes all the 4 cases)
    // It automatically balances an unbalanced node or if the node is already balanced, then it just returns it.
    Node *selfbalancing(Node *temp)
    {
        if (NodeHeight(temp->left) - NodeHeight(temp->right) > 1)
        {
            // tree is left heavy
            if (NodeHeight(temp->left->left) - NodeHeight(temp->left->right) > 0)
            {
                // This is a left-left case, perform a right rotation
                return rightrotate(temp);
            }
            else if (NodeHeight(temp->left->left) - NodeHeight(temp->left->right) < 0)
            {
                // This is a left-right case, perform a left rotation followed by a right rotation
                temp->left = leftrotate(temp->left);
                return rightrotate(temp);
            }
        }
        if (NodeHeight(temp->left) - NodeHeight(temp->right) < -1)
        {
            // tree is right heavy
            if (NodeHeight(temp->right->left) - NodeHeight(temp->right->right) > 0)
            {
                // This is a right-left case, perform a right rotation followed by a left rotation
                temp->right = rightrotate(temp->right);
                return leftrotate(temp);
            }
            else if (NodeHeight(temp->right->left) - NodeHeight(temp->right->right) < 0)
            {
                // This is a right-right case, perform a left rotation
                return leftrotate(temp);
            }
        }

        return temp;
    }

    // Returns the height of a node, or -1 if the node is null.
    int NodeHeight(Node *temp)
    {
        if (temp == nullptr)
            return -1;
        return temp->height;
    }

    // Helper function for balanceTree function (Private function)
    // It checks that if a particular node is balanced or not (recursively)
    bool inner_balance(Node *temp)
    {
        if (temp == nullptr)
            return true;
        return (abs(NodeHeight(temp->left) - NodeHeight(temp->right)) <= 1 && inner_balance(temp->left) && inner_balance(temp->right));
    }

    // Helper function for selfbalancing function (Private function)
    // its sole purpose is to right rotate the tree from a particular node
    Node *rightrotate(Node *p)
    {
        Node *c = new Node();
        Node *t = new Node();
        c = p->left;
        t = c->right;

        c->right = p;
        p->left = t;

        p->height = max(NodeHeight(p->left), NodeHeight(p->right)) + 1;
        c->height = max(NodeHeight(c->left), NodeHeight(c->right)) + 1;

        return c;
    }

    // Helper function for selfbalancing function (Private function)
    // its sole purpose is to left rotate the tree from a particular node
    Node *leftrotate(Node *c)
    {
        Node *p = new Node();
        Node *t = new Node();
        p = c->right;
        t = p->left;

        p->left = c;
        c->right = t;

        p->height = max(NodeHeight(p->left), NodeHeight(p->right)) + 1;
        c->height = max(NodeHeight(c->left), NodeHeight(c->right)) + 1;

        return p;
    }

    // Private function to display the tree in console with pictorial representation
    void Display(Node *temp, int level = 0)
    {
        if (temp == nullptr)
            return;
        Display(temp->right, level + 1);
        if (level != 0)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "|\t\t";
            }
            cout << "|----->" << temp->value << endl;
        }
        else
            cout << "|----->" << temp->value << endl;
        Display(temp->left, level + 1);
    }

public:
    // Public function to insert a node into the BST
    void insert(int value)
    {
        root = insert_inner(root, value);
    }

    // Public function to display the BST
    void display()
    {
        Display(root);
    }

    // Public function to check if the BST is balanced
    void balanceTree()
    {
        bool result = inner_balance(root);
        if (result)
            cout << "Balanced Tree" << endl;
        else
            cout << "Unbalanced Tree" << endl;
    }
};

int main()
{
    int value = 0;
    BinarySearchTree bst;
    cout << "To make a tree, just keep adding node values. When you're done, type -1 to stop." << endl;
    vector<int> treenodes;
    while (1)
    {
        cin >> value;
        if (value == -1)
            break;
        treenodes.push_back(value);
    }
    for (int i = 0; i < size(treenodes); i++)
    {
        bst.insert(treenodes[i]);
    }
    bst.display();
    bst.balanceTree();
    return 0;
}