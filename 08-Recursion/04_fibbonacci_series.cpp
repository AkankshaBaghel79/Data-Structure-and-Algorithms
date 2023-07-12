#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int fibbo(int n)
{
    //base case
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return fibbo (n-1)+ fibbo(n-2);
}


int main()
{
    int n;
    cin>>n;

    cout<<fibbo(n);
    
    return 0;
}