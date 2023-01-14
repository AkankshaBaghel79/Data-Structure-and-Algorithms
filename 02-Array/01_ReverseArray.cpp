#include<iostream>
using namespace std;
// An Array is a data structure which is used to store blocks of information in contiguous memory allocation.

void Reverse(int arr[],int n)
{
    for(int i = n-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    // cout<<"Enter the num: \n";
    cin>>n;
    int array[n];
    // cout<<"Enter the elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    Reverse(array, n);
    
    return 0;
}