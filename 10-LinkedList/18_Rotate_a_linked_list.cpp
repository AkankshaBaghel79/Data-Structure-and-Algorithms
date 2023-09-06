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

//Approach 1 :iteratively rotating the linked list k times. In each iteration, you can move the last node to become the new head, and adjust the pointers accordingly.
//Time Complexity: O(k * n) - We need to iterate through the entire linked list (n nodes) for each rotation (k times).
// Space Complexity: O(1) - We are using a constant amount of extra space for variables.

Node* rotateRight(Node* head, int k) 
{
    if(head == NULL || head->next == NULL || k == 0)   
    {
        return head;
    }

    int len = getLength(head);
    k = k%len;

    while(k--)
    {
        Node* curr = head;
        Node* prev = NULL;

        while(curr->next)
        {
            prev = curr;
            curr = curr->next;
        }
        curr->next = head;
        prev->next = NULL;

        head = curr;
    }

    return head;
}

//Approach 2 : Optimized aaproach
//Time complexity : O(N)
//space complexity : O(1)
Node* rotateListRight(Node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }

    //Find the length of the linked list 
    int len = getLength(head);

    //optimized value of k
    k = k % len;

    Node* curr = head; //tail pointer
    while(curr->next)
    {
        curr = curr->next;
    }

    curr->next = head;

    k = len - k;

    while(k--)
    {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = NULL;

    return head;
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

    Node* ans = rotateListRight(n1,6);
    display(ans);

    return 0;
}