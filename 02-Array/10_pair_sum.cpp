#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<vector<int>> pairSum(vector<int> &arr, int s){
    
    vector<vector<int>> ans;
    
    for(int i=0;i<arr.size();i++)
    {
        int value = arr[i];
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    return ans;
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
        int n,s;
        cin>>n>>s;

        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

        vector<vector<int>> vec = pairSum(v,s);

        for (int i = 0; i < vec.size(); i++) 
        {
            for (int j = 0; j < vec[i].size(); j++)
                cout << vec[i][j] << " ";
            cout << endl;
        }
    }
    
    return 0;
}