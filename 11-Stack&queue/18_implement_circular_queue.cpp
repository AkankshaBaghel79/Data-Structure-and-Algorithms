#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class circularQueue {
    private:
    int *arr;
    int size;
    int front;
    int rear;

    public:
    circularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data) {
        //overflow condition
        if((front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1))) {
            return;
        }
        else if(front == -1) { //adding first element
            front = 0;
            rear = 0;
        }
        else if(rear == size - 1 && front != 0) { //handling the circular position
            rear = 0;
        }
        else { //Normal case
            rear++;
        }

        arr[rear] = data;
    }

    int dequeue() {
        //underflow condition
        if(front == -1) {
            return -1;
        }

        int data = arr[front];
        arr[front] = -1;
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else if(front == size-1) {
            front = 0;
        }
        else {
            front++;
        }

        return data;
    }
};


int main()
{
    
    return 0;
}