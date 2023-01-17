#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int BinarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n-1;

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

int main()
{

    int n,key;
    cin>>n>>key;

    int arr[n+10];

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];   
    }

    int index = BinarySearch(arr,n,key);
    cout<<index<<endl;
    
    return 0;
}