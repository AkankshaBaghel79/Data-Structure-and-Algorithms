//Queue usess FIFO (First IN First Out) Concepts.
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    queue<string> q;

    q.push("I");
    q.push("AM");
    q.push("Akanksha");
    q.push("Baghel");

    cout<<"Size Before POP : "<<q.size()<<endl;
    cout<<"First Element : "<<q.front()<<endl;
    q.pop();
    cout<<"First Element : "<<q.front()<<endl;
    cout<<"Size After POP : "<<q.size()<<endl;

    return 0;
}