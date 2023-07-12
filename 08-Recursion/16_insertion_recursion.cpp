#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void insertion(int *arr, int n)
{
    //base case
    if(n == 0 || n == 1)
    {
        cout<<"n is 1 now"<<endl;
        return;
    }


    //Sort the first n - 1 elements in the array
    insertion(arr, n-1);
    // cout<<"Value of n : "<<n<<endl;
    int last = arr[n-1];
    int j = n - 2;

    while(j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = last;
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
    insertion(arr,n);

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}