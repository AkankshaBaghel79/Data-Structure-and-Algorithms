#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class SmartPhone{

    public:
    virtual void TakeaSelfie() = 0;
    virtual void MakeACall() = 0;

};

class Android : public SmartPhone{

    public:
    void TakeaSelfie()
    {
        cout<<"Android Selfie ..."<<endl;
    }

    void MakeACall()
    {
        cout<<"Android Calling ..."<<endl;
    }

};

class Iphone : public SmartPhone{

    public:
    void TakeaSelfie()
    {
        cout<<"Iphone Selfie ..."<<endl;
    }

    void MakeACall()
    {
        cout<<"Iphone Calling ..."<<endl;
    }

};


int main()
{
    SmartPhone* s1 = new Android;
    s1->TakeaSelfie();

    SmartPhone* s2 = new Iphone;
    s2->MakeACall();

    
    return 0;
}