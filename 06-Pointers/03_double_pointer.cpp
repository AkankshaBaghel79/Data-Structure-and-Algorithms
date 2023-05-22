#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void update(int **p)
{
    // p = p + 1;
    // cout<<"In function : "<<p<<endl; //Nochange

    // *p = *p + 1;
    // cout<<"In function : "<<*p<<endl; //change

    **p = **p + 1;
    cout<<"In function : "<<**p<<endl;//change


    

}


int main()
{
    int i = 10;
    int *ptr = &i;
    int **p = &ptr;


    //value of i
    // cout<<"value of i : "<<i<<endl;

    // cout<<i<<endl;
    // cout<<*ptr<<endl;
    // cout<<**p<<endl;

    // //value of address of i
    // cout<<"Value of address of i : "<<endl;
    // cout<<&i<<endl;
    // cout<<ptr<<endl;
    // cout<<*p<<endl;

    // //address of ptr
    // cout<<"value address of ptr"<<endl;
    // cout<<&ptr<<endl;
    // cout<<p<<endl;


    // int arr[5] = {10,20,30};
    // cout<<"address of first element of array : "<<endl;

    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;


    cout<<"before : "<<**p<<endl;
    update(p);
    cout<<"After : "<<**p<<endl;



    return 0;
}