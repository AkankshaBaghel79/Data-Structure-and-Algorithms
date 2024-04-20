#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int findmincost(string s) {

    if(s.length()%2 != 0)
    {
        return -1;
    }

    //1. Initialize a stack, such that it contains only invalid brackets.
    stack<int> st;

    for(int i = 0;i<s.length();i++) {
        //if closing braket, push it
        if(s[i] == '{') {
            st.push(s[i]);
        }
        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    //now the stack only contain invalid brackets
    int openbracket = 0, closebracket = 0;

    while(!st.empty()) {
        if(st.top() == '{') openbracket++;
        else closebracket++;

        st.pop();
    }

    int ans = (openbracket+1)/2 + (closebracket + 1)/2;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--) {
        string s;
        cin>>s;

        cout<<"Cost : "<<findmincost(s)<<endl;
    }
    
    return 0;
}