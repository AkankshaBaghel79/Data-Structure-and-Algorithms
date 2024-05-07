#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class specialstack{
    private:
    stack<int> s;
    int mini;

    public:
    void push(int data) {
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    void pop() {
        if(s.empty()) {
            return;
        }
        int curr = s.top();
        s.pop();
        if(curr < mini) {
            mini = 2*mini - curr;
        }
    }
    int top() {
        if(s.empty()) {
            return -1;
        }

        int data = s.top();
        if(data < mini) {
            return mini;
        }
        else {
            return data;
        }
    }
    int getmin() {
        if(s.empty()) return -1;

        return mini;
    }
};
