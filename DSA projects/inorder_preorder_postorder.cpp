#include <iostream>
using namespace std;

typedef struct node {
    int val;
    node *left, *right;
}node;

class bst {
    public:
        node *root;
        bst() {
            root = nullptr;
        }

        void insert(int val);
        void delete_bst(int val);
        void print_inorder();
        void inorder(node* temp);
        void print_preorder();
        void preorder(node* temp);
        void print_postorder();
        void postorder(node* temp);
};

void bst::insert(int val) {
    node *temp = root, *p;
    node *new_node = new node;
    new_node->val = val;
    if(!root) { 
        root = new_node;
        return ;
    }
    while(temp) {
        p = temp;
        if(temp->val > val) temp = temp->left;
        else    temp = temp->right;
    }
    p->val > val ? p->left = new_node : p->right = new_node;
    return ;
}

void bst::print_inorder() {
    inorder(root);
}

void bst::inorder(node* temp) {
    if(!temp)   return ;
    inorder(temp->left);
    cout<<temp->val<<" ";
    inorder(temp->right);
}

void bst::print_preorder() {
    preorder(root);
}

void bst::preorder(node* temp) {
    if(!temp)   return ;
    cout<<temp->val<<" ";
    preorder(temp->left);
    preorder(temp->right);
}

void bst::print_postorder() {
    postorder(root);
}

void bst::postorder(node* temp) {
    if(!temp)   return ;
    postorder(temp->left);
    postorder(temp->right); 
    cout<<temp->val<<" ";
}

int main() {
    bst b;
    b.insert(8);
    b.insert(2);
    b.insert(4);
    b.insert(9);
    b.insert(20);
    b.insert(1);
    b.insert(11);
    b.insert(100);

    cout<<"Inorder:     ";
    b.print_inorder();
    cout<<endl;
    cout<<"PreOrder:    ";
    b.print_preorder();
    cout<<endl;
    cout<<"PostOrder:   ";
    b.print_postorder();
    return 0;
}