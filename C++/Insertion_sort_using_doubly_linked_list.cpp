/*This code is of insertion sort using doubly linked list.
Algorithm:
-->Create a class node containing data, address of previous node and address of next node.
-->In case of insertion to the list, start traversing from the provided head and find its correct position in the list.
-->We will then update the next node addresss and previous node address for the nodes between which new node is being inserted.
-->For printing the sorted list, start from head and traverse through the list.
Time complexity:O(n*n) 
As we run a for loop for n elements and for each element we traverse through the list using  another loop.
Space Complexity: O(1)
As we are not using any extra space.
*/

#include<bits/stdc++.h>
using namespace std;

//Defining node for the program
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
//Defining function for inserting a node
void Insert_sort(Node* &head,int val){
    Node* n=new Node(val);
    //checking for empty list
    if(head==NULL){
        head=n;
        return;
    }
    //if input is larger than current largest
    if(head->data>val){
        head->prev=n;
        n->next=head;
        head=n;
        return;
    }
    //Traverse till you find correct position
    Node* temp=head;
    while(temp->next!=NULL){
        //if found correct position: insert and return
        if(temp->data>val){
            n->next=temp;
            temp->prev->next=n;
            n->prev=temp->prev;
            temp->prev=n;
            return;
        }
        else{
            temp=temp->next;
        }
    }
    //checking for last element
    if(temp->data>val){
        n->next=temp;
        if(temp->prev!=NULL){
            n->prev=temp->prev;
        temp->prev->next=n;
        }
        temp->prev=n;
        return;
    }
    else{
        temp->next=n;
        n->prev=temp;
    }
    return;
} 

//Defining function for display doubly linked list
void display(Node* head){
    // //check for empty list
    if(head==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp=head;
    cout<<"Sorted list: ";
    //Traversing through nodes
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<(temp->data)<<endl;
    return;
}

//Main driver code
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    //Code for taking input from user
    cout<<"Enter number of inputs:";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        int x;cin>>x;
        Insert_sort(head,x);
    }
    display(head);
    return 0;  
}

/*
Code contributed by:-
Abhijeet Kumar Jha
*/