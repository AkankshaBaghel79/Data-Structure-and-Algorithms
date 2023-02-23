#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int LightUptheStreet(int n, int m , int k , vector <int> Checkpoints){
    // Write Code here.
    int ans = -1;
    int reach = 0;
    int flag = 0;

    for(int i = 0;i<m;i++)
    {
        if(Checkpoints[i] - k <= 1)
        {
            ans = 1;
            reach = Checkpoints[i] + k;
        }
        if((Checkpoints[i] - k)<=reach && (Checkpoints[i] + k)>= n)
        {
            if((Checkpoints[i] - k)<=0 && (Checkpoints[i] + k)>= n)
            {
                ans = 1;
            }
            else
            {
                ans++;
            }

            flag = 1;
            break;  
        }
    }

    if(flag)
    {
        return ans;
    }
    else{
        int val = -1;
        return val;
    }
}


int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int> arr;
        for(int i = 0;i<m;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }

        int k;
        cin>>k;

        cout<<LightUptheStreet(n, m, k, arr)<<endl;
    }
    

    
    return 0;
}