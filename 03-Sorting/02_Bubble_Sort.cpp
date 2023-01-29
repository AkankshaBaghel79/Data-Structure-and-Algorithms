//Bubble sort -- > in this sort we just swap the adjusent elemen, and at the end of each round larger element is placed at
//their right position
//time complexity == O(n^2)(for best, worst, average)
//space Complexity == O(1)

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

    for(int i = 1;i<n-1;i++)
    {
        bool swapped = false;
        for(int j = 0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    for(auto x: arr)
    {
        cout<<x<<" ";
    }

    return 0;
}