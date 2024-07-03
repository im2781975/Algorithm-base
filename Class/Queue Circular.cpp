#include<bits/stdc++.h>
using namespace std;
class CircularQ{
    int *arr, size, front, rear;
    public:
    CircularQ(int sz){
        size = sz;
        arr = new int[size];
        front = rear = -1;
    }
    bool IsEmpty(){
        //Front == -1.indicating the idx
        return (front == -1 && rear == -1);
    }
    bool IsFull(){
        return(front == (rear + 1)% size);
    }
    void enqueue(int data){
        if(IsFull()){
            cout << "Queue is Full";
            return;
        }
        if(IsEmpty())
            front = rear = 0;
        else
            rear = (rear + 1)%size;
        arr[rear] = data;
    }
    void dequeue(){
        if(IsEmpty()){
            cout << "\nQueue is Empty";
            return;
        }
        //cout << "\nElements are : " << arr[front] << " ";
        // If there is only one element (when front equals rear), it sets both to -1 indicating the queue is now empty.
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1)%size;
    }
    int getFront(){
        if(IsEmpty()){
            cout << "Queue Is empty";
            return 1;
        }
        else
            return arr[front];
    }
    ~CircularQ(){
        delete []arr;
    }
};
int main(){
    CircularQ q(5);
    cout << "Front Elements are: \n";
    for(int i = 1; i <= 5; i++){
        q.enqueue(i);
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << "\nFront element: " << q.getFront() << endl;
    q.enqueue(6);
    cout << "\nFront element after dequeue and enqueue: " << q.getFront() << endl;

}
