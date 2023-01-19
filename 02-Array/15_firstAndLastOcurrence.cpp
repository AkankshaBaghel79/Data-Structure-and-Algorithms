#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

// Using count sort algo but this algo of mine still needs some optimization.
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int m = INT_MIN;
    pair<int,int> ans;
    bool flag = false;
    for(int i = 0;i<arr.size();i++)
    {
        m = max(m, arr[i]);
    }
    // cout<<m<<endl;

    int count[100] ={0};
    for(int i = 0;i<arr.size();i++)
    {
        count[arr[i]]++;
    }
    if(count[k]==0)
    {
        flag = true;
    }


    for(int i = 1;i<=m;i++)
    {
        count[i] = count[i] + count[i-1];
    }

    if(flag)
    {
        ans = {-1, -1};
    }
    else{
        if(k==0)
        {
            ans = {0, count[k] - 1};
        }
        else
        {
        
            ans = {count[k-1], count[k] - 1}; 
        }
    }

    
    return ans;
}

//Using Binary search algorithm 
//Time complexity --> O(logn)

//it will give the first ocurrence of the value.
int firstOcurr(vector<int> arr, int n, int key)
{
    int s = 0;
    int e = n-1;

    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key)
        {
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e - s)/2;
    }

    return ans;
}

int lastOcurr(vector<int> arr, int n, int key)
{
    int s = 0;
    int e = n-1;

    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > key)
        {
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
        int n,k;
        cin>>n>>k;

        vector<int> arr;

        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }

        cout<<"The first and last Ocurrence of the element is : "<<endl;
        cout<<firstOcurr(arr, n, k)<<" "<<lastOcurr(arr, n, k)<<endl;
        cout<<"total number of Ocurrence: "<<endl;
        cout<<lastOcurr(arr, n, k)  - firstOcurr(arr, n, k) + 1<<endl;
    }
    return 0;
}

// input :
// 1
// 5 3
// 2 3 3 3 3

// output:
// The first and last Ocurrence of the element is :
// 1 4
// total number of Ocurrence:
// 4