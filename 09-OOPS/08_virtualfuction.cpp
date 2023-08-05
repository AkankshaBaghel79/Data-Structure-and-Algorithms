//Virtual function, pure virtual function and abstract classes
#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Instrument{
    public:
    virtual void makeSound() = 0;//pure virtual function

};

class Accordian : public Instrument{

    public:
    void makeSound()
    {
        cout<<"Accordian Playing ..."<<endl;
    }
};

class Piano : public Instrument{

    public:
    void makeSound(){
        cout<<"Piano Playing ..."<<endl;
    }

};


int main()
{
    // Instrument i1;
    // i1.makeSound();

    // Accordian a1;
    // a1.makeSound();

    Instrument* i2 = new Accordian;
    // i2->makeSound();

    Instrument* i3 = new Piano;
    // i3->makeSound();
    

    Instrument* list[2] = {i2, i3};

    for(int i = 0;i<2;i++)
    {
        list[i]->makeSound();
    }
    return 0;

}