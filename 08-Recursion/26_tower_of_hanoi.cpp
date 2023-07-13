#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

void toh(int n, char from, char to, char aux) {
    // base case
    if(n==1)
    {
        cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
        return;
    }

    toh(n-1, from,aux,to);
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    toh(n-1,aux,to,from);
}


int main()
{
    int n;
    cin>>n;

    char from = 'A';
    char to = 'B';
    char aux = 'C';

    toh(n,from, to, aux);

    
    return 0;
}