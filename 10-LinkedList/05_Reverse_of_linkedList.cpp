#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Node{

    public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
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
//Approach 3 recursive
Node* recursiveway(Node* head)
{
    //base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* samllhead = recursiveway(head->next);
    head->next->next = head;
    head->next = NULL;

    return samllhead;
}

void reverselist(Node* &head, Node* curr, Node* prev)
{
    //base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverselist(head, forward, curr);
    curr->next = prev;
}


Node* reverse(Node* &head)
{
    //Appraoch 3------> Another recursive way
    return recursiveway(head);


    //Approach 2 -----> Recursive Approach
    // Node* prev = NULL;
    // Node* curr = head;
    // reverselist(head, curr, prev);
    // return head;
    

    // Approach 1 -------> Iterative Approach
    // if(head == NULL || head->next == NULL)
    // {
    //     return head;
    // }
    // Node* prev = NULL;
    // Node* curr = head;
    // Node* forward = NULL;

    // while(curr != NULL)
    // {
    //     forward = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = forward;
    // }

    // head = prev;
    // return head;

}


int main()
{
    Node* head = new Node(10);
    Node* Second = new Node(20);
    Node* third = new Node(30);

    head->next = Second;
    Second->next = third;
    display(head);

    cout<<"After reversing : "<<endl;
    
    display(reverse(head));


    
    return 0;
}