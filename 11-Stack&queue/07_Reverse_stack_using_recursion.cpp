#include <iostream>
#include <stack>
using namespace std;

#define endl "\n";

void InsertAtBootom(stack<int> &st, int x)
{
    // base case
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    // Recursive call
    InsertAtBootom(st, x);
    st.push(num);
}

void reverseStack(stack<int> &stack)
{

    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    // insert at bottom
    InsertAtBootom(stack, num);
}

int main()
{
    stack<int> st;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    reverseStack(st);
    for (int i = 0; i < n; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}