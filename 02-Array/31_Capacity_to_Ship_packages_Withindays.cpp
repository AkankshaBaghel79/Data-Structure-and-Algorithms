#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n";

bool possible(vector<int>& weights, int days, int mid)
{
    int daycount = 1;
    int capacity = 0;

    for(int i = 0;i<weights.size();i++)
    {
        if(capacity + weights[i] <= mid)
        {
            capacity += weights[i];
        }
        else{
            daycount++;
            if(daycount > days || weights[i] > mid)
            {
                return false;
            }
            capacity = weights[i];
        }
    }

    return true;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int s = 0;
    int ans = -1;
    int sum = 0;

    for(int i = 0;i<weights.size();i++)
    {
        sum += weights[i];
    }

    int e = sum;
    int mid = s + (e - s)/2;

    while(s<=e)
    {
        if(possible(weights, days, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;

}

int main()
{
    int n,days;
    cin>>n>>days;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<shipWithinDays(arr, days)<<endl;

    return 0;
}