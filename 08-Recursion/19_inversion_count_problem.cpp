#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Approach 1 : Brute force
//time complexity : O(N)^2

int count (vector<int> arr, int n)
{
    int count = 0;
    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
}

//Approach 2 :  using merge sort

int merge(int* arr, int s, int mid ,int e)
{
    int i = s;
    int j = mid;
    int n = e+1;

    int k = s;
    int count = 0;
    int* temp = new int[n];

    while(i<=mid-1 && j<=e)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }

    while(j<=e)
    {
        temp[k++] = arr[j++];
    }

    for(int i = s;i<=e;i++)
    {
        arr[i] = temp[i];
    }
    delete []temp;

    return count;
}

int mergesort(int* arr, int s, int e)
{
    int count = 0;
    if(s<e){
        int mid = (s+e) >> 1;
        count += mergesort(arr, s, mid);
        count += mergesort(arr, mid+1,e);

        count+= merge(arr, s, mid+1, e);
    }

    return count;
}


int main()
{
    int n;
    cin>>n;

    // vector<int> arr;
    // for(int i = 0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     arr.push_back(x);
    // }

    int arr[100];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    // cout<<count(arr, n);
    cout<<mergesort(arr,0,n-1)<<endl;

    
    return 0;
}