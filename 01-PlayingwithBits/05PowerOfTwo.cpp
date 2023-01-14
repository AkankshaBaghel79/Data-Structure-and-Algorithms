#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int n;
    cin>>n;

    int count = 0;
    while(n != 0)
    {
        int bit = bit && 1;
        if(bit == 1) count++;

        n = n >> 1;

    }

    if(count == 1)
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}