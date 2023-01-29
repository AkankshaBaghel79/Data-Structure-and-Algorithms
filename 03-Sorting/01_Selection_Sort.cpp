// Selection sort pick the smallest element and swap it with the bigger element.
// After each round the smaller element is placed at the right position.
//time complexity == O(n^2)(for best, worst, average)
//space Complexity == O(1)
//When the size of the array is small we can use it.

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

    for(int i = 0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex])
               minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }

    for(auto x: arr)
    {
        cout<<x<<" ";
    }
    
    return 0;
}