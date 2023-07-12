#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string reverse(string s, int i)
{
    int n = s.length();
    if(i>(n-i-1))
      return s; //Base condition

    swap(s[i],s[n-i-1]);
    i++;

    return reverse(s, i);
}


int main()
{
    string s;
    cin>>s;

    cout<<reverse(s,0)<<endl;

    return 0;
}