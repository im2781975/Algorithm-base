#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
};
class Queue{
    public:
    int size;
    node *head, *tail;
    Queue(){
        size = 0;
        head = NULL; tail = NULL;
    }
    node *create(int val){
        node *newnode = new node;
        newnode->nxt = NULL;
        newnode->data = val;
        return newnode;
    }
    void enqueue(int val){
        size++;
        node *newnode = create(val);
        if(size == 1)
            head = tail = newnode;
        else{
            tail->nxt = newnode;
            tail = newnode;
            return;
        }
    }
    void dequeue(){
        if(size == 0){
            cout << "Queue is empty";
            return;
        }
        if(size == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            node *a = head;
            head = head->nxt;
            delete a;
        }
        size--;
    }
    int getfront(){
        if(size == 0)
            return -1;
        return head->data;
    }
    int getsize(){
        return size;
    }
};
template<typename T>
class node{
    public:
    T data;
    node *nxt;
    node(T val):data(val), nxt(nullptr){}
};
template<typename T>
class Queue{
    node <T> *front, *rear;
    public:
    Queue():front(nullptr), rear(nullptr){}
    bool IsEmpty(){
        return front == nullptr;
    }
    void enqueue(T val){
        node <T> *newnode = new node<T>(val);
        if(front == rear){
            front = rear = newnode;
            return;
        }
        rear->nxt = newnode;
        rear = newnode;
    }
    void dequeue(){
        if(IsEmpty()){
            cout << "\nQueue is empty";
            return;
        }
        node <T> *tmp = front;
        front = front->nxt;
        delete tmp;
        if(front == nullptr)
            rear = nullptr;
    }
    T peek(){
        if(IsEmpty()){
            cout << "Queue is Empty";
            return T();
        }
        return front->data;
    }
};
int main(){
    Queue q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);
    cout << "Front element: " << q.getfront() << "\n";
    cout << "Size is: " << q.getsize() << "\n";
    q.dequeue();
    cout << "Front element: " << q.getfront() << "\n";
    cout << "Size is: " << q.getsize() << "\n";
    ////
    Queue <int> q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(7);
    cout << "\nFront: " << q.peek();
}
