#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

long long appleAndCoupon(int n, int m, vector<int> arr){
    // Write your code here.

    sort(arr.begin(),arr.end());

    int value = n - m ;
    int sum = 0;

    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }

    int ans = sum - arr[value];

    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<appleAndCoupon(n,m,arr)<<endl;


    return 0;
}