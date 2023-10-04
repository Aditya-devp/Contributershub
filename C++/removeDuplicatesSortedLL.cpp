/* C++ Program to remove duplicates from a sorted linked list */
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

void removeDuplicates(Node* head)
{
	Node* current = head;
	Node* next_next;

	if (current == NULL)
	return;

	while (current->next != NULL)
	{
        if (current->data == current->next->data)
        {		
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else 
        {
            current = current->next;
        }
	}
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);	
	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;
	/* Let us create a sorted linked list to test the functions
	Created linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);									
	cout<<"Linked list before duplicate removal " << endl;
	printList(head);
	removeDuplicates(head);
	cout<<"\nLinked list after duplicate removal "<< endl;	
	printList(head);			
	return 0;
}