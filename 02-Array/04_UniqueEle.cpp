#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int unique(int arr[],int size)
{
    int ans = 0;
    for(int i = 0;i<size;i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n+10];

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<unique(arr,n);
    return 0;
}