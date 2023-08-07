#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Node{

    public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;

        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< value << endl;
    }

};

//Insert node in circular linked list

void insertAtPosition(Node*& tail, int element, int data)
{
    //Empty list
    if(tail == NULL)
    {
        Node* newnode = new Node(data);
        newnode->next = newnode;
        tail = newnode;
    }
    else
    {
        //if the list is not empty
        Node* curr = tail;

        while(curr->data != element)
        {
            curr = curr->next;
        }

        Node* newnode = new Node(data);
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void display(Node* n)
{
    Node* temp = n;

    if(n == NULL)
    {
        cout<<"LIST IS EMPTY..."<<endl;
    }

    do{
        cout<<n->data<<"->";
        n = n->next;
    }while (n != temp);
    cout<<"NULL"<<endl;
    
}

void deletenode(Node* &tail, int element)
{
    //if tail is empty
    if(tail == NULL)
    {
        cout<<"List is empty .. "<<endl;
        return;
    }
    else{
        //non empty
        //asssuming that value is present
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //only 1 node is present
        if(curr == prev)
        {
            tail = NULL;
        }

        //>=2 node present
        else if(curr == tail)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;

    }
}

int main()
{
    Node* tail = NULL;

    insertAtPosition(tail, 5, 10);
    insertAtPosition(tail, 10, 20);
    insertAtPosition(tail, 20, 30);
    insertAtPosition(tail, 20, 40);
    display(tail);

    deletenode(tail, 10);
    display(tail);


    
    return 0;
}