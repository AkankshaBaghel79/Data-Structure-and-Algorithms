#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool isSorted(int *arr, int n)
{
    //base case

    if(n == 0 || n == 1)
    {
        return true;
    }

    //processing

    if(arr[0] > arr[1])
        return false;
    
    else{
        bool ans = isSorted(arr+1, n-1);
        return ans;
    }
}


int main()
{
    int arr[] = {5,41,56,100,222};
    int size = 5;

    bool ans = isSorted(arr, size);
    if(ans)
    {
        cout<<"Array is Sorted"<<endl;
    }   
    else{
        cout<<"Array is not sorted"<<endl;
    }
      
    
    return 0;
}