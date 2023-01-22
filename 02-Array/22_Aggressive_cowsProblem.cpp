#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool possible(vector<int> &stalls, int k, int mid)
{
    int cowcount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i<stalls.size();i++)
    {
        if(stalls[i] - lastPos >= mid)
        {
            cowcount++;
            if(cowcount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) 
{
    int s = 0;
    int Maxi = -1;
    int ans = -1;
    sort(stalls.begin(), stalls.end());

    for(int i = 0 ;i<stalls.size();i++)
    {
        Maxi = max(Maxi, stalls[i]);
    }
    int e = Maxi;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(possible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }

    return ans;
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
        cout<<aggressiveCows(arr, k)<<endl;
    }

    return 0;
}
// input:
// 2
// 6 4
// 0 3 4 7 10 9
// 6 3
// 0 4 3 7 10 9
// output:
// 3
// 4

