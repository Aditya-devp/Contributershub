#include <iostream>
using namespace std;

// Define a structure for a stack
struct stack
{
    int size;   // The size of the stack
    int top;    // The index of the top element
    int *arr;   // Pointer to an array to store the elements
};

// Function to check if the stack is empty
bool isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)  // If the top is -1, the stack is empty
        return true;
    return false;
}

// Function to check if the stack is full
bool isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))  // If the top is equal to size - 1, the stack is full
        return true;
    return false;
}

// Function to display the elements in the stack
void display(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
    {
        cout << ptr->arr[i] << " ";
    }
    cout << endl;
}

// Function to push an element onto the stack
int push(struct stack *ptr, int data)
{
    if (isFull(ptr))  // Check if the stack is full
    {
        cout << "Overflow" << endl;  // Print an overflow message if it's full
    }
    else
    {
        ptr->top++;           // Increment the top index
        ptr->arr[ptr->top] = data;  // Store the data at the top index
        display(ptr);          // Display the stack after pushing the element
    }
}

// Function to pop an element from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))  // Check if the stack is empty
    {
        cout << "Stack is empty";  // Print a message indicating the stack is empty
    }
    else
    {
        ptr->top--;  // Decrement the top index to simulate popping an element
    }
    display(ptr);  // Display the stack after popping
}

int main()
{
    struct stack *s = new stack;  // Create a stack using a pointer
    s->size = 5;                  // Set the size of the stack
    s->top = -1;                  // Initialize the top index to -1 to indicate an empty stack
    s->arr = new int[s->size];    // Create an array to store the elements

    push(s, 1);  // Push 1 onto the stack
    push(s, 2);  // Push 2 onto the stack
    push(s, 3);  // Push 3 onto the stack
    pop(s);      // Pop an element from the stack
    pop(s);      // Pop another element from the stack
    pop(s);      // Pop another element from the stack

    delete[] s->arr;  // Deallocate the dynamically allocated array
    delete s;         // Deallocate the dynamically allocated stack structure

    return 0;
}
