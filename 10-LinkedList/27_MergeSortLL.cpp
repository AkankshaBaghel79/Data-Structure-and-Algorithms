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

Node* merge(Node* h1, Node* h2)
{
    if(!h1)
       return h2;
    if(!h2)
       return h1;

    
    Node* dummy = new Node(0);
    Node* curr = dummy;

    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data > h2->data)
        {
            curr->next = h2;
            h2 = h2->next;
        }
        else{
            curr->next = h1;
            h1 = h1->next;
        }

        curr = curr->next;
    }

    if(h1)
    {
        curr->next = h1;
    }
    if(h2)
    {
        curr->next = h2;
    }

    Node* mergeList = dummy->next;
    delete dummy;
    return mergeList;
}

Node* findmid(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* mergesort(Node* head)
{
    //Step  1 : base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    //step 2 : break the linked list into two halves, after finding the mid
    Node* mid = findmid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //step 3: Recursive calls to sort both halves
    left = mergesort(left);
    right = mergesort(right);

    //step 4 : merge the two sorted linked list
    Node* ans = merge(left, right);

    //Return expression
    return ans;
}

int main()
{
    Node* n1 = new Node(20);
    Node* n2 = new Node(20);
    Node* n3 = new Node(10);
    Node* n4 = new Node(40);
    Node* n5 = new Node(70);
    Node* n6 = new Node(50);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    display(n1);
    Node* ans = mergesort(n1);
    display(ans);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}