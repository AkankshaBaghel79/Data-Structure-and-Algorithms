/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

/*
Example:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool valid (char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9'))
    {
        return 1;
    }
    return 0;
}

char tolowercase(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <='9'))
    {
        return ch;
    }
    else{
        ch = ch -'A' +'a';
        return ch;
    }
}

bool checkPallindrome(string s)
{
    int l = 0;
    int e = s.length()- 1;

    while(l<e)
    {
        if(s[l] != s[e])
        {
            return 0;
        }
        else{
            l++;
            e--;
        }
    }

    return 1;
}

bool isPalindrome(string s)
{
    string temp = "";
    //Take the valid character from the string
    for(int i = 0;i<s.length();i++)
    {
        if(valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    //convert them into lowercase

    for(int i = 0;i<temp.length();i++)
    {
        temp[i] = tolowercase(temp[i]);
    }

    return checkPallindrome(temp);

}

int main()
{
    string s;
    getline(cin, s);

    int ans = isPalindrome(s);

    if(ans)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    
    return 0;
}