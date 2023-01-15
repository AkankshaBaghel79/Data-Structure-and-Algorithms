#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<int> solution(vector<int> v1, vector<int> v2)
{
    int i=0,j=0;
    vector<int> ans;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i] < v2[j])
        {
            i++;
        }
        else if(v1[i] == v2[j])
        {
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v1;
        vector<int> v2;

        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            v1.push_back(x);
        }  

        for(int i = 0;i<m;i++)
        {
            int x;
            cin>>x;
            v2.push_back(x);
        }

        vector<int> ans = solution(v1,v2);  

        if(ans.size() == 0)
        {
            cout<<"-1"<<endl; 
        }
        else{
            
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        

    }
    
    return 0;
}