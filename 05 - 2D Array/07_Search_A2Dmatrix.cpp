#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while(rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if(element == target)
        {
            return true;
        }
        else if(element > target)
        {
            colIndex--;
        }
        else{
            rowIndex++;
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