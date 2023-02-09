#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    array<int,4> Arr;
    int size = Arr.size();

    for(int i = 0;i<size;i++)
    {
        cin>>Arr[i];
    }

    for(int i = 0;i<size;i++)
    {
        cout<<Arr[i]<<endl;
    }

    cout<<"Element at 2nd index--->"<<Arr.at(2)<<endl;

    cout<<"Empty or Not --->"<<Arr.empty()<<endl;
    cout<<"First element --->"<<Arr.front()<<endl;
    cout<<"Last element --->"<<Arr.back()<<endl;


    
    return 0;
}