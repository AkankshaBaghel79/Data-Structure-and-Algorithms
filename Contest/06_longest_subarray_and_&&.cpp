#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    //Write your code here.
    int len = arr.size();
    int i = 0;
    vector<int> result;
    

    while(q--)
    {
        int value = queries[i];
        int ans = arr[0];

        int j = 0;
        while(ans >= value && j<n)
        {
            j++;
            ans = ans & arr[j];
        }
        result.push_back(j);
        i++;

    }

    return result;
}

int main()
{

    int n,q;
    cin>>n>>q;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<int> queries;
    for(int i = 0;i<q;i++)
    {
        int x;
        cin>>x;
        queries.push_back(x);
    }

    vector<int> ans = bitwiseAnd(n, q, arr, queries);
    
    return 0;
}