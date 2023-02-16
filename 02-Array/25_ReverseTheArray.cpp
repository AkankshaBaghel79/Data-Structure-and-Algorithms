#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Two pointer Approach is used

void reverseArray(vector<int> &arr , int m) 
{
    int s = m+1, e = arr.size()-1;

    while(s<=e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }

    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
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

        reverseArray(arr, m);
  
    }
    
    return 0;
}

//Input: 
/*
2
6 3
1 2 3 4 5 6
5 2
10 9 8 7 6
*/

//output:
/*
1 2 3 4 6 5 
10 9 8 6 7
*/