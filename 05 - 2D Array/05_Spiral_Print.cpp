#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;


    int count = 0;
    int total = row * col;  

    while(count < total) 
    {
        //for printing the starting row
        for(int i = startingCol;(count < total && i<=endingCol);i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        
        //For printing the ending column
        for(int i = startingRow;(count < total && i<=endingRow);i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        //for printing the ending row
        for(int i = endingCol;(count < total && i>=startingCol);i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        //for printing the starting col
        for(int i = endingRow;(count < total && i>=startingRow);i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;

    }

    return ans;
}

void printvector(vector<int> arr)
{
    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

    cout<<"Sprial order of the matrix : "<<endl;

    vector<int> sprial = spiralOrder(arr);
    printvector(sprial);

    
    return 0;
}