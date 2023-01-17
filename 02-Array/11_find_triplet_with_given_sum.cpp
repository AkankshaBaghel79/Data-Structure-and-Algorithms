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

// Brute force Approach
// Time complexity -- > O(n)^3
// space complexity --> O(1)

vector<vector<int>> findTripletsBrute(vector<int>arr, int n, int K)
{
    set<vector<int>> visited;
    vector<vector<int>> ans;

    for(int i = 0;i<n-2;i++)
    {
        for(int j = i+1;j<n-1;j++)
        {
            for(int k = j+1;k<n;k++)
            {
                if(arr[i] + arr[j] + arr[k]  == K)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);

                    sort(temp.begin(),temp.end());

                    if(visited.find(temp) == visited.end())
                    {
                        ans.push_back(temp);
                        visited.insert(temp);
                    }
                }
            }
        }
    }

    return ans;
}

//Optimized Approach
// Time complexity --> O(n)^2

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) 
{
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0;i<n;i++)
    {
        int start = i+1;
        int end  = n-1;
        int value = K - arr[i];

        while(start < end)
        {
            if(arr[start] + arr[end] < value)
            {
                start++;
            }
            else if(arr[start] + arr[end] > value)
            {
                end--;
            }
            else{
                int x = arr[start];
                int y = arr[end];

                ans.push_back({arr[i], arr[start], arr[end]});

                while(start < end && arr[start] == x)
                {
                    start++;
                }
                while(start < end && arr[end] == y)
                {
                    end--;
                }

            }
        }

        while(i+1 < n && arr[i] == arr[i+1])
        {
            i++;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,sum;
        cin>>n>>sum;

        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

        vector<vector<int>> answer = findTriplets(v,n,sum);
        // cout<<answer.size()<<endl;
        for(int i = 0;i<answer.size();i++)
        {
            printArray(answer[i]);
        }
    }
    
}

// 6 6
// 1 2 3 1 2 3 =====>>> 1 2 3
// 5 12
//2 5 5 6 4 ===> (2 5 5) (2 4 6)
