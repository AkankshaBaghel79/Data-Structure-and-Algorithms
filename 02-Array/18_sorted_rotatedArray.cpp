#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int getPivot(vector<int> arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;

    while(s<e)
    {
        if(arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }

    return s;
}

int BinarySearch(vector<int> arr, int s, int e, int key)
{
    int start = s;
    int end = e;

    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}

int findPosition(vector<int> arr, int n, int k)
{
    int pivot = getPivot(arr, n);

    if(k >= arr[pivot] && k <= arr[n - 1])
    {
        return BinarySearch(arr, pivot, n-1, k);
    }
    else{
        return BinarySearch(arr, 0, pivot - 1, k);
    }
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

    cout<<findPosition(arr, n, k);
    return 0;
}