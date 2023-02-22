#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string removeDuplicates(string s) 
{
    int i = 0;

    while((s.length() != 0) && (i+1 < s.length()))
    {
        if(s[i] == s[i+1])
        {
            s.erase(i, 2);
            i = 0;
        }
        else{
            i++;
        }
    }

    return s;
}

int main()
{
    string s;
    cin>>s;
    cout<<removeDuplicates(s)<<endl;
    
    return 0;
}