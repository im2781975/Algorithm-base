#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node *nxt, *prv;
    node(T val):data(val), nxt(nullptr), prv(nullptr){}
};
template<typename T>
class Deque{
    node <T> *head, *tail;
    size_t size;
    public:
    Deque():head(nullptr), tail(nullptr), size(0){}
    void push_back(T val){
        node <T> *newnode = new node<T>(val);
        if(size == 0)
            head = tail = newnode;
        else{
            newnode->prv = tail;
            tail->nxt = newnode;
            tail = newnode;
        }
        size++;
    }
    void push_front(T val){
        node <T> *newnode = new node<T>(val);
        if(size == 0)
            head = tail = newnode;
        else{
            newnode->nxt = head;
            head ->prv = newnode;
            head = newnode;
        }
        size++;
    }
    void pop_front(){
        if(size == 0)
            cout << "\nDeque is empty";
        if(size == 1){
            delete head;
            head = tail = NULL;
        }
        else{
            node <T>*tmp = head;
            head = head->nxt;
            head->prv = NULL;
            delete tmp;
        }
    }
    void pop_back(){
        if(size == 0)
            cout << "\nDeque is empty";
        if(size == 1)
        {
            delete tail;
            head = tail = NULL;
        }
        else{
            node<T>*tmp = tail;
            tail = tail->prv;
            tail->nxt = NULL;
            delete tmp;
        }
        size--;
    }
    T Front(){
        if(size == 0){
            cout << "Deque is Empty";
            return T();
        }
        else
            return head->data;
    }
    T Back(){
        if(size == 0){
            cout << "Deque is empty";
            return T();
        }
        else
            return tail->data;
    }
    T getsize(){
        return size;
    }
};
int main(){
    Deque <int> d;
    d.push_back(5);
    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    while(d.getsize() > 0){
        cout << "Back: " << d.Back() << ", Front: " << d.Front() << "\n";
        d.pop_back();
    }
}
