#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool checking(string s, int i)
{
    int n = s.length();
    // cout<<"Currently at : "<<s[i]<<" "<<s[n-i-1]<<endl;
    
    if(i > n-i-1)
    {
        return true;
    }

    if(s[i] != s[n-i-1])
    {
        return false;
    }
    i++;

   return checking(s,i);
    // return ans;
}


int main()
{
    string s;
    cin>>s;
    cout<<"Pallindrome : "<<checking(s,0);
    
    return 0;
}