#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{     
    vector<int> temp;
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            temp.push_back(Mat[i][j]);
        }
    }
    
    sort(temp.begin(), temp.end());
    int k = 0;
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            Mat[i][j] = temp[k];
            k++;
        }
    }
    
    return Mat;
}

void printvector(vector<vector<int>> answer, int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> arr;
    for(int i = 0;i<n;i++)
    {
        vector<int> ans;
        for(int j = 0;j<n;j++)
        {
            int x;
            cin>>x;
            ans.push_back(x);
        }

        arr.push_back(ans);
    }

    vector<vector<int>> answer = sortedMatrix(n,arr);

    printvector(answer , n);

    return 0;
}