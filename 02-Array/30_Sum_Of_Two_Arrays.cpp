#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<int> reverse(vector<int> v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) 
{
	int i = n - 1;
    int j = m - 1;

    vector<int> ans;
    int carry = 0;

    while (i>=0 && j>=0)
    {
        int val1 = a[i];
        int val2 = b[i];

        int sum = val1 + val2 + carry;

        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        i--;
        j--;
    }

    // if the length of first array is greater than second.

    while(i>=0)
    {
        int sum = a[i] + carry;

        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        i--;
    }

    //if the length of second array is greater than first

    while(j>=0)
    {
        int sum = b[j] + carry;

        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        j--;
    }

    //for carry if the carry remains

    while(carry != 0)
    {
        int sum = carry;

        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
    }

    return reverse(ans);
    
}

void print(vector<int> ans)
{
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a;
    vector<int> b;

    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i = 0;i<m;i++)
    {
        int y;
        cin>>y;
        b.push_back(y);
    }

    vector<int> ans = findArraySum(a, n, b, m);
    print(ans);
    
    return 0;
}