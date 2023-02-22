#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool checkInclusion(string s1, string s2)
{
    vector<int> v1(26,0);
    vector<int> v2(26,0);

    int window = s1.length();
    int len = s2.length();

    int left = 0, right = 0;

    if(len < window)
    {
        return false;
    }

    //Creating the first window and also creating the v1 vector for comparison 
    while(right < window)
    {
        v1[s1[right] - 'a']++;
        v2[s2[right] - 'a']++;
        right++;
    }
    right--;

    while(right < len)
    {
        if(v1 == v2)
        {
            return true;
        }
        right++;

        if(right != len)
        {
            v2[s2[right] - 'a']++;
        }

        v2[s2[left] - 'a']--;
        left++;
    }

    return false;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    if(checkInclusion(s1,s2))
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    
    return 0;
}