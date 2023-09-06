#include<bits/stdc++.h>
#include<unordered_map>
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

void splitCircularList(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head)
    {
        fast = fast->next;
        if(fast->next != head)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node* newhead = slow->next;
    slow->next = head;
    fast->next = newhead;
}

int main()
{

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
    n6->next = n1;

    splitCircularList(n1);



    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}