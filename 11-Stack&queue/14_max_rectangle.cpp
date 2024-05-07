#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
#define MAX 1000

vector<int> nextsmaller(int* arr, int n) {
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);
    for(int i = n-1;i>=0;i--)
    {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevsmaller(int* arr, int n) {
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);
    for(int i = 0;i<n;i++)
    {
        int curr = arr[i];
        while(st.top() != -1 && arr[st.top()]>=curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(int* heights, int n) {

    vector<int> next(n);
    next = nextsmaller(heights, n);

    vector<int> prev(n);
    prev = prevsmaller(heights, n);

    int area = INT_MIN;
    for(int i = 0;i<n;i++) {
        int l = heights[i];

        if(next[i] == -1) next[i] = n;

        int b = next[i] - prev[i] - 1;
        int newarea = l*b;

        area = max(area, newarea);
    }

    return area;

}

int maxArea(int M[MAX][MAX], int n, int m) {

    int area = largestRectangleArea(M[0], n);

    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(M[i][j] != 0) M[i][j] = M[i][j] + M[i-1][j];
            else M[i][j] = 0;
        }

        area = max(area, largestRectangleArea(M[i], n));
    }

    return area;
}

int main()
{
    cout<<"Main function"<<endl;
    int n, m;
    cin>>n>>m;

    int M[MAX][MAX];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>M[i][j];
        }
    }

    cout<<"Max rectangel Area is : "<<maxArea(M, n, m);
    
    return 0;
}