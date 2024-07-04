#include<bits/stdc++.h>
using namespace std;
class Queue{
    int *arr, front, rear, size, cur_size;
    public:
    Queue(int sz){
        size = sz;
        arr = new int[size];
        front = 0; rear = -1;
        cur_size = 0;
    }
    void enqueue(int val){
        if(cur_size == size)
            cout << "Queue is Full";
        rear++;
        rear = rear % size;
        arr[rear] = val;
        cur_size++;
    }
    void dequeue(){
        if(cur_size == 0)
            cout << "Empty";
        front++;
        front = front % size;
        cur_size--;
    }
    int getsize(){
        return size;
    }
    int getfront(){
        if(cur_size == 0)
            return -1;
        return arr[rear];
    }
};
class StaticQ{
    int arr[100], frontIdx, rareIdx;
    public:
    StaticQ(){
        frontIdx = -1; 
        rareIdx = -1;
    }
    bool IsEmpty(){
        return frontIdx == -1;
    }
    bool IsFull(){
        return rareIdx == 99;
    }
    void enqueue(int item){
        if(IsFull())
            cout << "\nQueue is full";
        else{
            if(IsEmpty())
                frontIdx = 0;
            arr[++rareIdx] = item;
        }
    }
    void dequeue(){
        if(IsEmpty())
            cout << "queue is empty";
        else{
            if(frontIdx == rareIdx)
                frontIdx = rareIdx = -1;
            else
                frontIdx++;
        }
    }
    int getfront(){
        if(IsEmpty()){
            cout << "Queue is empty";
            return -1;
        }
        else
            return arr[frontIdx];
    }
};
int main(){
    Queue q(5);
    cout << "Elements are: ";
    for(int i = 1; i < 6; i++){
        q.enqueue(i);
        cout << q.getfront() << " ";
    }
    StaticQ q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(8);
    cout << "Front: " << q.getfront();
}
