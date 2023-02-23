#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string removeDuplicates(string s) 
{
    string ans = "";
    for(int i = 0;i<s.length();i++)
    {
        if(ans.empty())
        {
            ans.push_back(s[i]);
        }
        else{
            if(s[i] == ans[ans.length()-1])
            {
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
    }

    return ans;
}


int main()
{
    string s;
    cin>>s;
    cout<<removeDuplicates(s)<<endl;
    
    return 0;
}

/*
Input: s = "abbaca"
Output: "ca"
*/