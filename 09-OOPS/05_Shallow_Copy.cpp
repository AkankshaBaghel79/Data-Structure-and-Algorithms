#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class box{
    public:
    int *l;
    int h;
    int b;

    public:
    box()
    {
        l = new int;
    }

    void setData(int a,int b, int c)
    {
        *l = a;
        this->b = b;
        this->h = c;
    }

    void display()
    {
        cout<<"Length : "<<*l<<endl;
        cout<<"breadth : "<<b<<endl;
        cout<<"height : "<<h<<endl;
    }

    //paramertrized copy constructor for deep copy
    box(box &value)
    {
        l = new int;
        *l = *(value.l);
        b = value.b;
        h = value.h;
    }

    ~box()
    {
        delete l;
    }
};

int main()
{

    box b1,b2;
    b1.setData(5,10,15);
    // cout<<"For B1 : "<<endl;
    // b1.display();

    // when copying the data object after intilaizations then the copy is done through default assignment operator.
    // cout<<"For B2 : "<<endl;
    // b2 = b1; 
    // // b2.display();
    // b1.l = 100; // when changing the b1 here b2 is not changing.
    // b1.b = 0;
    // b1.h = 22;
    // b2.display();
    // b1.display();

    //when copying the data object at the time of intilaizations then the copy is made through COPY CONSTRUCTOR.
    // cout<<"For B3 : "<<endl;
    box b3 = b1;
    // b3.display();
    *(b1.l) = 200;
    b1.display();
    b3.display();

    
    return 0;
}