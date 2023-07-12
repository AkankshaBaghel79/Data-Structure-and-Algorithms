#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int power(int n)
{
    if(n==0)
    {
        return 1;
    }

    return 2*power(n-1);
}


int main()
{
    int n;
    cin>>n;

    cout<<power(n)<<endl;
    
    return 0;
}