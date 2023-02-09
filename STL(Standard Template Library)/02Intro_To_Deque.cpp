#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

//Deque is a type of data structure which insert and delete elements from both ends of the queue.
//Deque is also called doubly ended queue.

int main()
{
    deque<int> d;
    deque<int> d2;

    d.push_back(3);
    d.push_front(1);
    d.push_front(5);
    d.push_front(4);
    d.push_back(2);

    for(auto i : d)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_back();
    // d.pop_front();
    // for(auto i : d)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    cout<<"Element at index 2 is : "<<d.at(2)<<endl;// Random access is possible of index.
    cout<<"Is deque empty or not : "<<d.empty()<<endl;
    cout<<"Is deque(d2) empty or not : "<<d2.empty()<<endl;
    cout<<"Size of deque(d) : "<<d.size()<<endl;
    cout<<"after erase : "<<endl;
    d.erase(d.end()-1 , d.end());
    for(auto i : d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of deque(d) : "<<d.size()<<endl;
    d.clear();
    cout<<"Size after clearing the array : "<<d.size()<<endl;
    
    return 0;
}