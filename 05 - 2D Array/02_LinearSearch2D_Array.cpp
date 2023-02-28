#include<iostream>
using namespace std;

#define endl "\n";

bool search(int arr[][3], int row, int col, int key)
{
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(key == arr[i][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int arr[3][3];

    cout<<"Input of the 2D array : "<<endl;
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<3;col++)
        {
            cin>>arr[row][col];
        }
    }
    int key;
    cout<<"Key : ";
    cin>>key;

    bool find = search(arr, 3, 3,key);
    if(find)
    {
        cout<<"Element found !!"<<endl;
    }
    else
    {
        cout<<"Not found !!"<<endl;
    }
    
    return 0;
}