/* Problem Statement : You are given a string 'S'. Your Task is to check whether the string is pallindrome or not. 
for checking pallindrome , consider alphabets and numbers only and ignore the symbols and whitespaces

Input:
N2 i&nJA?a& jnI2n

output:
Yes
// */

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void Tolower(string &s)
{
    for(int i = 0;i<s.length();i++)
    {
        char ch = s[i];
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            s[i] = ch;
        }
    }
}

bool checkPalindrome(string s)
{
    // Write your code here.
    Tolower(s);
    
    int l = 0;
    int e = s.length()- 1;

    while(l<e)
    {
        
        if(isalnum(s[l]) == 0)
           ++l;
        
        else if(isalnum(s[e]) == 0)
           --e;
        
        else if(s[l] == s[e])
        {
            ++l;
            --e;
        }
        else
        {
            return false;
        }
    }

    return true;

}

int main()
{
   
    string s;
    getline(cin, s);

    int ans = checkPalindrome(s);

    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
