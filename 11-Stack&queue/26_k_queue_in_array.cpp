#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

class kqueue {

    private:
        int n;
        int k;
        int *front;
        int *rear;
        int *next;
        int *arr;
        int freespot;
    public:
        kqueue(int n, int k) {
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for(int i = 0;i<k;i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
            next = new int[n];
            for(int i = 0;i<n;i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freespot = 0;
        }

        //Push data in queue
        void enqueue(int data, int q) {
            //check overflow condition
            if(freespot == -1) {
                cout<<"Oops array is full"<<endl;
                return;
            }

            //find index
            int index = freespot;

            //update freespot
            freespot = next[index];

            //check if it's the first element of the queue
            if(front[q-1] == -1) {
                front[q-1] = index;
            }
            else {
                next[rear[q-1]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[q-1] = index;

            //push element
            arr[index] = data;
        }

        //Pop data in queue
        int dequeue(int q) {
            //underflow condition
            if(front[q-1] == -1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            //find index to pop
            int index = front[q-1];

            //change front to next element in the queue
            front[q-1] = next[index];

            //manage the freeslots in the array
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }   
};

int main()
{
    kqueue q(10, 3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}