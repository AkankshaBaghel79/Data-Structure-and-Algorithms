#include<bits/stdc++.h>
// #include "doublyLinkedList.h"
using namespace std;

#define endl "\n";

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;

        if(next != NULL)
        {
            delete next;
            next = nullptr;
        }

        cout << "memory free for node with data "<< val << endl;
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

//2.Length of doubly linked list
int getlength(Node* head)
{
    Node* n = head;
    int len = 0;
    while(n!=nullptr)
    {
        len++;
        n = n->next;
    }
    return len;
}