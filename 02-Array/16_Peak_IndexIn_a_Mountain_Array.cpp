#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int peakIndexInMountainArray(vector<int>& arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s)/2;

    while(s < e)
    {
        if(arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int main()
{
    int t;
    cin>>t;

    while(t--)   
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

        cout<<peakIndexInMountainArray(arr)<<endl;;
    }
    
    return 0;
}

// input:
// 1
// 4
// 3 4 5 1
// output:
// 2