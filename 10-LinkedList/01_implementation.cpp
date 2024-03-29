#include<bits/stdc++.h>
using namespace std;

#define endl "\n";


class Node{

    public:
    int data;
    Node* next;

    Node(int data=0)
    {
        this->data = data;
        this->next = NULL;
    }

};

//1.Traversing the Linked list
void display(Node* n)
{
    cout<<"Printing the list : "<<endl;
    while(n!=nullptr)
    {
        cout<<n->data<<"->";
        n = n->next;
    }
    cout<<"NULL"<<endl;
}

//2. Length of linked list
int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

int main()
{
    /*In this line, an object of the Node class named n1 is created using automatic storage (on the stack). This means that the memory for n1 is allocated on the stack, and when the scope of the main function ends, the memory for n1 will be automatically deallocated.*/
    // Node n1(11);
    /*In this line, a pointer to a Node object named n2 is created. The new operator is used to allocate memory for a Node object on the heap. This memory will persist until it is explicitly deallocated using the delete operator. This is manual memory management. If you don't use delete to deallocate the memory, it will lead to a memory leak.*/
    // Node* n2 = new Node(10);

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);
    Node* n6 = new Node(60);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;



    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}