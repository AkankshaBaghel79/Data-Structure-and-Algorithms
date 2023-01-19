#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    unordered_map<int,int> freq;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        freq[x]++;
    }

    unordered_set<int> s;
    for(auto x : freq)
    {
        s.insert(x.second);
    }

    if(s.size() == freq.size())
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    
    return 0;
}

// output:
// 6
// 1 1 2 1 2 3 --->> TRUE