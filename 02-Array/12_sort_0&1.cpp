#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void printArray(vector<int> v, int n)
{
    for(int i = 0; i<n;i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
}

void sortArray(vector<int> &v, int n)
{
    int left = 0, right = n-1;

    while(left < right)
    {
        while(v[left] == 0 && left < right) left++;
        while(v[right] == 1 && left < right) right--;
        swap(v[left],v[right]);
        left++;
        right--;
    }
}



int main()
{
    int n;
    cin>>n;

    vector<int> v;

    for(int i =0 ; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sortArray(v,n);
    printArray(v,n);
    
    return 0;
}

// 0 1 0 1 0 0 1 0 1 === 0 0 0 0 0 1 1 1 1