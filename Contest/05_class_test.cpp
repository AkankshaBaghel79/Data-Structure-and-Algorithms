#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int classTest(int n, vector<int> &a, int k) {
    // Write your code here.

    int index = n - k;

    sort(a.begin(), a.end());

    return a[index];
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

    cout<<classTest(n, arr, k);

    return 0;
}