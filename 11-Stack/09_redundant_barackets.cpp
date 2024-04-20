#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '(' || s[i] == '+' ||s[i] == '-' ||s[i] == '*' ||s[i] == '/') st.push(s[i]);
        else {
            if(s[i] == ')') {
                bool ans = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        ans = false;
                    }
                    st.pop();
                }
                if(ans)
                {
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}


int main()
{
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        bool ans = findRedundantBrackets(s);
        if(ans) {
            cout<<"YES ";
        }
        else {
            cout<<"NO ";
        }
    }
    
    return 0;
}