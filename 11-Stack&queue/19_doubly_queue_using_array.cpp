#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class dequeue {
    private:
    int size;
    int *arr;
    int front;
    int rear;
    public:
    //constructor
    dequeue(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    //Push_front
    bool push_front(int x) {

        //overflow condition
        if(isfull()) {
            return false;
        }
        else if(front == -1) { //single element
            front = 0;
            rear = 0;
        }
        else if(front == 0 && rear != size - 1) { //circular nature
            front = size - 1;
        }
        else { //normal case
            front--;
        }

        arr[front] = x;
        return true;
    }

    //Push_back
    bool push_back(int x) {

        //overflow condition
        if(isfull()) {
            return false;
        }
        else if(front == -1) { //single element
            front = 0;
            rear = 0;
        }
        else if(front != 0 && rear == size - 1) { //circular nature
            rear = 0;
        }
        else { //normal case
            rear++;
        }

        arr[rear] = x;
        return true;
    }
     
    //Pop_front
    int pop_front() {

        //underflow condition
        if(isempty()) {
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //only single element
            front = -1;
            rear = -1;
        }
        else if(front == size - 1) { //circular nature
            front = 0;
        }
        else { //normal case
            front++;
        }
        return ans;
    }

    //Pop_back
    int pop_back() {
        //underflow condition
        if(isempty()) {
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear) { //only single element
            front = -1;
            rear = -1;
        }
        else if(rear == 0) { //circular nature
            rear = size - 1;
        }
        else { //normal case
            rear--;
        }
        return ans;
    }

    //isempty() 
    bool isempty() {
        if(front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    //isfull()
    bool isfull() {
        if((front == 0 && rear == size - 1) || (front != 0 && (rear == (front - 1)%(size - 1)))) {
            return true;
        }
        else {
            return false;
        }
    }

};

int main()
{
    
    return 0;
}