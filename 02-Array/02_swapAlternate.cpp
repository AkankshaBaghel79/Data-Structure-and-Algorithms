#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void printArray(int arr[], int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[], int n)
{
    for(int i = 1;i<n;i+=2)
    {
        swap(arr[i],arr[i-1]);
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    swapAlternate(arr,n);
    printArray(arr,n);
    
    return 0;
}

//5
//1 2 3 4 5 ---> 2 1 4 3 5