#include<bits/stdc++.h>
using namespace std;

#define endl "\n";


class Node{

    public:
    int data;
    Node* next;

    Node(int data = 0)
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
//Approach 1--> Brute Force
//Remove Nth Node from the end of the linked list
Node* RemoveNthNode(Node* head, int n)
{
    int len = getLength(head);
    int value = len - n;

    //case1 : if the node to be deleted is first node

    if (n >= len || value == 0)
    {
        Node* temp = head;
        head = head->next;

        //memory free from start node
        temp->next = NULL;
        delete temp;
        return head;
    }


    int count = 1;
    Node* dummy = head;
    while (count < value) {
        dummy = dummy->next;
        count++;
    }
    
    Node* nodeToDelete = dummy->next;
    dummy->next = dummy->next->next;
    delete nodeToDelete;

    return head;
}

//Approach 2 : optimised
Node* RemoveNthNode2(Node* head, int n)
{
    Node* dummy  = new Node();
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;

    for(int i = 0;i<n;i++)
    {
        fast = fast->next;
    }

    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
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

    int n;
    cin>>n;

    display(n1);
    // cout<<getLength(n1)<<endl;



    cout<<"After removing "<<n<<"th node from the end"<<endl;
    // Node* answer = RemoveNthNode(n1,n);
    Node* answer = RemoveNthNode2(n1,n);
    display(answer);

}