#include<iostream>
using namespace std;
 
#define endl "\n";

int main()
{
    int arr[3][3];

    cout<<"Input of the array : "<<endl;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Output of the array : "<<endl;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int maxi = INT_MIN;
    int row;

    cout<<"Row wise sum : "<<endl;
    for(int i = 0;i<3;i++)
    {
        int sum = 0;
        for(int j = 0;j<3;j++)
        {
            sum += arr[i][j];
            if(sum > maxi)
            {
                maxi = sum;
                row = i;
            }
        }
        cout<<i<<"-->"<<sum;
        cout<<endl;
    }

    cout<<"Largest sum possible --> "<<maxi<<" from "<<row<<" Row "<<endl;


    maxi = INT_MIN;
    int col;
    cout<<"col wise sum : "<<endl;
    for(int i = 0;i<3;i++)
    {
        int sum = 0;
        for(int j = 0;j<3;j++)
        {
            sum += arr[j][i];
            if(sum > maxi)
            {
                maxi = sum;
                col = i;
            }
        }
        cout<<i<<"-->"<<sum;
        cout<<endl;
    }

    cout<<"Largest sum possible --> "<<maxi<<" from "<<col<<" column "<<endl;



    return 0;
}