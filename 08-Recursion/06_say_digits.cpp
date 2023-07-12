#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

void saydigits(int n, vector<string> s)
{
    // base case
    if (n == 0)
        return;

    int digits = n % 10;
    n = n / 10;

    saydigits(n, s);
    cout << s[digits] << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<string> s = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout<<"Digits are : "<<endl;

    saydigits(n,s);

    return 0;
}