#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int partition(int arr[], int s, int e)
{
    //take a pivot
    int pivot = arr[s];
    int count = 0;

    //count all elements <pivot
    for(int i = s + 1;i<=e;i++)
    {
        if(arr[i] <= pivot)
        {
            count++;
        }
    }

    //find the pivotIndex and swap it
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    //satisfy the condition 

    int i = s;
    int j = e;


    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }

    //1. Partition

    int p = partition(arr,s,e);

    //Left part sort using recursion
    quicksort(arr,s,p-1);

    //right part sort using recursion
    quicksort(arr,p+1,e);
}


int main()
{
    int n;
    cin>>n;
    int arr[100];

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}