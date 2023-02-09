#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    priority_queue<int> maxi; // Max heap

    //Min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(15);
    maxi.push(20);
    maxi.push(10);
    maxi.push(25);
    maxi.push(9);

    cout<<"Size of Max Heap : "<<maxi.size()<<endl;

    cout<<"Print the max heap : "<<endl;
    int n = maxi.size();

    for(int i = 0;i<n;i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    cout<<"Is Max heap empty or not -->"<<maxi.empty()<<endl;

    mini.push(15);
    mini.push(20);
    mini.push(10);
    mini.push(25);
    mini.push(9);

    cout<<"Size of Min Heap : "<<mini.size()<<endl;

    cout<<"Print the min heap : "<<endl;
    int m = mini.size();

    for(int i = 0;i<m;i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<"Is Min heap empty or not -->"<<mini.empty()<<endl;


    return 0;
}