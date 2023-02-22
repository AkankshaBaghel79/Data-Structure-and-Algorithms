//Maximum Ocurring Character
/*Given a string str. The task is to find the maximum occurring character in the string str. If more than one character 
occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

char getMaxOccuringChar(string str)
{
    int arr[26] = {0};
    int number = 0;

    for(int i = 0;i<str.length();i++)
    {
        char ch = str[i];
        number = ch - 'a';
        arr[number]++;
    }

    int ans = -1;
    int mx = INT_MIN;

    for(int i =0;i<26;i++)
    {
        if(mx < arr[i])
        {
            mx = arr[i];
            ans = i;
        }
    }

    char result = 'a' + ans;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;

    cout<<getMaxOccuringChar(s);
    
    return 0;
}