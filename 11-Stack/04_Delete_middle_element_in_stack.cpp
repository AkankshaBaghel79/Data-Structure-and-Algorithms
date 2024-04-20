#include <iostream>
#include <stack>
using namespace std;

#define endl "\n";

void solve(stack<int>&inputStack, int count , int size)
{
    //base case
    if(count == size/2)
    {
        inputStack.pop();
        return;
    }

    //Recursive call
    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count+1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){

    int count = 0;
    solve(inputStack, count, N);
}
int main()
{
    stack<int> st;
    int n;
    cin>>n;

    //Insert value in stack
    for(int i = 0;i<n+1;i++)
    {
        int value;
        cin>>value;
        st.push(value);
    }

    deleteMiddle(st, n);
    //After deleting middle element
    for(int i = 0;i<n;i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}