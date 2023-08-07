#include<bits/stdc++.h>
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

//3.Insert Node at the front of the Linked List
void InsertAthead(Node* &head, int val)
{
    //1.Prepare a node;
    Node* newnode = new Node(val);

    //checking if empty list
    if(head == NULL)
    {
       head = newnode;
       return; 
    }

    //2.Put it in front of current head
    newnode->next = head;

    //3.Make the prev of head point to newNode
    head->prev = newnode;

    //4.Move head of the list to point to the newnode
    head = newnode;
}

//4.Insert Node at the End of the Linked List
void InsertAtTail(Node* &head, int val)
{
    //1.Prepare a new node
    Node* newnode = new Node(val);

    //2.if the linked list is empty ,then the head node will be the newnode or the endnode
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    //3.find the last node
    Node* last = head;
    while(last->next != NULL)
    {
        last = last->next;
    }

    //4.Insert newnode after the last node(or end node)
    last->next = newnode;

    //5.Make the prev of newnode point to lastnode
    newnode->prev = last;
}

//5.Insert Node at a given position
void InsertAfterPosition(Node* &head, int position, int val)
{
    //Insert at start position
    if(position == 1)
    {
        InsertAthead(head, val);
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

    //create a new node
    Node* newnode = new Node(val);

    //Insert newnode after previous
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
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
        head->prev = NULL;
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
        if(curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{
    // Node* head = new Node(10);

    Node* head = NULL;
    InsertAthead(head, 100);
    InsertAthead(head, 15);
    InsertAthead(head, 20);
    InsertAtTail(head, 58);
    InsertAtTail(head, 2000);
    display(head);

    // InsertAfterPosition(head, 1, 458);
    deletenode(head, 5);
    display(head);
    
    return 0;
}