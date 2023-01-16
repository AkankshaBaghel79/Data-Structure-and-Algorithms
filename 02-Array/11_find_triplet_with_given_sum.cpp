#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void printArray(vector<int> v)
{
    for(int i = 0; i<v.size();i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
}

vector<int> solution(vector<int> v,int sum)
{
    vector<int> ans;

    sort(v.begin(), v.end());
    bool flag = false;

    for(int i = 0; i<v.size(); i++)
    {
        int l = i+1;
        int h = v.size() - 1;

        while(l<h)
        {
            if(v[i] + v[l] + v[h] == sum)
            {
                ans.push_back(v[i]);
                ans.push_back(v[l]);
                ans.push_back(v[h]);
                flag = true;
                break;
            }
            else if(v[i] + v[l] + v[h] < sum)
            {
                l++;
            }
            else{
                h--;
            }
        }

        if(flag)
        {
            break;
        }
    }

    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,sum;
    cin>>n>>sum;

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> ans = solution(v,sum);
    if(ans.size() != 0)
    printArray(ans);
    else
       cout<<"-1"<<endl;
    
    return 0;
}

// 6 6
// 1 2 3 1 2 3 =====>>> 1 2 3
