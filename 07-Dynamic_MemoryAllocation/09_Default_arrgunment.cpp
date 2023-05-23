#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void printarr(int* arr, int n, int k = 0)
{
    for(int i = k;i<n;i++){
        cout<<i[arr]<<" ";
    }
    cout<<endl;
}


int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    cout<<"Using default value : "<<endl;
    printarr(arr, size);
    cout<<"without using default : "<<endl;
    printarr(arr, size, 2);
    
    return 0;
}