#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class animal{

    private:
    int value;
    double d;
    char level;
    char *name;

    public:
    static int time;

    void setvalue(int v)
    {
        value = v;
    }
    void setch (char ch)
    {
        level = ch;
    }
    void setname(char* name)
    {
        strcpy(this->name,name);
    }

    int getvalue()
    {
        return value;
    }
    char getch()
    {
        return level;
    }
    

    //constructor

    //default constructor
    animal()
    {
        cout<<"Constructor is called "<<endl;
        name = new char[100];
    }

    //Parameterised constructor

    animal(int value, char ch)
    {
        this->value = value;
        this->level = ch;
    }

    //Copy constructor

    animal(animal& temp)
    {
        cout<<"Copy constructor get called"<<endl;
        this->value = temp.value;
        this->level = temp.level;
    }

    void print()
    {
        cout<<"[";
        cout<<"Name : "<<name<<" ,";
        cout<<"value : "<<value<<" ,";
        cout<<"Level : "<<level<<"]";
        cout<<endl;
    }

    ~animal()
    {
        cout<<"Destructor is called"<<endl;
    }

    static int random()
    {
        return (time + 100);
    }

    
    
};

int animal::time = 100;


int main()
{
    //static allocation
    // animal a;

    // a.setvalue(100);
    // a.setch('A');

    // cout<<"Value : "<<a.getvalue()<<endl;
    // cout<<"char: "<<a.getch()<<endl;

    // //dynamic allocation
    // animal *b = new animal;
    // b->setvalue(200);
    // b->setch('B');

    // cout<<"Value of B : "<<b->getvalue()<<endl;
    // cout<<"level of B : "<<(*b).getch()<<endl;


    //*********constructor*****/
    // animal lion(45,'T');
    // lion.print();

    // animal tiger(lion); // copy constructor
    // tiger.print();

    // animal* tiger = new animal();


    //******Shallow copy and deep copy*********//

    // animal lion;
    // lion.setvalue(50);
    // lion.setch('L');
    // char name[100] = "Lion";
    // lion.setname(name);
    // lion.print();



    //********Destructor***********//
    // animal a; // for static object destructor is called automatically
    // animal* b = new animal(); //for dynamic object destructor is called manually.
    // delete b;

    //static member and static functions

    cout<<"Time : "<<animal::time<<endl; 
    cout<<"Using static function : "<<animal::random()<<endl;

    
    return 0;
}