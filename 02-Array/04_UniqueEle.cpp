// Find the unique element in an array where every element appears twice execept one element.
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int unique(int arr[],int size)
{
    //Linear search method
    //Time complexity : O(N);
    // int ans = 0;
    // for(int i = 0;i<size;i++)
    // {
    //     ans = ans ^ arr[i];
    // }
    // return ans;

    //Binary Search approach
    //Time complexity : O(logn)

    int l = 0;
    int r = size - 1;

    while(l<r)
    {
        int mid = (l+r)/2;
        if(mid % 2 != 0)
           mid --;

        if(arr[mid] != arr[mid+1])
        {
            r = mid;
        }
        else{
            l = mid+2;
        }
    }

    return arr[l];
  
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

// output:
// 5
// 1 2 1 2 5 --->> 5