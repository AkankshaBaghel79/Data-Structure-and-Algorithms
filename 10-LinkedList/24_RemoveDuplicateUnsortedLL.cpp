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

//Approach 1: put the curr at the first element and traverse the whole linked list  fo find whether the element is present or not
//Time complexity : O(N^2)
//Space complexity : O(1)
Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* curr = head;
    Node* temp = head;
    // int val = curr->data;

    while(temp!= NULL)
    {
        curr = temp;
        int val = curr->data;
        while(curr->next != NULL)
        {
            if(val == curr->next->data)
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

        temp = temp->next;
    }

    return head;
}

//Approach 2 : use hashmap or hasSet
//Time complexity : O(N)
//Space complexity : O(N)

Node *removeDuplicates2(Node *head)
{
    unordered_map<int, bool> mp;
    Node* dummy = new Node(0);
    Node* newhead = dummy;

    while(head != NULL)
    {
        int val = head->data;
        if(!mp[val])
        {
            mp[val] = true;
            Node* newNode = new Node(val);
            dummy->next = newNode;
            dummy = dummy->next;
        }
        head = head->next;
    }

    return newhead->next;
} 

//Approach 3 : Two step solution (i) To sort the ll (ii) Remove duplicate
//Time complexity : O(nlogn)
//Space complexity : O(1)

int main()
{

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(10);
    Node* n4 = new Node(20);
    Node* n5 = new Node(30);
    Node* n6 = new Node(10);
    Node* n7 = new Node(20);
    Node* n8 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    display(n1);
    Node* ans = removeDuplicates2(n1);
    display(ans);



    // delete n1;
    // delete n2;
    // delete n3;
    // delete n4;
    // delete n5;
    // delete n6;

    return 0;
}