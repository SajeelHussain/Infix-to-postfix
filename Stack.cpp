/*
Assignment-2

Title: Infix to Postfix Expression conversion and its evaluation using stack.

Design and implement ADT for expression conversion from infix to postfix 
and its evaluation using stack. 
Please note, operands can be a two-digit number, whereas the operators hold a single character space.

This assignment has two phases as listed below.

Write a complete stack class using arrays
and upload it to a public repo on GitHub. 
Later pull that work to include the infix to postfix conversion
and evaluation and push back
You should keep the Github repository public 
and share the link with the assignment submission.*/
#include <iostream>
using namespace std;
// Creating stack class
class Stack
{
    //Initializing necessary variable for the
    int *arr, next_Index, capacity;

public:
    // creating non-parametrize constructor in c++ for defualt size of stack
    Stack()
    {
        // defualt variable value for stack
        capacity = 10;
        arr = new int[capacity];
        next_Index = 0;
    }
    // Creating size parametrized constructor for stack
    Stack(int size_of_Stack)
    {
        capacity = size_of_Stack;
        arr = new int[size_of_Stack];
        next_Index = 0;
    }

    bool isEmpty()
    { // If the next_index is zero, then the stack is zero
        // if user adds something next index will move forward by 1
        if (next_Index == 0)
            return true;

        else
            return false;
    }

    int size()
    {
        return next_Index;
    }
    void push(int element)
    { // next index equals to capacity shows that stack is already filled
        // because if add something more the next index will get out of stack capacity
        if (next_Index == capacity)
        {
            cout << "The stack is overflowed." << endl;
            return;
        }
        arr[next_Index] = element;
        next_Index++;
    }
    void pop(int element)
    {
        if (isEmpty())
        {
            cout << "The stack is underflowed.";
            return;
        }
        next_Index--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "The stack is empty";
            return -1;
        }
        return arr[next_Index - 1];
    }
};

int main()
{
    Stack test_stack(5);
    test_stack.push(10);
    test_stack.push(10);
    test_stack.push(10);
    test_stack.push(10);
    test_stack.push(10);
    test_stack.push(10);
    cout << test_stack.size();
}