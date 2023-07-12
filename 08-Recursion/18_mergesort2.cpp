#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Approach 2 : using indexes and pointer

void merge(vector<int> &arr, int s, int mid, int e)
{
    int l1 = s;
    int l2 = mid+1;

    int temp;

    while(l1<=mid && l2 <= e)
    {
        if(arr[l1] < arr[l2])
        {
            l1++;
        }
        else{
            temp = arr[l1];
            arr[l1] = arr[l2];
            l1++;

            for(int i=l2;i>l1;i--)
            {
                arr[i]=arr[i-1];
            }
            arr[l1] = temp;
            l2++;
        }
    }
}

void mergesort(vector<int>& a, int s, int e)
{
    if(s>=e)
        return;
    else
    {
        int mid=s+(e-s)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);
        merge(a,s,mid,e);
    }
}


void printarray(vector<int>& arr, int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // int arr[100];
    // for(int i = 0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }

    mergesort(arr,0,n-1);
    printarray(arr,n);
    
    return 0;
}