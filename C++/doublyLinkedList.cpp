#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL;
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

void insertAtHead(Node* &head, int d)
{
    //empty list
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head ->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d )
{
    //empty list
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    temp ->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail,  int position, int d) {
    
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    } 

    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return; 
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next  = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(int position,Node* &head)
{
    if(position ==1)
    {
        Node* tmp = head;
        tmp ->next -> prev = NULL;
        head = head -> next;
        tmp -> next = NULL;
        delete tmp;
    }

    else{
    Node* curr = head;
    Node* prev = NULL;

    int cnt=1;
    while(cnt< position){
        prev = curr;
        curr = curr ->next;
        cnt++;
    }

    curr -> prev = NULL;
    prev -> next = curr ->next;
    curr -> next = NULL;
    delete curr;

    }
}

int getLen(Node* head)
{
    int len=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

void print(Node* head)
{
    Node*temp = head;
    while(temp!=NULL)
    {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;

}

int main()
{
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;
    print(head);
    // cout<<getLen(head)<<endl;

    insertAtHead(head, 9);
    print(head);
    insertAtHead(head, 7);
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtTail(tail, 11);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtPosition(head, tail, 7, 12);
    print(head);
    insertAtPosition(head, tail, 8, 13);
    print(head);
    insertAtPosition(head, tail, 1, 0);
    print(head);
    insertAtPosition(head, tail, 11, 20);
    print(head);
    cout<<endl;
    deleteNode(1, head);
    print(head);
    deleteNode(5, head);
    print(head);





    return 0;
}