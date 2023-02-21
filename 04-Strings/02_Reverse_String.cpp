#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void reverseString(vector<char>& s) 
{
    int l = 0;
    int e = s.size()-1;

    while(l < e)
    {
        swap(s[l++], s[e--]);
    }
}

int main()
{
    vector<char> s;

    int n;
    cin>>n;
    cout<<"Enter the string : "<<endl;
    for(int i = 0;i<n;i++)
    {
        char x;
        cin>>x;
        s.push_back(x);
    }
    
    

    reverseString(s);
    cout<<"Reverse of String is : "<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    
    
    return 0;
}