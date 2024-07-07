#include<iostream>
#include<stdexcept>
using namespace std;
template<typename T>
class DynamicQ{
    T *arr;
    int cap, front, rear, size;
    public:
    DynamicQ(int cap){
        this->cap = cap;
        arr = new T[cap];
        front = rear = -1;
        size = 0;
    }
    ~DynamicQ(){
        delete []arr;
    }
    bool IsEmpty(){
        return size = 0;
    }
    void enqueue(T data){
        if(size == cap){
            int newcap = cap*2;
            T *newarr = new T[newcap];
            for(int i = 0; i < size; i++)
                newarr[i] = arr[(front + i)%cap];
            delete []arr;
            arr = newarr;
            cap = newcap;
            front = 0; rear = size -1;
        }
        rear = (rear + 1)%cap;
        arr[rear] = data;
        size++;
    }
    void dequeue(){
        if(IsEmpty()){
            cout << "\nQueue is Empty";
            return;
        }
        front = (front + 1)%cap;
        size--;
    }
    T getFront(){
        if(IsEmpty()){
            cout << "Queue is Empty";
        }
        return arr[front];
    }
    int getsize(){
        return size;
    }
};
template<typename T>
class CircularQ{
    T arr[10];
    int front, rear, Itemcount;
    public:
    CircularQ(){
        front = rear = -1;
        Itemcount = 0;
    }
    bool IsEmpty(){
        return Itemcount == 0;
    }
    bool IsFull(){
        return Itemcount == 10;
    }
    int size(){
        return Itemcount;
    }
    void enqueue(int val){
        if(IsEmpty())
            front = rear = 0;
        if(IsFull()){
            cout << "Queue is full";
            return;
        }
        arr[rear] = val;
        rear = (rear + 1)%10;
        Itemcount++;
    }
    T dequeue(){
        if(IsEmpty()){
            cout << "Queue is empty";
            return T();
        }
        int item = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else
            front = (front + 1)%10;
        Itemcount--;
        return item;
    }
};
int main(){
    DynamicQ<int>q(5);
    cout << "Front Elements are: \n";
    for(int i = 1; i <= 5; i++){
        q.enqueue(i);
        cout << q.getFront() << " ";
        q.dequeue();
    }
    ////
    CircularQ <int> q;
    for(int i = 1; i <= 10; i++){
        q.enqueue(i * 10);
        cout << q.dequeue() << " ";
    }
    cout << "\nSizeof queue is: " << q.size();
}
