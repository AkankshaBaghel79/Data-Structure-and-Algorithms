//How to create a 2D array dynamically 
//How to release memory
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";


int main()
{
    int row;
    cin>>row;
    int col;
    cin>>col;

    int **arr = new int*[row];

    //Creating 2D array

    for(int i = 0;i<row;i++)
    {
        arr[i] = new int[col];
    }

    //Taking inputs
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    //Producing Outputs
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    //relesing memory
    for(int i = 0;i<row;i++)
    {
        delete [] arr[i];
    }

    delete [] arr;

    
    return 0;
}