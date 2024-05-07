#include <iostream>
#include <stack>
using namespace std;

#define endl "\n";

void solve(stack<int> &st, int x)
{
    //base case
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call
    solve(st, x);
    st.push(num);
}

stack<int> pushAtBottom(stack<int> &st, int x)
{
    solve(st,x);
    return st;
}

int main()
{
    stack<int> st;
    int n,x;
    cin >>n>>x;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    pushAtBottom(st, x);
    cout<<"After adding the element in the end : "<<endl;
    for(int i = 0;i<n+1;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}