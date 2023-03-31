#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int median(vector<vector<int>> &matrix, int R, int C)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        if (matrix[i][0] < min)
            min = matrix[i][0];
    
        if (matrix[i][C-1] > max)
            max = matrix[i][C-1];
    }
    
    int desired = (R * C + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < R; ++i)
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        if(place == desired)
        {
            return mid;
        }
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
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

    cout<<"Median is : "<<median(arr, row, col);
    
    return 0;
}