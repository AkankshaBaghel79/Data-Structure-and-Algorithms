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

int getlength(Node* head)
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

Node *findMiddle(Node *head)
{
    //Optimized approaach using slow and fast pointer
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    if(head->next->next == NULL)
    {
        return head->next;
    }


    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;

    //Brute force
    // int len = getlength(head);
    // int ans = len/2;

    // Node* temp = head;

    // while(ans--)
    // {
    //     temp = temp->next;
    // }

    // return temp;
}

int main()
{
    Node* head = new Node(10);
    Node* Second = new Node(20);
    // Node* third = new Node(30);
    // Node* four = new Node(40);
    // Node* five = new Node(50);

    head->next = Second;
    // Second->next = third;
    // third->next = four;
    // four->next = five;
    display(head);

    cout<<"Middle of node : "<<endl;
    Node* ans = findMiddle(head);
    display(ans);
    
    return 0;
}