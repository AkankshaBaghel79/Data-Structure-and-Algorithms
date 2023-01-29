//Insertion Sort--> stable sort
//Time Complexity --> worst case and average case : O(n2) and for best case-->O(n)
//space Complexity --> O(1)

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i = 1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    for(auto x: arr)
    {
        cout<<x<<" ";
    }

    return 0;
}