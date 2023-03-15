#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int findKthPositive(vector<int>& arr, int k) 
{
    int n = arr.size();
    int start = 0, end = n-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] - (mid + 1) < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start + k;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<findKthPositive(arr, k);
    
    return 0;
}