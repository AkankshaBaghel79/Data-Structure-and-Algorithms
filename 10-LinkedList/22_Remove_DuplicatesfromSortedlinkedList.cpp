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


//From singly linked List
Node* RemoveDuplicates(Node* head)
{
    if(head == NULL || head->next==NULL)
    {
        return head;
    }

    Node* curr = head;
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* next = curr->next->next;
            Node* tobedeleted = curr->next;
            delete tobedeleted;
            curr->next = next;
        }
        else{
            curr = curr->next;
        }
    }

    return head;
}


int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(10);
    Node* n3 = new Node(10);
    Node* n4 = new Node(40);
    Node* n5 = new Node(40);
    Node* n6 = new Node(60);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;


    display(n1);
    Node* ans = RemoveDuplicates(n1);
    display(n1);



    // delete n1;
    // delete n2;
    // delete n3;
    // delete n4;
    // delete n5;
    // delete n6;

    return 0;
}