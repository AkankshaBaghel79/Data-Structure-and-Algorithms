#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

long long int binarySearch_SquareRoot(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e)
    {
        long long int square = mid * mid;
        if(square == n)
        {
            return mid;
        }
        else if(square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    cout<<binarySearch_SquareRoot(n);
    
    return 0;
}