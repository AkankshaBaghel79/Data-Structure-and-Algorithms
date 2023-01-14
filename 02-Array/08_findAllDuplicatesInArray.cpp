//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each 
//integer appears once or twice, return an array of all the integers that appears twice.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<int> solution(vector<int> &nums)
{
    vector<int> answer;

    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size()-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            answer.push_back(nums[i]);
        }
    }

    return answer;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> v;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

        vector<int> ans = solution(v);

        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}