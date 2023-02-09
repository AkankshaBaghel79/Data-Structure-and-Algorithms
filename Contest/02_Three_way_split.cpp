#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

long long threeWaySplit(int n, vector<int> arr){
    // Write your code here.
    if(n == 1){
        return 0;
    }
    
    long long ans = 0;

    int i = 0;
    int j = n - 1;

    long long front = arr[i];
    i++;
    
    long long last = arr[j];
    j--;

    if(front == last){
        ans = front;
    }

    while(i <= j){

        if(front < last){
            front += arr[i];
            i++;
        }
        else{
            last += arr[j];
            j--;
        }
        if (front == last) {
          ans = front;
        }
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<threeWaySplit(n, arr);

    return 0;
}