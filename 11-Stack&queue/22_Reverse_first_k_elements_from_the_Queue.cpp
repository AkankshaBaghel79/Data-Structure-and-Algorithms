#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

queue<int> modifyQueue(queue<int> q, int k) {

    //step 1 : fetch first k elements from the queue and push it into stack
    stack<int> s;
    for(int i = 0;i<k;i++)
    {
        int top = q.front();
        q.pop();
        s.push(top);
    }

    //step 2: push those elements from stack to queue
    while(!s.empty()) {
        int top  = s.top();
        s.pop();
        q.push(top);
    }
    //step 3: fetch first (n-k) elements from queue and push it into queue again
    for(int i = 0;i<q.size() - k;i++)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }

    return q;
}

int main()
{
    int n,k;
    cout<<"n : ";
    cin>>n;
    cout<<"k : ";
    cin>>k;

    queue<int> q;
    cout<<"Enter elements : "<<endl;
    while(n-- > 0)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<"size: "<<q.size()<<endl;

    queue<int> ans = modifyQueue(q, k);
    cout<<"Reversal : ";
    while (!ans.empty())
    {
        int val = ans.front();
        ans.pop();
        cout<<val<<" ";
    }
    cout<<endl;
    
    
    return 0;
}