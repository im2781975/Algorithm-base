#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *nxt, *prv;
    node(int val):data(val), nxt(NULL), prv(NULL){}
};
class Deque{
    public:
    //rev operator in the Deque class is a flag used to 
    //reverse the direction of the deque operations. When the rev flag is set, 
    //operations that typically affect the front of the deque will affect the back, and vice versa
    //When rev is 0, the deque operates normally.
    //When rev is 1, the deque operations are reversed

    int size, rev;
    node *head, *tail;
    Deque():size(0), rev(0), head(NULL), tail(NULL){}
    node *create(int val){
        node *newnode =new node(val);
        newnode->nxt= NULL;
        newnode->prv = NULL;
        return newnode;
    }
    void push_back(int val){
        node *newnode = create(val);
        if(size == 0){
            head = newnode;
            tail = newnode;
            size++; return;
        }
        newnode ->prv = tail;
        tail ->nxt = newnode;
        tail = newnode;
        size++; return;
    }
    void push_front(int val){
        node *newnode = create(val);
        if(size == 0){
            head = newnode;
            tail = newnode;
            size++; return;
        }
        newnode->nxt = head;
        head->prv = newnode;
        head = newnode;
        size++; return;
    }
    void InsertBack(int val){
        if(rev == 0)
            push_back(val);
        else
            push_front(val);
    }
    void InsertFront(int val){
        if(rev == 0)
            push_front(val);
        else
            push_back(val);
    }
    void pop_back(){
        if(size == 0){
            cout << "\nDeque is Empty";
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            node *b = tail;
            tail = b->prv;
            tail->nxt = NULL;
            delete b;
        }
        size--;
    }
    void pop_front(){
        if(size == 0)
            cout << "\nDeque is Empty";
        else if(head == tail){
            node *a = head;
            head = tail = NULL;
            delete a; 
            size--; return;
        }
        else{
            node *b = head;
            head = head->nxt;
            delete b;
            head->prv = NULL;
            size--; return;
        }
    }
    void EraseBack(){
        if(rev == 0)
            pop_back();
        else
            pop_front();
    }
    void EraseFront(){
        if(rev == 0)
            pop_front();
        else
            pop_back();
    }
    
    int Front(){
        if(size == 0)
            return -1;
        else
            return (rev == 0) ? head->data : tail->data;
    }
    int Back(){
        if(size == 0)
            return -1;
        else
            return (rev == 0) ? tail->data : head->data;
    }
    void Reverse(){
        if(rev == 0)
            rev = 1;
        else
            rev = 0;
    }
    int getsize(){
        return size;
    }
};
int main(){
    Deque d;
    d.push_back(5);
    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    d.Reverse();
    while (d.getsize() > 0) {
        cout << "Back: " << d.Back() << ", Front: " << d.Front() << "\n";
        d.pop_back();
    }
}
