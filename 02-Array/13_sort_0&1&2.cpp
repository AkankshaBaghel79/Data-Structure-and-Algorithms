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
    int i = 0,j = 0, k = n-1;

    while(i<=k)
    {
        if(v[i] == 0)
        {
            swap(v[i], v[j]); // here i maintaing the area for 1.
            i++;
            j++;
        }
        else if(v[i] == 1) // here j maintaining the area for 0.
        {
            i++;
        }
        else{
            swap(v[i], v[k]); // here k maintaing the area for k.
            k--;
        }
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

// 0 1 2 2 1 1 2 0 0 === 0 0 0 1 1 1 2 2 2