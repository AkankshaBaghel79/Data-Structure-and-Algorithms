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

//Check whether the linked List is pallindrome or not


Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}
bool checkPallindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseList(slow->next);
    Node* dummy = head;
    slow = slow->next;

    while(slow != NULL)
    {
        if(dummy->data != slow->data)
        {
            return false;
        }

        dummy = dummy->next;
        slow = slow->next;
    }

    return true;

}

//Approach 2 : (i) Create an array (ii) Copy ll content into the array (iii) write logic to check the pallindrome or not
//Time complexity : O(N)
//space complexity : O(N)
bool check(vector<int> arr)
{
    int i = 0;
    int j = arr.size() - 1;
    
    while(i<=j)
    {
        if(arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
    
}

bool isPalindrome(Node *head)
{
    //Your code here
    Node* temp = head;
    vector<int> arr;
    int i = 0;
    int count = 0;
    
    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
        i++;
        count++;
    }
    
    bool ans = check(arr);
    return ans;
}

int main()
{
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(30);
    Node* n5 = new Node(10);
    Node* n6 = new Node(10);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    if(isPalindrome(n1))
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}