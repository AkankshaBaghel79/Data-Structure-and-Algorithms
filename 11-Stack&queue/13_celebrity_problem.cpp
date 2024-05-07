#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool knows(vector<vector<int> >& M, int n, int a, int b)
{
    if(M[a][b] == 1) return true;
    else return false;
}

int celebrity(vector<vector<int> >& M, int n) {

    //1. put all the elements in the stack
    stack<int> st;
    for(int i = 0;i<n;i++)
    {
        st.push(i);
    }

    //2. Remove two elements from the stack and compare them
    while(st.size() > 1) {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        //now compare them who knows whom
        if(knows(M, n, a, b)) {
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    //Now the stack contain only one elment, we have to verify it whether that element is the potential celebrity or not.

    int ans = st.top();
    int zerocount = 0;
    for(int i = 0;i<n;i++)
    {
        if(M[ans][i] == 0) zerocount++;
    }

    if(zerocount != n)
    {
        return -1;
    }

    int onecount  = 0;
    for(int i = 0;i<n;i++)
    {
        if(M[i][ans] == 1) onecount++;
    }

    if(onecount != n-1)
    {
        return -1;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> vec(n, vector<int> (n,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }


    cout<<"Celebrity is : "<<" "<<celebrity(vec, n);
    
    return 0;
}