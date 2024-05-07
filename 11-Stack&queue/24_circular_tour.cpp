#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n) {
    int defitcit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0;i<n;i++) {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0) {
            start = i+1;
            defitcit += balance;
            balance = 0;
        }
    }

    if(defitcit + balance >= 0)
       return start;
    
    return -1;
}


int main()
{
    int n;
    cin>>n;

    petrolPump p[n];

    for(int i = 0;i<n;i++) {
        cin>>p[i].petrol>>p[i].distance;
    }

    cout<<"Answer : "<<tour(p, n)<<endl;
    return 0;
}