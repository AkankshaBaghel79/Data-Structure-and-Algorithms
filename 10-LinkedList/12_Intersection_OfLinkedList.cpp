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

//Approach 1 : Brute force-->we would iterate through each node of one linked list and compare it with each node of the other linked list to find the intersection point.
//Time complexity : O(n*m), Here, n is the length of the first linked list (headA), and m is the length of the second linked list (headB).
Node* intersection(Node* headA, Node* headB)
{
    Node* currA = headA;

    while(currA)
    {
        Node* currB = headB;
        while(currB)
        {
            if(currA == currB)
                return currA;

            currB = currB->next;
        }
        currA = currA->next; 
    }

    return NULL;
}

//Approach 2 : Using Hashing -->In this approach, you create a hash set and traverse the first linked list (headA) to store its nodes in the set. Then, you traverse the second linked list (headB) and check if any node exists in the hash set. If a node exists in the hash set, it means that node is the intersection point.
//Time Complexity--> O(N+M)
//space complexity --> O(N)

Node* intersect2(Node* headA, Node* headB)
{
    unordered_set<Node*> nodes;

    Node* currA = headA;
    while (currA)
    {
        nodes.insert(currA);
        currA = currA->next;
    }

    Node* currB = headB;
    while (currB)
    {
        if(nodes.find(currB) != nodes.end())
        {
            return currB;
        }
        currB = currB->next;
    }

    return NULL;
}

//Approach 3 : Optimized Approach
//Time complexity --> O(2*M)
//space complexity --> O(1)

Node* intersect3(Node* headA, Node* headB)
{
    if(headA == NULL || headB == NULL) return NULL;

    Node* d1 = headA;
    Node* d2 = headB;

    while(d1 != d2)
    {
        d1 = d1 == NULL? headB : d1->next;
        d2 = d2 == NULL? headA : d2->next;
    }

    return d1;
}

int main()
{

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);
    Node* n6 = new Node(60);

    Node* m1 = new Node(70);
    Node* m2 = new Node(80);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    m1->next = m2;
    m2->next = n3;

    Node* answer = intersect3(n1,m1);
    if(!answer)
    {
        cout<<"No intersection found"<<endl;
    }
    else{
        cout<<"Intersection at : "<<answer->data<<endl;
    }

    

    return 0;
}