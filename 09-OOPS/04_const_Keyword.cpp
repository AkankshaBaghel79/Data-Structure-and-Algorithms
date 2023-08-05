#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class myclass {
    public:
    const int a;

    myclass(int x) : a(x){
        // cout<<"The value of a : "<<endl;
    }
};


int main()
{
    myclass m(10);
    cout<<m.a<<endl;
    // m.a = 1000; invalid as a is of const type
    return 0;
}