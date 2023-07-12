#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void bubble(int *arr, int n)
{
    //base case
    if(n==0 || n == 1)
    {
        return;
    }

    //processing
    for(int i = 0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    //recursive call
    bubble(arr, n-1);
}


int main()
{
    int arr[100];
    int n;
    cin>>n;

    cout<<"Input the array : "<<endl;

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<< "After sorting : "<<endl;
    bubble(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}