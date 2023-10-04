#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data "<< val<<endl;

    }
};

void insertNode(Node* &tail, int element, int d) {
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;
        while( curr -> data != element){
            curr = curr -> next;
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    do{
        cout<< tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    if(tail==NULL){
        cout<< "List is empty, please check again" << endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        if(curr == prev) {
            tail = NULL;
        }
        else if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 7);
    print(tail);
    insertNode(tail, 5, 6);
    print(tail);
    deleteNode(tail, 6);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    deleteNode(tail, 7);
    print(tail);
    deleteNode(tail, 3);
    print(tail);


    return 0;
}