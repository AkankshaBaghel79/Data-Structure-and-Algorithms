#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class Youtubechannel{

    public:
    string Name;
    int Subscribercount;


    Youtubechannel(string name, int subscribecount)
    {
        Name = name;
        Subscribercount = subscribecount;
    }

    bool operator==(const Youtubechannel& channel) const {
        return this->Name == channel.Name;
    }

};

ostream& operator<<(ostream& COUT, Youtubechannel& yt)
{
    COUT << "Name : "<<yt.Name<<endl;
    COUT << "Count : "<<yt.Subscribercount<<endl;
    return COUT;
}

class MyCollections{

    public:
    list<Youtubechannel> mychannel;

    void operator+=(Youtubechannel& yt)
    {
        this->mychannel.push_back(yt);
    }
    void operator-=(Youtubechannel& yt)
    {
        this->mychannel.remove(yt);
    }

};

ostream& operator<<(ostream& COUT, MyCollections& mycollections)
{
    for(Youtubechannel ytchannel: mycollections.mychannel)
        COUT<<ytchannel<<endl;   
    
    return COUT;
}

// void operator+=(MyCollections& my, Youtubechannel& yt) // Global += overloaded function
// {
//     my.mychannel.push_back(yt);
// }


int main()
{

    Youtubechannel yt1("Akanksha", 1000000);
    Youtubechannel yt2("Hellen", 50000);
    // cout << yt1 << yt2;

    // cout<<yt1;
    // operator<<(cout, yt2);


    MyCollections my1;

    my1 += yt1;
    my1 += yt2;
    my1 -= yt1;
    

    cout<<my1;    
    
    return 0;
}