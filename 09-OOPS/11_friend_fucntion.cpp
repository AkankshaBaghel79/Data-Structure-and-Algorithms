#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class EquilateralTriangle{

    float a;
    float circumference;
    float area;

    public:

    void setValue(float length)
    {
        a = length;
        circumference = a + a + a;
        area = (1.73 * a * a)/4;
    }

    // friend void printResult(EquilateralTriangle);
    friend class HomeWork;

};

// void printResult(EquilateralTriangle et) //friend function
// {
//     cout<<"Circumference : "<<et.circumference<<endl;
//     cout<<"Area : "<<et.area<<endl;
// }

class HomeWork{ // friend class

    public:
    void printResult(EquilateralTriangle et)
    {
        cout<<"Circumference : "<<et.circumference<<endl;
        cout<<"Area : "<<et.area<<endl;
    }

};


int main()
{

    EquilateralTriangle et1;
    et1.setValue(5);

    // printResult(et1);

    HomeWork h1;
    h1.printResult(et1);    
    return 0;
}