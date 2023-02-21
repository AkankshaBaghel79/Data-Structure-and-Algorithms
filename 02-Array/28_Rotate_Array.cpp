#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

/*
the concept is whenever we mod n with any value the answer always lies between 0 to (n-1)
   x % n ---> 0 to  (n-1)   
*/

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);

    for(int i = 0;i<n;i++)
    {
        temp[(i+k) % n] = nums[i];
    }

    nums = temp; // copy temp into nums vector

    for(int i = 0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> nums;

    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;

        nums.push_back(x);
    }

    rotate(nums, k);
    
    return 0;
}

// input:
/*
7 3
1 2 3 4 5 6 7

output:
5 6 7 1 2 3 4
*/