#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        if(this-> next !=NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout<< "Memeory is free for node with value" << val <<endl;
    }
};

void insertAtHead(Node* &head, int v){
    Node* temp = new Node(v);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int v)
{
    Node* temp = new Node(v);
    tail->next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail,  int position, int d)
{
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
    temp -> next = nodeToInsert;
}

void deleteNode(int position,Node* &head)
{
    if(position ==1)
    {
        Node* tmp = head;
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

    prev -> next = curr ->next;
    curr -> next = NULL;
    delete curr;

    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<< temp ->data<<" ";
        temp=temp ->next;
    }
    cout<<endl;
}

int main()
{
    //created a new node
    Node* node1 = new Node(10);
    cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 17);
    print(head);
    insertAtPosition (head, tail, 3, 7);
    print(head);
    insertAtPosition (head, tail, 4, 9);
    print(head);

    // cout<<"Head :" << head -> data << endl;
    // cout<<"Tail :" << tail -> data << endl;

    deleteNode(5, head);
    print(head);

    return 0;
} 