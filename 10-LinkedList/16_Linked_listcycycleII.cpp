#include<bits/stdc++.h>
#include<unordered_set>
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

Node* detectcycle1(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    unordered_set<Node*> node;
    while(head)
    {
        if(node.find(head) != node.end())
        {
            return head;
        }
        else{
            node.insert(head);
            head = head->next;
        }
    }

    return NULL;
}

//Approach 2 : using fast and slow pointer
//Time complexity : O(N)
//space Complexity : O(1)

Node* detectCycle(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    Node* entry = head;

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            while(entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL;
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
    n6->next = n4;

    Node* ans = detectCycle(n1);
    cout<<ans<<endl;

    return 0;
}