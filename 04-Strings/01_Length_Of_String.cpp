#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int getLength(char arr[])
{
    int count = 0;

    for(int i = 0; arr[i] != '\0';i++)
    {
        count++;
    }

    return count;
}

int main()
{
    char arr[20];
    cout<<"Enter the Single length string : ";
    cin>>arr;
    cout<<"Your string is :"<<arr<<endl;

    cout<<"Length : "<<getLength(arr)<<endl;
    
    
    return 0;
}