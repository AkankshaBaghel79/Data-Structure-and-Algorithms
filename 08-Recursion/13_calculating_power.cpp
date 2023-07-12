#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int power(int a, int b)
{
    //base case
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }

    //recursive call
    int ans = power(a, b/2);

    if(b % 2 == 0)
    {
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}


int main()
{
    int a,b;
    cin>>a>>b;

    cout<<"Power is : "<<power(a,b)<<endl;
    
    return 0;
}