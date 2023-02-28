#include <bits/stdc++.h> 
using namespace std;

#define endl "\n";

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for(int col = 0;col<mCols;col++)
    {
        //If col is odd;
        //bottom to top printing of array
        if(col&1)
        {
            for(int row = nRows-1;row>=0;row--)
            {
                ans.push_back(arr[row][col]);
            }
        }

        //If the column is even
        //Top to bottom printing of the vector
        else{
            for(int row = 0;row<nRows;row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
    }

    return ans;
}

void printvector(vector<int> wave)
{
    for(int i = 0;i<wave.size();i++)
    {
        cout<<wave[i]<<" ";
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

    cout<<"Printing the wave print : "<<endl;
    vector<int> wave = wavePrint(arr, row, col);
    printvector(wave);
    
    return 0;
}