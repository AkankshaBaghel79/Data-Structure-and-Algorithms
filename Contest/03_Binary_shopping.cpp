#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string binaryShopping(string s, int P)
{
    // Write your code here.  

    string temp = "";

    reverse(s.begin(),s.end());
    int count = 0;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '1' && count != 2)
        {
            temp.push_back('0');
            count++;
        }
        else{
            temp.push_back(s[i]);
        }
    }
    reverse(temp.begin(), temp.end()); 
    
    if(count < 2 && count!=0)
    {
        temp[0] = '1';
    }
    return temp;
}

int main()
{
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;

    cout<<binaryShopping(s,p);
    
    return 0;
}