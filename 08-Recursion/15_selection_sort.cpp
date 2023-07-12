#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void selection(int *arr, int n)
{
    //base case
    if(n == 0 || n == 1)
    {
        return;
    }


    //processing
    int mini = INT_MAX;
    int index = 0;

    for(int i = 0;i<n;i++)
    {
        if(arr[i] < mini)
        {
            index = i;
            mini = arr[i];
        }
    }

    swap(arr[0], arr[index]);

    //recursive call

    selection(arr+1, n-1);
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
    selection(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}