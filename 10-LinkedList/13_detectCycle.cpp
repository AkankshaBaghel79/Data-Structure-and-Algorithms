//Linked List cycle
#include<bits/stdc++.h>
#include <unordered_set>
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

//Approach 1 : using Hashing
//time complexity -- > O(n)
//space complexity --> O(n)
bool hasCycle(Node* n)
{
    unordered_set<Node*> node;

    while(n)
    {
        if(node.find(n) == node.end())
        {
            node.insert(n);
            n = n->next;
        }
        else{
            return true;
        }
        
    }

    return false;
}

//Approach 2 : using fast and slow pointer
//Time complexity --> O(N)
//space complexity --> O(1)
bool hascycle2(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            return true;
        }
    
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
    n6->next = n5;

    if(hascycle2(n1))
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}