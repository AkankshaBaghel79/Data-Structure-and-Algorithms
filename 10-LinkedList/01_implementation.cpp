#include<bits/stdc++.h>
using namespace std;

#define endl "\n";


class Node{

    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};


int main()
{
    /*In this line, an object of the Node class named n1 is created using automatic storage (on the stack). This means that the memory for n1 is allocated on the stack, and when the scope of the main function ends, the memory for n1 will be automatically deallocated.*/
    Node n1(11);
    /*In this line, a pointer to a Node object named n2 is created. The new operator is used to allocate memory for a Node object on the heap. This memory will persist until it is explicitly deallocated using the delete operator. This is manual memory management. If you don't use delete to deallocate the memory, it will lead to a memory leak.*/
    Node* n2 = new Node(10);

    return 0;
}