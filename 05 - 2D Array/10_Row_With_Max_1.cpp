#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int first(vector<int>arr, int low, int high)
{
    if(high >= low)
    {
        int mid = low + (high - low)/2;

        if((mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
        {
            return mid;
        }
        else if(arr[mid] == 0)
        {
            return first(arr, mid+1, high);
        }
        else{
            return first(arr, low, mid-1);
        }
    }

    return -1;
}

int rowWithMax1s(vector<vector<int> > arr, int n, int m)
{
    int ans = 0, maxi = -1;

    int index;
    for(int i = 0;i<n;i++)
    {
        index = first(arr[i], 0, m - 1);
        if(index != -1 && m-index > maxi)
        {
            maxi = m - index;
            ans = i;
        }
    }

    return ans;
}


int main()
{
    int row,col;
    cin>>row>>col;
    
    vector<vector<int>> arr;
    for(int i = 0;i<row;i++)
    {
        vector<int> ans;
        for(int j = 0;j<col;j++)
        {
            int x;
            cin>>x;
            ans.push_back(x);
        }

        arr.push_back(ans);
    }

    cout<<rowWithMax1s(arr, row, col);

    return 0;
}
