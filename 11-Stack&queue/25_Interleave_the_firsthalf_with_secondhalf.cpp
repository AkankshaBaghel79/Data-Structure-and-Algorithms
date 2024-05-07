#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Approach 1 : using queue
vector<int> rearrangeQueue(queue<int> &q) {
   queue<int> q2;
   vector<int> ans;
   int size = q.size();

   //1.fetch first half of the queue element and push it into the new queue
   for(int i = 0;i<size/2;i++)
   {
        q2.push(q.front());
        q.pop();
   }

   while(!q2.empty()) {
       ans.push_back(q2.front());
       q2.pop();
       ans.push_back(q.front());
       q.pop();
   }

   return ans;
}

//Approach 2: using stack
vector<int> usingstack(queue<int> &q) {
    stack<int> s;
    vector<int> ans;
    int size = q.size();
        
    for(int i = 0;i<(size/2);i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    for(int i = 0;i<size/2;i++) {
        q.push(q.front());
        q.pop();
    }
    
    for(int i = 0;i<size/2;i++) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        int val = s.top();
        ans.push_back(val);
        s.pop();
        int val2 = q.front();
        ans.push_back(val2);
        q.pop();
    }
    
    return ans;
}

int main()
{
    queue<int> q;
    int n;
    cin>>n;

    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }

    vector<int> ans = usingstack(q);
    cout<<"Answer : "<<endl;
    for(int i = 0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}