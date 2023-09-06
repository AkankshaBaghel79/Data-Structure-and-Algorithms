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

//*************Detect Cycle***********
//Approach 1 : using Map 
//S.C = O(N)
//T.c = O(N)

bool detectcyle(Node* head)
{
    Node* temp = head;
    map<Node*, bool> visited;

    if(head == NULL)
    {
        return false;
    }

    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

//Approach 2: Using Flyod's cycle detection
//T.C = O(N)
//S.C = O(1)

Node* flyodscycle(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node* startingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersect = flyodscycle(head);
    if(intersect == NULL)
    {
        return NULL;
    }
    Node* slow = head;

    while(slow != intersect)
    {
        slow = slow->next;
        intersect = intersect->next;
    }

    return slow;
}

void RemoveLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* startOfLoop = startingNode(head);
    if(startOfLoop == NULL)
    {
        return head;
    }
    
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
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
    n5->next = n3;

    // cout<<flyodscycle(n1)<<endl;

    // Node* loop = startingNode(n1);
    // cout<<"Loop start at : "<<loop->data<<endl;

    RemoveLoop(n1);
    display(n1);






    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}