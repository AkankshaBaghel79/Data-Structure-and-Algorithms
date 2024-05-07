#include <iostream>
#include <stack>
using namespace std;

#define endl "\n";

bool isvalidParenthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // if opening bracket, push the char
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // when the bracket is closing
            if (!s.empty())
            {
                char top = s.top();

                if ((ch == ')' && top == '(') || 
                (ch == ']' && top == '[') || 
                (ch == '}' && top == '{')) {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty())
    {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    string str = "{{[()]}}";

    bool ans = isvalidParenthesis(str);

    if (ans)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}