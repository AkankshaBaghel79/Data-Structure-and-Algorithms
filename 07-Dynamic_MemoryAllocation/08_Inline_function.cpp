#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

inline int getmax(int& a, int& b)
{
    return (a>b)?a:b;
}


int main()
{
    int a = 10;
    int b = 20;

    int ans = 0;

    ans = getmax(a,b);

    cout<<ans<<endl;
    a+=11;
    b-=2;

    ans = getmax(a,b);
    cout<<ans<<endl;
    
    return 0;
}