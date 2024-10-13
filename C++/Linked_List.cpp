#include <bits/stdc++.h>
using namespace std;

// Define a structure for a singly-linked list node.
struct Node
{
    int data;          // Data stored in the node.
    struct Node *next; // Pointer to the next node in the list.
};

// Function to display the elements of a linked list.
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data;
        ptr = ptr->next;
        if (ptr != NULL)
            cout << "->";
    }
}

// Function to insert a node with 'data' at a specified 'index' in the linked list.
struct Node *insert_mid(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node.
    struct Node *temp = head;
    int i = 1;
    while (i != index)
    {
        temp = temp->next;
        i++;
    }
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

// Function to search for a specific 'data' value in the linked list.
struct Node *search(struct Node *ptr, int data)
{
    struct Node *temp = ptr;
    int location = 1;
    while (ptr->next != NULL)
    {
        if (ptr->data == data)
        {
            cout << location;
            break;
        }
        ptr = ptr->next;
        location++;
    }
}

// Function to insert a node with 'data' before the last node in the linked list.
struct Node *insertBeforeLast(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *ptr1 = head->next;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node.
    temp->data = data;

    while (ptr1->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr->next;
    }
    ptr->next = temp;
    temp->next = ptr1;
}

// Function to delete the first node in the linked list.
struct Node *delete_node(struct Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete." << endl;
        return head;
    }

    struct Node *temp = head;
    head = head->next; // Update 'head' to point to the second node.
                       // free(temp);        // Free the memory of the deleted node.
    display(head);
}

// Function to create and manipulate the linked list.
void create()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // Create nodes and link them to form a linked list.
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = first;

    first->data = 3;
    first->next = second;

    second->data = 3;
    second->next = NULL;

    // Display the initial linked list.
    cout << "Linked List before any operation:   ";
    display(head);
    cout << endl;

    cout << "Linked List Desired location operation:   ";
    insert_mid(head, 22, 2); //(key to add=22,index=2)
    display(head);
    cout << endl;

    cout << "Location of node with Key=22:   ";
    search(head, 22); //(key to search=3)
    cout << endl;

    cout << "Insert after last node:   ";
    insertBeforeLast(head, -4); //(key to insert=-4)
    display(head);
    cout << endl;

    cout << "After Deleting first node:   ";
    delete_node(head);

    cout << endl;
}

int main()
{
    create(); // Call the create function to set up and manipulate the linked list.
    return 0;
}
