#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Complex{

    private:
    int real;
    int img;


    public:

    Complex(int r = 0 , int i = 0){
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
        cout<<real<<" + i"<<img<<endl;
    }
};


int main()
{
    Complex c(10,5), c2(2,2);
    Complex c3 = c + c2;

    c3.print();


    
    return 0;
}