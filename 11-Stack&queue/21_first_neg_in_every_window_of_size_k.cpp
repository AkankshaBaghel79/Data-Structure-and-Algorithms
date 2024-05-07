#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int n, long long int k) {
    deque<long long int> d;
    vector<long long> ans;

    //Process first window 
    for(int i = 0;i<k;i++) {
        if(A[i] < 0) {
            d.push_back(i);
        }
    }

    //Push the ans
    if(!d.empty()) {
        ans.push_back(A[d.front()]);
    }
    else {
        ans.push_back(0);
    }

    //Process the other window
    for(int i = k;i<n;i++) {
        if(!d.empty() && (i - d.front()) >= k) {
            d.pop_front();
        }

        //push the curr ans
        if(A[i] < 0) {
            d.push_back(i);
        }

        if(d.size() > 0) {
            ans.push_back(A[d.front()]);
        }
        else {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    long long int k;
    cin>>k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);

    cout<<"Ans : ";
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}