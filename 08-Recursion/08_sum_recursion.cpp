#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int value(int *arr, int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return *arr;
    }

    int ans = *arr+value(arr+1, n-1);
    return ans;

}


int main()
{
    int arr[] = {1,2,3,4,5};
    int size = 5;
    cout<<"SUM : "<<value(arr,size);
    
    return 0;
}