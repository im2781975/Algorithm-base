#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt, *prv;
    node(int val):data(val), nxt(nullptr), prv(nullptr){}
};
class Doubly{
    public:
    node *head, *tail;
    Doubly():head(nullptr), tail(nullptr){}
    void InsertFront(int val){
    node *newnode = new node(val);
        if(head == nullptr)
            head = tail = newnode;
        else {
            newnode->nxt = head;
            head->prv = newnode;
            head = newnode;
        }
    }
    void RemoveBack(){
        if(tail == nullptr)
            cout << "underflow";
        if(head == tail)
            head = tail = nullptr;
        else{
            node *tmp = tail;
            tail = tail ->prv;
            tail ->nxt = nullptr;
            delete tmp;
        }
    }
    void RemoveFront(){
        if(head == nullptr)
            cout << "Underflow";
        if(head == tail)
            head = tail = nullptr;
        else{
            node *tmp = head;
            head = head->nxt;
            head->prv = nullptr;
            delete tmp;
        }
    }
    int SearchIdx(int idx){
        node *a = head;
        int curIdx = 0;
        while(a !=nullptr && curIdx < idx){
            a = a-> nxt;
            curIdx++;
        }
        if(a == nullptr){
            cout << "Idx doesn't found";
            return -1;
        }
        return a->data;
    }
    bool SearchDistinct(int val){
        node *a = head;
        while(a !=nullptr){
            if(a->data == val)
                return true;
            a = a->nxt;
        }
        return false;
    }
    void Reverse(){
        node *tmp = nullptr;
        node *a = head;
        while(a !=nullptr){
            tmp = a ->prv;
            a ->prv = a->nxt;
            a->nxt = tmp;
            a = a->prv;
        }
        if(tmp !=nullptr)
            head = tmp->prv;
    }
    void Insert(int idx, int val){
        if(idx == 0)
            InsertFront(val);
        else{
            node *newnode = new node(val);
            node *a = head;
            int cur = 0;
            while(a!=nullptr && cur < idx){
                a = a->nxt;
                cur++;
            }
            if(a == nullptr){
                cout << "Idx not found";
                delete newnode;
                return;
            }
            newnode ->nxt = a->nxt;
            newnode->prv = a;
            if(a->nxt!=NULL){
                a->nxt->prv = newnode;
            }
            a->nxt = newnode;
            if(newnode->nxt == nullptr)
                tail = newnode;
        }
    }
    void Erase(int val){
        node *a = head;
        while(a!=nullptr){
            if(a->data == val){
                if(a->prv!=NULL)
                    a->prv->nxt = a->nxt;
                if(a->nxt!=NULL)
                    a->nxt->prv = a->prv;
                if(a == head)
                    head = a ->nxt;
                if(a == tail)
                    tail = a->prv;
                delete a;
                return;
            }
            a = a->nxt;
        }
        cout << "Value doesn't exits";
    }
    bool IsPalindrome(){
        node *a = head;
        node *b = tail;
        if(a!=nullptr && b!=nullptr && a !=b && b->nxt !=a){
            if(a->data != b->data)
                return false;
            a = a->nxt;
            b = b->prv;
        }
        return true;
    }
    void Display(){
        node *a = head;
        while(a !=nullptr){
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
};
int main(){
    Doubly Dl;
    for(int i = 0; i <= 10; i+= 2)
        Dl.InsertFront(i);
    Dl.Display();
    Dl.Reverse();
    Dl.Display();
    (Dl.IsPalindrome())? cout << "Yes": cout << "No";
    return 0;
}
