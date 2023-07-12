#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int distinctway(int n)
{
    //base case
    if(n < 0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }


    return distinctway(n-1) + distinctway(n-2);
}


int main()
{
    int n;
    cin>>n;

    cout<<distinctway(n);
    
    return 0;
}