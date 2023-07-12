#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& answer)
{
    //base case
    if(index >= nums.size())
    {
        answer.push_back(output);
        return;
    }

    //Exclude
    solve(nums, output, index+1, answer);

    //Include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, answer);
}



vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> answer;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, answer);
    return answer;
}

void printarr(vector<vector<int>>& answer)
{
    for(int i = 0;i<answer.size();i++)
    {
        for(int j = 0;j<answer[i].size();j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    int n;
    cin>>n;

    vector<int> arr;

    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<vector<int>> answer = subsets(arr);
    printarr(answer);
    
    return 0;
}