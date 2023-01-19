//The array contain elements from 1 - (n-1)
//find the duplicate element in the list
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int solution(vector<int> &arr)
{
    int ans = 0;
    for(int i = 0;i<arr.size();i++)
    {
        ans = ans^arr[i];
    }
    for(int i = 1;i<arr.size();i++)
    {
        ans = ans^i;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int>v;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int value = solution(v);
    cout<<value<<endl;

    return 0;
}

// output:
// 6
// 1 2 3 4 4 5 -->> 4