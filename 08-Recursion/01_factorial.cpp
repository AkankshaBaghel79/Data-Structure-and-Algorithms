#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int factorial(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }

    //recursive relation
    return n*factorial(n-1); // tail recursion
}


int main()
{
    int n;
    cin>>n;

    cout<<factorial(n)<<endl;
    
    return 0;
}