#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool check(vector<int>& nums) 
{
    int n = nums.size();

    int count = 0;

    for(int i = 1;i<n;i++)
    {
        if(nums[i-1] > nums[i])
        {
            count++;
        }
    }

    if(nums[n-1] > nums[0])
    {
        count++;
    }

    return count<=1;
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

    bool value = check(nums);

    if(value)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    
    return 0;
}