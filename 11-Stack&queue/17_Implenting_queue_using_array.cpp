#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class queue {
    private: 
    int* arr;
    int size;
    int qfront;
    int rear;

    /*----------------- Public Functions of Queue -----------------*/
    public:
    queue(){
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data) {
        //overflow
        if(rear == size) {
            cout<<"Overflow"<<endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }
    bool isempty() {
        if(qfront == rear) return true;
        else return false;
    }
    int dequeue() {
        //underflow
        if(qfront == rear) return -1;
        else {
            int data = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return data;
        }
    }
    int front() {
        if(qfront == rear) return -1;
        else return arr[qfront];
    }
};

int main()
{
    
    return 0;
}