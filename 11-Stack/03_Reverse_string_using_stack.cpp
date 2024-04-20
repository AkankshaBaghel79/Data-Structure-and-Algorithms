#include<iostream>
#include<stack>
using namespace std;

#define endl "\n";


int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    stack<char> rev;

    for(int i = 0;i<s.size();i++)
    {
        char ch = s[i];
        rev.push(ch);
    }

    string ans = "";
    while(!rev.empty())
    {
        char ch = rev.top();
        ans.push_back(ch);
        rev.pop();
    }

    cout<<"Reverse string : "<<ans;



    
    return 0;
}