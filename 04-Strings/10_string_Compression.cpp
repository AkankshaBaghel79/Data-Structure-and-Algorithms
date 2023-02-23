#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int compress(vector<char>& chars) 
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while(i<n)
    {
        int j = i+1;
        while(j < n && chars[i] == chars[j])
        {
            j++;
        }

        chars[ansIndex++] = chars[i];
        int count = j - i;

        if(count > 1)
        {
            string cnt = to_string(count);
            for(char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    for(int i = 0;i<ansIndex;i++)
    {
        cout<<chars[i]<<" ";
    }
    cout<<endl;

    return ansIndex;        
}

int main()
{
    int n;
    cin>>n;

    vector<char> ch;
    for(int i = 0;i<n;i++)
    {
        char c;
        cin>>c;
        ch.push_back(c);
    }

    cout<<compress(ch);
    
    
    return 0;
}

/*
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/