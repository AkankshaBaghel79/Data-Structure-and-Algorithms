// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

#include<bits/stdc++.h>
using namespace std;

#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

//Approach 1 : Brute force , The brute force approach involves creating a new copy of each node while traversing the original list. Then, after copying all nodes, iterate through the copied list again to set the random pointers based on the original list's random pointers.

/*Time Complexity:
Creating the copy of nodes: O(n), where n is the number of nodes in the linked list.
Setting the next and random pointers for copied nodes: O(n), as you traverse through the entire linked list and set the pointers based on the hash map.
Overall, the time complexity is O(n).

Space Complexity:
Hash map: O(n), where n is the number of nodes in the linked list. In the worst case, you would need to store each original node and its corresponding copied node.
Overall, the space complexity is O(n) due to the hash map.
*/

Node* copyRandomList(Node* head) 
{
    if(!head)
    {
        return NULL;
    }

    unordered_map<Node*, Node*> nodeMap;
    
    
    // First pass: Create a copy of each node
    Node* curr = head;
    while(curr)
    {
        nodeMap[curr] = new Node(curr->val);
        curr = curr->next;
    }
    
    
    // Second pass: Set next and random pointers for the copied nodes
    curr = head;
    while(curr)
    {
        nodeMap[curr]->next = nodeMap[curr->next];  //nodeMap[curr] gives us the cloned node corresponding to the current node in the original list, and nodeMap[curr->next] gives us the cloned node corresponding to the next node in the original list. This line establishes the same next relationships in the cloned list as in the original list.
        nodeMap[curr]->random = nodeMap[curr->random]; //gives you the cloned node corresponding to the random node of the current original node.
        curr = curr->next;
    }

    /*Here's a breakdown of how it works:
        nodeMap[curr] gives you the cloned node corresponding to the current original node (curr).
        nodeMap[curr->next] gives you the cloned node corresponding to the next node of the current original node.
        nodeMap[curr->random] gives you the cloned node corresponding to the random node of the current original node.
   */


    return nodeMap[head];
    
}

//Approach 2 : optimized approach
Node* clonelist(Node* head)
{
    Node* front = head;
    Node* itr = head;

    // Step 1 : make copy of each node, and link them together side-by-side in a single list.

    while(itr)
    {
        front = itr->next;
        Node* copy = new Node(itr->val); // creating deep value;
        itr->next = copy;
        copy->next = front;
        itr = front;
    }

    //Step 2 : assign random pointers for the copy nodes.

    itr = head;
    while(itr)
    {
        if(itr->random != NULL)
        {
            itr->next->random = itr->random->next;
        }
        itr = itr->next->next;
    }


    //Step 3 : Restore the original list, and extract the copy list.

    itr = head;
    Node* dummy =  new Node(0);
    Node* copy = dummy;
    

    while(itr)
    {
        front = itr->next->next;

        //extract the copy
        copy->next = itr->next;

        //restore the original list
        itr->next = front;

        copy = copy->next;
        itr = front;
    }


    return dummy->next;


}

void display(Node* head)
{
    Node* current = head;
    while (current) {
        cout << "Value: " << current->val;
        if (current->random) {
            cout << ", Random: " << current->random->val;
        }
        cout << endl;
        current = current->next;
    }
}

int main() {
    // Create the original linked list with random pointers
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = node3;
    node2->random = node1;
    node3->random = node5;
    node4->random = node2;
    node5->random = node4;

    // Calling the copyRandomList function
    cout<<"Through Brute force : "<<endl;
    Node* copiedHead = copyRandomList(node1);
    display(copiedHead);

    // cout<<"Through optimized approach : "<<endl;
    // Node* clone = clonelist(node1);
    // display(clone);


    return 0;
}
