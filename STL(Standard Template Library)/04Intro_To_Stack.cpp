// Stack ---> Last In First Out(LIFO) concepts is used.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    stack<string> s;
    s.push("I");
    s.push("AM");
    s.push("Akanksha");
    s.push("Baghel");

    cout<<"Top Element ---> "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element ---> "<<s.top()<<endl;
    cout<<"Size of Stack --->"<<s.size()<<endl;
    cout<<"Empty or not --->"<<s.empty()<<endl;
    
    return 0;
}