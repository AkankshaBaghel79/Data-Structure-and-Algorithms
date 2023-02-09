#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    list<int> l;
    list<int> list1(5,10);

    l.push_back(25);
    l.push_front(11);
    list1.push_front(99);

    cout<<"Printing l :"<<endl;
    for(auto i : l)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Printing list1 :"<<endl;
    cout<<"Size : "<<list1.size()<<endl;
    for(auto i : list1)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    list1.erase(list1.begin());
    cout<<"Size : "<<list1.size()<<endl;


    return 0;
}