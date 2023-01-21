#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool PossibleSol(int n, int m, vector<int> &arr, int mid)
{
    int dayCount = 1;
    int ChapterTime = 0;

    for(int i = 0;i<m;i++)
    {
        if(ChapterTime + arr[i] <= mid)
        {
            ChapterTime += arr[i];
        }
        else{
            dayCount++;
            if(dayCount > n || arr[i] > mid)
            {
                return false;
            }
            ChapterTime = arr[i];
        }
    }
    return true;
}

int BookAllocation(int n, int m, vector<int> &arr)
{
    int s = 0;
    int ans = -1;
    int sum = 0;

    for(int i = 0;i<m;i++)
    {
        sum = sum + arr[i];
    }

    int e = sum;
    int mid = s + ( e-s )/2;

    while( s <= e)
    {
        if(PossibleSol(n, m, arr, mid))
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
        int n,m;
        cin>>n>>m;

        vector<int> arr;
        for(int i = 0;i<m;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<BookAllocation(n,m,arr)<<endl;
    }

    return 0;
}

// Input:
// 2
// 3 5
// 1 2 2 3 1
// 4 7
// 2 2 3 3 4 4 1
// output:
// 4
// 6
