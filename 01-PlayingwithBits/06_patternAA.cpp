// Print AA pattern

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
        for(int j = n;j>i;j--)
        {
            cout<<" ";
        }
        while(true)
        {
            if(i==1){
                cout<<" A";
                break;
            }
            else{
                cout<<"A";
                for(int m = 2*i;m>1;m--)
                {
                    cout<<" ";
                }
                cout<<"A";
                break;
            }
        }
        
        cout<<endl;
    }
    
    return 0;
}