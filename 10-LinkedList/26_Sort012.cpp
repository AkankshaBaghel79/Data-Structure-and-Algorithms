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

//Approach 1: Traverse the whole linked list and then count 0,1 and 2. After this replace the value in the original linked list accordingly
//Time complexity : O(N)
//space complexity : O(1)

Node* sortList(Node *head){

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    int ZeroCount = 0;
    int oneCount = 0;
    int twocount = 0;

    Node* temp =  head;
    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            ZeroCount++;
        }
        else if(temp->data == 1)
        {
            oneCount++;
        }
        else{
            twocount++;
        }
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL)
    {
        if(ZeroCount)
        {
            temp->data = 0;
            ZeroCount--;
        }
        else if(oneCount)
        {
            temp->data = 1;
            oneCount--;
        }
        else{
            temp->data = 2;
            twocount--;
        }

        temp = temp->next;
    }

    return head;
}

//Approach 2 : it groups all the nodes with the same value together in their respective sublists, and then it simply concatenates these sublists to obtain the sorted list. The algorithm works in a single pass through the original list, making it efficient for sorting linked lists with a small number of distinct values.
//Time complexity : O(N)
//space complexity : O(1)

Node* sortlist2(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* ZeroHead = new Node(0);
    Node* zero = ZeroHead;
    Node* OneHead = new Node(0);
    Node* one = OneHead;
    Node* twoHead = new Node(0);
    Node* two = twoHead;

    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if(curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else{
            two->next = curr;
            two = two->next;
        }

        curr = curr->next;
    }

    if(OneHead->next != NULL)
    {
        zero->next = OneHead->next;
        one->next = twoHead->next;
        two->next = NULL;
    }
    else if(twoHead->next != NULL)
    {
        zero->next = twoHead->next;
        two->next = NULL;
    }
    else{
        zero->next = NULL;
    }

    return ZeroHead->next;

}

int main()
{

    Node* n1 = new Node(2);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);
    Node* n4 = new Node(2);
    Node* n5 = new Node(2);
    Node* n6 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;


    display(n1);
    Node* ans = sortlist2(n1);
    display(ans);



    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}