#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int n;
    cin>>n;

    int ans = 0;
    int i = 0;

    while(n != 0)
    {
        int bit = n % 10;
        ans = bit * pow(2 , i) + ans;
        n = n / 10;
        i++;
    }

    cout<<ans<<endl;
    
    return 0;
}