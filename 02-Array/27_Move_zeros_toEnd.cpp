#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void moveZeroes(vector<int>& nums) 
{
    int nonzero = 0;

    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[i], nums[nonzero]);
            nonzero++;
        }
    }

    for(int i = 0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main()
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

    moveZeroes(arr);
    
    
    return 0;
}

/*
Input:
5
0 1 0 3 12

output:
1 3 12 0 0
*/