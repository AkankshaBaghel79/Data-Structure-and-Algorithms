#include<bits/stdc++.h>
using namespace std;

#define endl '\n';

string longestCommonPrefix(vector<string> str)
{
    if(str.empty())
    {
        return "";
    }

    string shortest = str[0];

    for(auto s : str)
    {
        if(s.length() < shortest.length())
        {
            shortest = s;
        }
    }

    for(int i = 0;i<shortest.length();i++)
    {
        char ch = shortest[i];
        for(auto s : str)
        {
            if(s[i] != ch)
            {
                return shortest.substr(0,i);
            }
        }
    }

    return shortest;
}


int main()
{
    vector<string> strs = {"flower","flow","flight"};

    string prefix = longestCommonPrefix(strs);
    cout<<prefix<<endl;
    
    return 0;
}