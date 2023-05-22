#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void update(int *&p)
{
    // p = p+1;
    // cout<<p<<endl;

    *p = *p + 10;
}

int getsum(int arr[], int n);

int main()
{
    // int arr[10] = {144, 11, 25, 13};
    // cout<<"Address of first block of array : "<<arr<<endl;
    // cout<<"Address of first block of array : "<<&arr[0]<<endl;
    // cout<<"Value present in the first block of array : "<<arr[0]<<endl;
    // cout<<"Value present in the first block of array : "<<0[arr]<<endl;
    // cout<<"Value present in the first block of array : "<<*arr<<endl;
    // cout<<"Added 1 in the first value of array "<<*arr + 1<<endl;
    // cout<<"Added 1 in the first value of array "<<(*arr) + 1<<endl;
    // cout<<"Increment the address  "<<*(arr + 2)<<endl;
    // cout<<"address of 2rd block of array  "<<(arr + 1)<<endl;
    // cout<<"address of 3rd block of array  "<<(arr + 2)<<endl;
    // cout<<"address of 4th block of array  "<<(arr + 3)<<endl;

    // cout<<"Second value of the array : "<<1[arr]<<endl;

    // int temp[10] = {5,9,10};

    // cout<<"Size of arr : "<<sizeof(temp)<<endl;
    // cout<<"Size of the element of arr : "<<sizeof(*temp)<<endl;
    // cout<<"Size of arr : "<<sizeof(&temp)<<endl;

    // int *ptr = temp;
    // // int *ptr = &temp[0];
    // cout<<"size of ptr : "<<sizeof(ptr)<<endl;
    // cout<<"size of *ptr : "<<sizeof(*ptr)<<endl;
    // cout<<"size of &ptr : "<<sizeof(&ptr)<<endl;

    // int a[10] = {11,12,13};
    // cout<<a<<endl;   //address of first block of array
    // cout<<&a<<endl; //address of first block of array
    // cout<<*a<<endl;

    // int *p = a;
    // cout<<p<<endl;  
    // cout<<&p<<endl;// address of p
    // cout<<*p<<endl;


    /*Char Array*/

    // char ch[5] = "ebc";
    // cout<<ch<<endl;

    // char *c = &ch[0];
    // cout<<c<<endl;
    // cout<<*(c + 1) + 1<<endl;



    //Pointer to function

    // int a = 5;
    // int *p = &a;

    // cout<<"Before : "<<*p<<endl;
    // update(p);
    // cout<<"After : "<<*p<<endl;
    // cout<<"A : "<<a<<endl;

    int arr[5] = {1,2,3,4};
    cout<<"size of array in main function : "<<sizeof(arr)<<endl;

    cout<<getsum(arr+2, 2);
    
    
    return 0;
}

int getsum(int arr[] , int n) // in place of int arr[] you can also write int *arr
{
    cout<<endl<<"size of array in call function : "<<sizeof(arr)<<endl;
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum+= arr[i];
    }
    return sum;
}