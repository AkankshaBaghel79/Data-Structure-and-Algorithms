#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void print(int n)
{
    if(n==0)
    {
        return;
    }

    cout<<n<<endl;

    print(n-1);
}


int main()
{
    int n;
    cin>>n;

    cout<<endl;
    print(n);
    return 0;
}