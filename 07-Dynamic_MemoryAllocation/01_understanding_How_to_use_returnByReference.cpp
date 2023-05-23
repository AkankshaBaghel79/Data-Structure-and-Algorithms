#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int& findMax(int& num1, int& num2) {
    int a = num1;
    int &value = a; //here a and value both are local variable and value is the refrence variable
    if (num1 > num2) {
        return value;  // Returning a reference to 'num1'
    } else {
        return value;  // Returning a reference to 'num2'
    }
}

int *val (int n)
{
    int *ptr = &n;
    return ptr;
}


int main()
{
    int x = 10;
    // int y = 20;
    
    // int& maxNum = findMax(x, y);
    // maxNum = 30;  // Modifying the original variable directly
    // cout<<maxNum<<endl;
    // maxNum = 100;

    // findMax(x,y);
    
    // cout << "x: " << x << endl;  // Output: x: 30
    // cout << "y: " << y << endl;  // Output: y: 20

    cout<<val(x);


    
    
    return 0;
}