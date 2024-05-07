#include <iostream>
#include <stack>
using namespace std;

#define endl "\n";

void InsertSort(stack<int> &stack, int x)
{
    //base case 
    if(stack.empty() || stack.top() < x) {
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    InsertSort(stack, x);

    stack.push(num);
}

void sortStack(stack<int> &stack)
{

    // base casse
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recusive call
    sortStack(stack);

    // sorted insertion
    InsertSort(stack, num);
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

    sortStack(st);
    for (int i = 0; i < n; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}