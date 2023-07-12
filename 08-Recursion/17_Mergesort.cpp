#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Approach 1 : using array and copy the values

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) >> 1;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}


void mergeSort(vector<int>& arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)>>1;

    //left part sort karna h 
    // cout<<"currently checking index "<<s<<" "<<mid<<endl;
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    // cout<<"currently checking index "<<mid+1<<" "<<e<<endl;
    mergeSort(arr, mid+1, e);

    //merge
    // cout<<"Merging the part : "<<s<<" "<<e<<endl;
    merge(arr, s, e);

}

void printarray(vector<int>& arr, int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // int arr[100];
    // for(int i = 0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }

    mergeSort(arr,0,n-1);
    printarray(arr,n);
    
    return 0;
}