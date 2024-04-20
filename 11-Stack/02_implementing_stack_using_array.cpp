#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // Behaviour
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    // Insert operation in stack
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    // Delete operation in stack
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    // Top element of the stack
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    // check stack is empty or not
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);

    cout << s.top << endl;
    cout << s.size << endl;

    return 0;
}