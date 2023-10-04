// Recursive C++ program to reverse a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	/* Function to reverse the linked list */
	Node* reverse(Node* node)
	{
		if (node == NULL)
			return NULL;
		if (node->next == NULL) {
			head = node;
			return node;
		}
		Node* node1 = reverse(node->next);
		node1->next = node;
		node->next = NULL;
		return node;
	}

	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

// //iterative approach
// Node* reverseLinkedList(Node* head)
// {
//     if( head == NULL || head -> next == NULL)
//     {
//         return head;
//     }
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* frwd = NULL;

//     while (curr != NULL)
//     {
//         frwd = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = frwd;
//     }
    
//     return prev;
// }

// //recursive approach
// void reverse(Node* &head, Node* curr, Node* prev )
// {
//     if(curr == NULL){
//         head = prev; 
//         return ;
//     }
    
//     Node* forward = curr -> next;
//     reverse(head, forward, curr);
//     curr -> next = prev;
    
// }

// Node* reverseLinkedList(Node* head)
// {
//     Node* curr = head;
//     Node* prev = NULL;
//     reverse(head, curr, prev);
//     return head;

// }
