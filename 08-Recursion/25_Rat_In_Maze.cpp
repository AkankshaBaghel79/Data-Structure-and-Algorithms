#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool possible(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && (m[x][y] == 1) && (visited[x][y] == 0) )
    {
        return true;
    }
    else{
        return false;
    }

}


void solve(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited, vector<string>& ans, string path)
{
    //base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }


    //processing
    visited[x][y] = 1;

    //4 Choices -- > Down, up, left, and Right
    //1.Down
    int newx = x+1;
    int newy = y;

    if(possible(m,n,newx, newy, visited))
    {
        path.push_back('D');
        solve(m,n,newx, newy, visited, ans, path);
        path.pop_back();
    }

    //2.UP
    newx = x-1;
    newy = y;

    if(possible(m,n,newx, newy, visited))
    {
        path.push_back('U');
        solve(m,n,newx, newy, visited, ans, path);
        path.pop_back();
    }

    //3.Left
    newx = x;
    newy = y-1;

    if(possible(m,n,newx, newy, visited))
    {
        path.push_back('L');
        solve(m,n,newx, newy, visited, ans, path);
        path.pop_back();
    }

    //4.Right
    newx = x;
    newy = y+1;

    if(possible(m,n,newx, newy, visited))
    {
        path.push_back('R');
        solve(m,n,newx, newy, visited, ans, path);
        path.pop_back();
    }


    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> visited = m;

    if(m[0][0] == 0)
    {
        return ans;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            visited[i][j] = 0;
        }
    }

    int srcx = 0;
    int srcy = 0;

    string path = "";
    solve(m,n,srcx,srcy,visited, ans, path);
    sort(ans.begin(), ans.end());// for lexographically increasing order
    return ans;
}


int main()
{
    int n;
    cin>>n;

    vector<vector<int>> maze(n, vector<int> (n,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    cout<<"The possible paths are : "<<endl;

    vector<string> ans = findPath(maze, n);
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}