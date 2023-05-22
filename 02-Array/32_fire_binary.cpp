#include <bits/stdc++.h>
using namespace std;

// bool possible(vector<long long int> &v, long long int x, long long int mid)
// {
//     long long int animalCount = 0;
    
//     for(long long int i = 0;i<v.size();i++)
//     {
//         if(v[i]>=mid)
//         {
//             animalCount++;
//             if(animalCount == x && i!=v.size())
//             {
//                 return true;
//             }
//         }
//     }
//     return false;

// }

// long long int energy(long long int n, long long int x, vector<long long int> v)
// {
//     long long int ans = -1;
//     long long int sum =0;
//     long long int s = 0;

//     for(long long int i = 0;i<n;i++)
//     {
//         sum+=v[i];
//     }

//     long long int e = sum;
//     long long int mid = s + (e - s)/2;

//     while(s<=e)
//     {
//         if(possible(v, x, mid))
//         {
//             ans = mid;
//             s = mid+1;
//         }
//         else{
//             e = mid - 1;
//         }
//         mid = s + (e - s)/2;
//     }

//     return ans;
    
// }

long long int energy(long long int n, long long int x, vector<long long int> v)
{
    int count = 0;
    int ans = -1;

    for(int i = 0;i<n;i++)
    {
        long long int temp = v[i];

        for(long long int k = 0;k<n;k++)
        {
            if(temp <= v[k])
            {
                count++;
            }
        }

        if(count == x)
        {
            ans = 1;
            return temp;
            break;
        }

        count = 0;
    }

    return -1;

}

int main()
{
    long long int n,x;
    cin>>n>>x;

    vector<long long int> v;
    for(long long int i = 0;i<n;i++)
    {
        long long int x;
        cin>>x;
        v.push_back(x);
    }

    cout<<energy(n,x,v);
    return 0;
}