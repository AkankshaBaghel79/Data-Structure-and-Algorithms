#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
int N = 1000000 + 7;
vector<bool> sieve(N+1, true);

void createSieve()
{
    sieve[0] = sieve[1] = false;

    for(int i = 2;i*i<=N;i++)
    {
        if(sieve[i] == true)
        {
            for(int j = i*i;j<=N; j+=i)
            {
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N) 
{

    vector<int> ds;
    for(int i = 2;i<=N;i++)
    {
        if(sieve[i] == true)
        {
            ds.push_back(i);
        }
    }

    return ds;
}


int main()
{
    createSieve();
    int t;
    cin>>t;
    while(t--)
    {
        int l, r;
        cin>>l>>r;

        //Step 1: Generate all primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));

        //Step 2: Create a dummy array of size r-l+1 and make everyone as 1
        vector<bool> dummy(r - l + 1, true);

        //Step 3: for all prime numbers mark its multiples as false
        for(auto pr: primes)
        {
            int firstMultiple = (l/pr) * pr;

            for(int j = max(firstMultiple, pr*pr); j<=r; j+= pr)
            {
                dummy[j -l] = 0;
            }
        }

        //Step 4: get all the primes
        for(int i = l;i<=r;i++)
        {
            if(dummy[i-l] == 1)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}