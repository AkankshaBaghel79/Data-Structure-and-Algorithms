#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class NStack{
    private:
    int n, s;
    int *arr;
    int *top;
    int *next;
    int freespot;
    public:
    NStack(int N, int S) {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top intialize
        for(int i = 0;i<n;i++)
        {
            top[i] = -1;
        }

        //next initalize 
        for(int i = 0;i<s;i++)
        {
            next[i] = i+1;
        }

        //update the last index of next
        next[s-1] = -1;

        freespot = 0;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        //check overflow
        if(freespot == -1) return false;

        //find index
        int index = freespot;

        //push x
        arr[index] = x;

        //update freespot
        freespot = next[index];

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        //check underflow
        if(top[m-1] == -1) return -1;

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};