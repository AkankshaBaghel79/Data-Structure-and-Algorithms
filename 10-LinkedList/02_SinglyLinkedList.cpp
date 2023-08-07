#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

class Node{

    public:
    int data;
    Node* next;

    //Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node()
    {
        int val = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout<<"Memory is free for node having data : "<<val<<endl;
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

//2.Insert Node at the front of the Linked List
void InsertAtHead(Node* &head, int val)
{
    //1. Prepare a new node
    Node* newnode = new Node(val);

    //2.Put it in front of current head
    newnode->next = head;

    //3.Move head of the list to point to the newNode
    head = newnode;

}
//For example:
/*
10->NULL
10->1->2->3->NULL;
*/

//3.Insert Node at the End of the Linked List
void InsertAtTail(Node* &head, int val)
{
    //1.Prepare a new node
    Node* newnode = new Node(val);

    //2.if the linked list is empty ,then the head node will be the newnode or the endnode
    if(head == NULL)
    {
        head = newnode;
    }

    //3.find the last node
    Node* last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }

    //4.Insert newnode after the last node(or end node)
    last->next = newnode;
}
//100->NULL
//1->2->3->100->NULL

//4.Insert Node after a given node
void insertAterNode(Node* &prev, int val)
{
    //1.Prepare a new node
    Node* newnode = new Node(val);

    //2.Check if previous node is NULL
    if(prev == NULL)
    {
        cout<<"Previous can not be null";
        return;
    }

    //Insert newnode after previous
    newnode->next = prev->next;
    prev->next = newnode;

}

//4->NULL
//1->2->4->3->NULL
//1->2->3->NULL

//5.Insert Node at a given position
void insertAfterPosition(Node* &head, int position, int val)
{
    //Insert at start position
    if(position == 1)
    {
        InsertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < position-1)
    {
        temp = temp->next;
        count++;
    }

    //Insert at last position
    if(temp->next == NULL)
    {
        InsertAtTail(head, val);
        return;
    }

    //Create a new node
    Node* newnode = new Node(val);

    //insert newnode after previous
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletenode(Node* &head, int position)
{
    //deleting first or head node
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;

        //memory free from start node
        temp->next = NULL;
        delete temp;
    } 
    else{
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count<position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteValueNode(Node* &head, int val)
{
    if(head->data == val)
    {
        Node* temp = head;
        head = head->next;
        //memory free from start node
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        while(curr->data != val && curr->next!=NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        
        if(curr->data != val)
        {
            cout<<"Value not present .. "<<endl;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    Node* head = new Node(10);
    Node* Second = new Node(20);
    Node* third = new Node(30);

    head->next = Second;
    Second->next = third;

    // display(head);
    InsertAtHead(head, 11);
    InsertAtHead(head, 44);

    InsertAtTail(head, 55);
    InsertAtTail(head, 78);
    display(head);

    // insertAterNode(Second, 55);

    // insertAfterPosition(head, 4, 101);

    // deletenode(head, 1);
    // deletenode(head,3);
    // deletenode(head,7);

    deleteValueNode(head, 550);

    display(head);
    return 0;
}