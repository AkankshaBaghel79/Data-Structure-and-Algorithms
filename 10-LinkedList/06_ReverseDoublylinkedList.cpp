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

Node* reverseList(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }


    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        prev = curr;
        curr = temp;
    }

    head = prev;

    return head;
    
}


int main()
{
    // Node* head = new Node(10);

    Node* head = NULL;
    InsertAthead(head, 10);
    InsertAthead(head, 20);
    InsertAthead(head, 30);
    InsertAthead(head, 40);
    display(head);

    cout<<"After reversal : "<<endl;
    Node* ans = reverseList(head);
    display(ans);    
    return 0;
}