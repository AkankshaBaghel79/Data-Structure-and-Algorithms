#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool PossibleSol(vector<int> &arr,int k, int mid)
{
    int PainterCount = 1;
    int Time = 0;

    for(int i = 0;i<arr.size();i++)
    {
        if(Time + arr[i] <= mid)
        {
            Time += arr[i];
        }
        else{
            PainterCount++;
            if(PainterCount > k || arr[i] > mid)
            {
                return false;
            }
            Time = arr[i];
        }
    }
    return true;
}

int PaintersPartition(vector<int> &arr, int k)
{
    int s = 0;
    int ans = -1;
    int sum = 0;

    for(int i = 0;i<arr.size();i++)
    {
        sum = sum + arr[i];
    }

    int e = sum;
    int mid = s + ( e-s )/2;

    while( s <= e)
    {
        if(PossibleSol(arr, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return mid;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> arr;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<PaintersPartition(arr,k)<<endl;
    }

    
    
    return 0;
}

// Input:
// 4
// 4 2
// 5 5 5 5
// 4 2
// 10 20 30 40
// 2 2
// 48 90
// 4 2
// 1 2 3 4
// output:
// 10
// 60
// 90
// 6