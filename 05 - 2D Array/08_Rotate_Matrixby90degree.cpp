#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void print2DVector(vector<vector<int>> arr)
{
   
    for(int i = 0;i<arr.size();i++)
    {
        for(int j = 0;j<arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

//For rotating the matrix by 90 degree we just need a two step process:
//1-->Transpose the matrix
//2-->Reverse the matrix

void rotate(vector<vector<int>> &arr)
{
    for(int i = 0;i<arr.size();i++)
    {
        for(int j = 0;j<i;j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i = 0;i<arr.size();i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main()
{
    int row,col;
    cin>>row>>col;
    
    vector<vector<int>> arr;
    for(int i = 0;i<row;i++)
    {
        vector<int> ans;
        for(int j = 0;j<col;j++)
        {
            int x;
            cin>>x;
            ans.push_back(x);
        }

        arr.push_back(ans);
    }
    cout<<"Before Rotation : "<<endl;
    print2DVector(arr);
    rotate(arr);
    cout<<"After rotataion : "<<endl;
    print2DVector(arr);

    return 0;
}