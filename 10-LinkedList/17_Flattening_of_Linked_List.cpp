#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

//Display linked list without being flattend

void display(Node* head)
{
    cout<<"Linked List : "<<endl;
    Node* current = head;

    while(current)
    {
        Node* currbottom = current;
        while(currbottom)
        {
            cout<<currbottom->data<<" ";
            currbottom = currbottom->bottom;
        }
        cout<<endl;
        current = current->next;
    }
}

//Approach : take two pointer and merge both of the linked list into one
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}

void displat2(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->bottom;
    }
    cout<<endl;
    
}

int main() 
{
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    // display(head);
    
    Node* ans = flatten(head);
    // display(head);

    displat2(head);

    return 0;
}
