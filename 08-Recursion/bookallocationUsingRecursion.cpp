#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool possible(vector<int> v, int students, int mid)
{
    int allocatestudents = 1;
    int totalpages = 0;

    for(int i = 0;i<v.size();i++)
    {
        if(v[i] > mid) return false;
        if(totalpages + v[i] > mid)
        {
            allocatestudents += 1;
            totalpages = v[i];
            if(allocatestudents > students)
            {
                return false;
            }
        }
        else{
            totalpages += v[i];
        }
    }

    return true;
}

int allocation(vector<int> v, int n, int m, int low, int high)
{
    if(m > n)
    {
        return -1;
    }

    int mid = (low+high)>>1;
    // int res = -1;
    int res;

    // if(low > high)
    // {
    //     return -1;
    // }

    if(possible(v,m,mid)){
        res = mid;
        return allocation(v, n,m,low, mid - 1);
    }
    else{
        return allocation(v,n,m,mid+1,high);
    }

    return res;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;

    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int low = *min_element(v.begin(),v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    cout<<"No. of maximum of minimum pages allocated are : "<<allocation(v,n,m,low, high)<<endl;
    return 0;
}