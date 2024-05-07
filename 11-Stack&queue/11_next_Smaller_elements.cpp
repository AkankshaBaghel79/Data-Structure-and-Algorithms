#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    //1. initialize the stack,  and push -1
    stack<int> st;
    st.push(-1);

    //2. Now traverse the vector from back side.
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--) {
        int curr = arr[i];
        while(st.top()>=curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> vec;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            vec.push_back(x);
        }

        vector<int> ans = nextSmallerElement(vec, n);
        cout<<"OUTPUT : "<<endl;
        for(int i = 0;i<n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}