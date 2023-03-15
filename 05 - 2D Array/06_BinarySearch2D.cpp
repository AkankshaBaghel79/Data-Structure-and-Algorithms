#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = row*col -1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        mid = s + (e-s)/2;

        if(matrix[mid/col][mid%col] == target)
        {
            return true;
        }   
        else if(matrix[mid/col][mid%col] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid+1;
        }
    }

    return false;
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

    int target;
    cin>>target;

    if(searchMatrix(arr, target))
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}