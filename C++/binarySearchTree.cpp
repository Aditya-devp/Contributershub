/*
    A binary search tree is a special type of binary tree in which the left child of a node contains value less than the node and the right child of the node contains value greater than the node.
    This condition is applicable to each and every node of the Binary Search Tree.
*/


#include<bits/stdc++.h>

using namespace std;

// Structure definition of BST node

struct Treenode {
  /*
     (node->data)
        /  \
    (left)  (right)
  */
  int data;
  Treenode *left, *right;
  Treenode():data(0),left(NULL),right(NULL) {}
  Treenode(int val):data(val),left(NULL),right(NULL) {}
};

// Insertion in BST

Treenode* insert(Treenode *node,int data){
    // If node is NULL, return a new node
    if(!node) return new Treenode(data);

    // Comparing the node's value with the data to be inserted.
    if(node->data>data)
    node->left=insert(node->left,data);
    else 
    node->right=insert(node->right,data);
    return node;
}


// Searching in BST

bool search(Treenode *node,int data){
    // If node is NULL, return false
    if(!node) return false;

    // Comparing the node's value with the data to be searched.
    if(node->data>data)
    search(node->left,data);

    else if(node->data<data)
    search(node->right,data);

    else return true;
}

// Deletion in BST

Treenode* deleteValue(Treenode *node,int data){
    /*
    There are 3 cases while deleting a node in a BST:
        1. Deleting a node with no children
        2. Deleting a node with only 1 child
        3. Deleting a node with both children
    */

    if(!node) return NULL;

    // Traversing until we reach the node to be deleted
    // Node is in left subtree
    if(node->data>data){
        node->left=deleteValue(node->left,data);
        return node;
    }
    // Node is in right subtree
    else if(node->data<data){
        node->right=deleteValue(node->right,data);
        return node;
    }

    // After reaching the node to be deleted

    // If BST has no child
    if(!node->left && !node->right){
        delete node;
        return NULL;
    }

    // If BST has only 1 child 

    else if(!node->left){
        Treenode *temp=node->right;
        delete node;
        return temp;
    }
    else if(!node->right){
        Treenode *temp=node->left;
        delete node;
        return temp;
    }

    //BST has both children

    else{
        Treenode *successor=node->right;

        // Finding the inorder successor
        while(successor&&successor->left){
            successor=successor->left;
        }

        node->data=successor->data;

        node->right=deleteValue(node->right,successor->data);
    }
        return node;
}


// Inorder traversal

void inorder(Treenode *node){
    if(!node) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

int main(){

    cout<<"Enter the total number of values to be inserted!"<<endl;

    int numberOfValues;
    cin>>numberOfValues;

    cout<<"Enter the values to be inserted in the binary search tree!"<<endl;

    int firstValue;
    cin>>firstValue;
    struct Treenode *BST=new Treenode(firstValue);

    for(int i=0;i<numberOfValues-1;++i){
        int value;
        cin>>value;
        insert(BST,value);
    }
    inorder(BST);
    BST=deleteValue(BST,5);
    inorder(BST);


    return 0;
}