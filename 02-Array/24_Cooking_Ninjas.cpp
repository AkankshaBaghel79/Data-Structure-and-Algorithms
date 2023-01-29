#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool Possible(vector<int> rank, int m, int mid)
{
    int cookingTime = 0;
    int dishes = 0;

    for(int i = 0;i<rank.size();i++)
    {
        cookingTime = rank[i];
        int j = 2;
        while (cookingTime <= mid)
        {
            dishes++;
            cookingTime += (rank[i]*j);
            j++;
            if(dishes >= m)
            {
                return true;
            }
        }

        
    }

    return false;
}

int CookingNinjas(vector<int> &rank, int m)
{
    int s = 0;
    int Maxi = INT_MIN;
    int ans = -1;

    for(int i = 0;i<rank.size();i++)
    {
        Maxi = max(Maxi, rank[i]);
    }

    int e = 1e8;
    
    int mid = s + (e - s)/2;

    while(s<=e)
    {
        if(Possible(rank, m, mid))
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
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int> arr;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<CookingNinjas(arr, m)<<endl;
    }
    
    return 0;
}