#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string removeOccurrences(string s, string part) 
{
    while((s.length() != 0) && (s.find(part) < s.length()))  
    {
        s.erase(s.find(part), part.length());
    }

    return s; 
}

int main()
{
    string s;
    string part;
    getline(cin,s);
    getline(cin, part);
    cout<<removeOccurrences(s, part)<<endl;
    
    return 0;
}