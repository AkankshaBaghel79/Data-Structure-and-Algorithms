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

//Approach 1 : Iterative Approach
//Time complexity : O(n1+m1), where n1 and m1 is the length of the two linked list
//space complexity : O(1) , it uses constant space

Node* mergeTwoSortedList(Node* h1, Node* h2)
{
    Node* dummy = new Node();
    Node* curr = dummy;

    while(h1 && h2)
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

//Approach 2: Recursive solution
//Time complexity : O(n1+m1), where n1 and m1 is the length of the two linked list
//space complexity : O(n1+m1) , The recursive call stack can grow to accommodate the maximum depth of recursion, which is the sum of the lengths of both linked lists.
Node* mergeTwoSortedList2(Node* h1, Node* h2)
{
    if(!h1)
    {
        return h2;
    }
    if(!h2)
    {
        return h1;
    }

    Node* merge;
    if(h1->data < h2->data)
    {
        merge = h1;
        merge->next = mergeTwoSortedList2(h1->next, h2);
    }
    else{
        merge = h2;
        merge->next = mergeTwoSortedList2(h1, h2->next);
    }

    return merge;
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

    Node* m1 = new Node(15);
    Node* m2 = new Node(25);
    Node* m3 = new Node(35);
    Node* m4 = new Node(45);
    Node* m5 = new Node(55);
    Node* m6 = new Node(65);

    m1->next = m2;
    m2->next = m3;
    m3->next = m4;
    m4->next = m5;
    m5->next = m6;

    display(n1);
    display(m1);

    Node* answer = mergeTwoSortedList2(n1,m1);
    cout<<endl;
    cout<<endl;

    display(answer);

    return 0;
}