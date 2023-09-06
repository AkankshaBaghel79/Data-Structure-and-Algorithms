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
    Node* temp = head->next;
    int count = 1;

    while(temp != head)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

bool CircularLinked(Node* head)
{
    if(head == NULL)
    {
        return true;
    }

    int len = getLength(head);
    Node* temp = head->next;
    int count = 0;

    while(temp != NULL && temp != head)
    {
        count ++;
        temp = temp->next;
        
        if(count > len)
        {
            return false;
        }
    }

    if(temp == head)
    {
        return true;
    }
    return false;
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
    n6->next = n3;

    if(CircularLinked(n1))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }


    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}