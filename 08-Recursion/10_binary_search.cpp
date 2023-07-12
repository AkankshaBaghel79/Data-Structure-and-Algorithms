#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void printarr(int *arr, int s, int e)
{
    for(int i = s;i<=e;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binarySearch(int *arr, int s, int e, int k)
{
    printarr(arr,s,e);
    //Base case
    // When element is not found

    if(s>e)
    {
        return false;
    }

    int mid = s + (e-s)/2;
    // cout<<"Mid : "<<arr[mid]<<endl;

    //when element is found
    if(arr[mid] == k)
    {
        return true;
    }
    else if(arr[mid] < k)
    {
        return binarySearch(arr, mid + 1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1,k);
    }
}


int main()
{
    int arr[] = {1,2,5,8,9,11,16,22,110,589,599,600};
    int size = 12;
    int key = 599;

    bool ans = binarySearch(arr, 0, 11, key);

    if(ans)
    {
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }

    
    return 0;
}