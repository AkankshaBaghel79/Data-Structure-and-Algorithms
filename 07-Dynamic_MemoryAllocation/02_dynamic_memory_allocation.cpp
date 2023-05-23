#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int getsum(int *arr, int n)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}


int main()
{
    char ch;
    // cout<<sizeof(ch)<<endl; //1 byte
    char *a;
    // cout<<sizeof(a)<<endl;// 8 byte

    char *cha = new char; //total 9 bytes are used in making it

    //fixed sized array
    int arr1[100];

    //variable sized array
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<getsum(arr, n);

    return 0;
}