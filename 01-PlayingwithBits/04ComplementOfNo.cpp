#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int n;
    cin>>n;

    int m = n;
    int mask = 0;

    if(n == 0)
    {
        cout<<1<<endl;
    }
    else {
        while(m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int ans = (~n) & mask;
        cout<<ans<<endl;
    }
    

    return 0;
}