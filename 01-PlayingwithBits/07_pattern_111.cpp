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

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(i==1 || i==5)
            {
                cout<<"0";
            }
            else{
                if(j==1 || j==5)
                {
                    cout<<"0";
                }
                else{
                    cout<<" ";
                } 
            }
        }
        cout<<endl;
    }
    
    return 0;
}