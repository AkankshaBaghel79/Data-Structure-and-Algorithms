#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    public:
    int a;
    int b;

    ComplexNumbers(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    void print()
    {
        cout<<a<<"+"<<"i"<<b;
    }
    void plus(ComplexNumbers c2)
    {
        this->a = this->a+c2.a;
        this->b = this->b+c2.b;
    }
    void multiply(ComplexNumbers c2)
    {
        int c = a;
        int d = b;
        a = c*c2.a - d * c2.b;
        b = c*c2.b + d * c2.a;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2, choice;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    cin>>choice;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}