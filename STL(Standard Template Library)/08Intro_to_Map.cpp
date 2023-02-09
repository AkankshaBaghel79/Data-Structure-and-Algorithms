#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    map<int,string> mp;
    
    mp[1] = "Akanksha";
    mp[9] = "Baghel";
    mp[10] = "Is";
    mp[12] = "A";
    mp[40] = "Great";
    mp[50] = "Competitive";
    mp[60] = "Programmer";

    mp.insert({100, "Google"});

    cout<<"Before Erase : "<<endl;
    for(auto i : mp)
    {
        cout<<i.first<<" --> "<<i.second<<endl;
    }
    cout<<endl;

    mp.erase(50);

    cout<<"After Erase : "<<endl;

    for(auto i : mp)
    {
        cout<<i.first<<" --> "<<i.second<<endl;
    }
    cout<<endl;

    auto it = mp.find(10);

    for(auto i = it;i!=mp.end();i++)
    {
        cout<<(*i).first<<endl;
    }


    
    return 0;
}