#include<iostream>
using namespace std;

#define endl "\n";

int main()
{
    int a[3][3] = {1,2,3,4,5,6,7,8,9};//row wise
    int Sarr[3][3] = {{10,20,30}, {40,50,60},{70,80,90}}; //row wise
    int roArray[3][3]; //another way of declaring 2d array
    int coArray[3][3]; //another way of declaring 2d array


    // Input of the array (ROW wise)
    cout<<"Row wise input : "<<endl;
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<3;col++)
        {
            cin>>roArray[row][col];
        }
    }

    //Input of the array (column wise)
    cout<<"Column wise input : "<<endl;
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<3;col++)
        {
            cin>>coArray[col][row];
        }
    }

    //output of the array
    cout<<"Output of the 2D array : "<<endl;
    cout<<"1. Row wise : "<<endl;
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col < 3;col++)
        {
            cout<<roArray[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<"2. col wise : "<<endl;
    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col < 3;col++)
        {
            cout<<coArray[row][col]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
