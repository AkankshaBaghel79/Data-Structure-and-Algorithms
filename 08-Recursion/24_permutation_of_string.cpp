#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void solve(string str, int index, vector<string>& ans)
{
    //base case
    if(index >= str.length())
    {
        ans.push_back(str);
        return;
    }


    for(int i = index;i<str.length();i++)
    {
        swap(str[i],str[index]);
        solve(str, index+1, ans);
        //backtring
        swap(str[i], str[index]);
    }
}

vector<string> generatePermutations(string &str){
    vector<string> ans;
    int index=0;
    solve(str, index, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s;
    cin>>s;

    vector<string> ans = generatePermutations(s);
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}