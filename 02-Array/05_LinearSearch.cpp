// Linear Search in array in c++
#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return (i+1);
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the element to be searched : ";
    cin>>key;

    int result=linearsearch(arr,n,key);
    cout<<result;
    return 0;
}