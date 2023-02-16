#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
// Two pointer Approach
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    vector<int> b;

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<m && j<n)
    {
        if(nums1[i] < nums2[j])
        {
            b.push_back(nums1[i]);
            i++;
            k++;
        }
        else if(nums1[i] == nums2[j])
        {
            b.push_back(nums1[i]);
            i++;
            k++;
        }

        else if(nums1[i] > nums2[j])
        {
            b.push_back(nums2[j]);
            j++;
            k++;
        }
    }

    while(i<m)
    {
        b.push_back(nums1[i]);
        i++;
        k++;
    }

    while(j<n)
    {
        b.push_back(nums2[j]);
        j++;
        k++;
    }

    for(int i = 0;i<b.size();i++)
    {
        nums1[i] = b[i];
        // cout<<b[i]<<" ";
    }

    for(int i = 0;i<b.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int m,n;
    cin>>m>>n;

    vector<int> nums1;
    vector<int> nums2;

    for(int i = 0;i<m;i++)
    {
        int x;
        cin>>x;
        nums1.push_back(x);
    }

    for(int i = 0;i<n;i++)
    {
        int y;
        cin>>y;
        nums2.push_back(y);
    }

    merge(nums1, m, nums2, n);
    
    return 0;
}

//Input:
/*
3 3
1 2 3
2 5 6
*/

//output :
/*
1 2 2 3 5 6
*/