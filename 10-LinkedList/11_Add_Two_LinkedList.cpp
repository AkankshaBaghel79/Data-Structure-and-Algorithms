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

//Add two given linked list
//Time complexity --> O(max(l1,l2));
//space complexity --> O(n) , n represent the size of the new linked list

Node* Reverse(Node* head)
{
    Node* curr = head;
    Node* pre = NULL;
    Node* next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    
    return pre;
}
//Function to add two numbers represented by linked list.
Node* addTwoLists(Node* first, Node* second)
{
    // code here
    //Step 1 : Reverse both of the linked lilsts
    
    first = Reverse(first);
    second =Reverse(second);
    
    
    //Step  2 : Add both of the linked list
    int sum = 0;
    int carry = 0;
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    
    while(first != NULL || second != NULL || carry)
    {
        sum = 0;
        if(first != NULL)
        {
            sum+= first->data;
            first = first->next;
        }
        if(second != NULL)
        {
            sum += second->data;
            second = second->next;
        }
        
        sum = sum + carry;
        carry = sum/10;
        
        Node* newnode = new Node(sum%10);
        temp->next = newnode;
        temp = temp->next;
        
    }
    
    Node* ans = Reverse(dummy->next);
    
    return ans;
}

int main()
{

    Node* n1 = new Node(2);
    Node* n2 = new Node(4);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;
   

    Node* m1 = new Node(5);
    Node* m2 = new Node(6);
    Node* m3 = new Node(7);
    Node* m4 = new Node(9);

    m1->next = m2;
    m2->next = m3;
    m3->next = m4;

    Node* answer = addTwoLists(n1, m1);
    display(answer);
    return 0;
}