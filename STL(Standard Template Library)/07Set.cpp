//Set stores only unique element.
//In set Elements are returned in sorted order

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    set<int> s;
    
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(8);
    s.insert(3);

    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);

    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Is 4 present or not --->"<<s.count(4)<<endl;

    set<int>::iterator itr = s.find(1);

    // cout<<"value present at itr is : "<<*itr<<endl;

    for(auto it = itr; it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }

    cout<<endl;


    
    return 0;
}
