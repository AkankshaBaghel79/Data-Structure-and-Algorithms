#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Complex{
    
    private:
    int real;
    int img;

    public:
    Complex(int r = 0, int i = 0)
    {
        this->real = r;
        this->img = i;
    }

    Complex operator+(const Complex &a)
    {
        Complex b;
        b.real = this->real + a.real;
        b.img = this->img + a.img;
        return b;
    }

    void print()
    {
        cout<<real<<" +i"<<img;
    }
};


int main()
{
    Complex c1(10,5),c2(5,10);
    Complex c3 = c1 + c2;

    c3.print();

    return 0;
}