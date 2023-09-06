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

Node* ReverseKgroups(Node* head, int k)
{
    //Step 1 : find the length of the linked list
    int count = getLength(head);

    Node* dummy = new Node();
    dummy->next = head;

    Node* curr = dummy, *prev = dummy, *next = dummy;

    while(count >= k)
    {
        curr = prev->next;
        next = curr->next;
        for(int i = 1;i<k;i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        prev = curr;
        count-=k;

    }

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

    display(n1);
    int k;
    cin>>k;
    cout<<"Reversing in "<<k<<" Groups: "<<endl;
    Node* ans = ReverseKgroups(n1, k);
    display(ans);

    return 0;
}