#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int n;
    cin>>n;

    int ans;
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;
    for(int i = 2;i<n;i++)
    {
        if(prime[i])
        {
            ans++;

            for(int j = 2*i; j<n;j = j+i)
            {
                prime[j] = false;
            }
        }
    }

    cout<<ans;
    
    return 0;
}

//O( n + log(logn))
