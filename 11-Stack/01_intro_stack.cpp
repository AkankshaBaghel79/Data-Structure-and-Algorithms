#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    // initializing the stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // pop operation
    s.pop();
    s.pop();
    s.pop();
    s.pop();


    // cout << "top element : " << s.top() << endl;
    cout << "Empty or not : " << s.empty() << endl;

    return 0;
}