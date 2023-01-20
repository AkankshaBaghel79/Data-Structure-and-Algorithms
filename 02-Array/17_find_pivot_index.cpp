#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
int sum(vector<int> &nums)
{
    int sum = 0;
    for(int i = 0;i<nums.size();i++)
    {
        sum += nums[i];
    }

    return sum;
}

int pivotIndex(vector<int>& nums)
{
    int value = sum(nums);
    int lsum = 0;
    int rsum = value;

    for(int i = 0;i<nums.size();i++)
    {
        rsum = rsum - nums[i];

        if(lsum == rsum)
        {
            return i;
        }

        lsum += nums[i];
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums;

    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout<<pivotIndex(nums)<<endl;

    return 0;
}