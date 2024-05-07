#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Approach 1 : Using stack
queue<int> reverse(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        s.push(front);
    }

    while(!s.empty()) {
        int top = s.top();
        s.pop();
        q.push(top);
    }

    return q;
}

//Approach 2 : using Recursion
void solve(queue<int> &q) {
    //base case
    if(q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();

    solve(q);
    q.push(front);
}
queue<int> Reverse(queue<int> q) {
    solve(q);
    return q;
}

int main()
{
    queue<int> q;
    cout<<"Enter n :"<<endl;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    cout<<"After Reversal :"<<endl;
    queue<int> ans = Reverse(q);

    while(!ans.empty()) {
        int top = ans.front();
        ans.pop();
        cout<<top<<" ";
    }

    return 0;
}