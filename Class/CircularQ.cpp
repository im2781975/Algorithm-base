#include<bits/stdc++.h>
using namespace std;
template<typename T>
class CircularQ{
    T *arr;
    int front, rear, cap;
    public:
    CircularQ(int sz){
        cap = sz;
        arr = new T[cap];
        front = rear = -1;
    }
    bool IsEmpty(){
        return front == -1;
    }
    // rear is one position behind front ((rear + 1) % capacity == front).
    bool IsFull(){
        return ((front == 0 && rear == cap - 1)||(rear == (front -1) % (cap - 1)));
    }
    void enqueue(T item){
        if(IsFull()){
            cout << "\nQueue is full";
            return;
        }
        if(IsEmpty()){
            front = rear = 0;
            arr[rear] = item;
        }
        else{
            rear = (rear + 1)% cap;
            arr[rear] = item;
        }
    }
    T dequeue(){
        if(IsEmpty()){
            cout << "\nQueue is empty";
            return T();
        }
        T item = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else
            front = (front + 1)%cap;
        return item;
    }
    T getFront(){
        if(IsEmpty()){
            cout <<"\nQueue is empty";
            return T();
        }
        return arr[front];
    }
};
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
    //For template base
    CircularQ <int >q(5);
    CircularQ q(5);
    cout << "\nFront Elements are: ";
    for(int i = 1; i <= 5; i++){
        q.enqueue(i);
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << "\nFront element: " << q.getFront() << endl;
    q.enqueue(6);
    cout << "\nFront element after dequeue and enqueue: " << q.getFront() << endl;
}
