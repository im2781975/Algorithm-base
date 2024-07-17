#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
    node(int val):data(val), nxt(nullptr){}
};
class Singly{
    int size;
    node *head;
    public:
    Singly():size(0), head(nullptr){}
    void InsertFront(int val){
        size++;
        node *newnode = new node(val);
        node *a = head;
        if(head == nullptr)
            head = newnode;
        newnode->nxt = head;
        head = newnode;
    }
    int GetVal(int idx){
        if(idx < 0 || idx > size)
            return -1;
        node *a = head;
        int curIdx = 0;
        while(a !=nullptr && cur_idx != idx){
            a = a->nxt;
            curIdx++;
        }
        if(a !=nullptr)
            return a->data;
        return -1;
    }
    bool GetVal(int val){
        node *a = head;
        while(a!=NULL){
            if(a->data == val)
                return true;
            a = a->nxt;
        }
        return false;
    }
    void Append(int val){
        node *newnode = new node(val);
        if(head == nullptr){
            head =  newnode;
            return;
        }
        else {
            node *a = head;
            while(a->nxt !=nullptr)
                a = a->nxt;
            a->nxt = newnode;
        }
        size++;
    }
    void RemoveZero(){
        node *a = head;
        while(a!=nullptr && a->data == 0){
            node *tmp = head;
            head = head->nxt;
            delete tmp;
            size--;
        }
        if(head == nullptr)
            return;
        node *a = head;
        while(a->nxt !=nullptr){
            if(a->nxt->data == 0){
                node *tmp = a->nxt;
                a->nxt = a->nxt->nxt;
                delete tmp;
                size--;
            }
            else
                a = a->nxt;
        }
    }
    void RemoveFront(){
        if(head == nullptr)
            return;
        while(head !=nullptr){
            node *a = head;
            head = head->nxt;
            delete a;
            size--;
        }
    }
    int GetSum(){
        node *a = head;
        int idx = 0, sum = 0;
        while(a !=nullptr){
            if(idx%2 == 1)
                sum += a->data;
            idx++;
            a = a->nxt;
        }
        return sum;
    }
    void RemoveLast(){
        if(head == nullptr)
            return;
        while(head !=nullptr){
            
            if(head->nxt == nullptr){
                delete head;
                head = nullptr;
            }
            else {
                node *cur = head;
                while(cur->nxt->nxt!=nullptr)
                    cur = cur->nxt;
                delete cur->nxt;
                cur->next = nullptr;
            }
        }
        size--;
    }/*
    int GetVal(int idx){
        node *cur = head;
        int curIdx = 0;
        while(cur!=nullptr){
            if(curIdx == idx )
                return cur->data;
            cur = cur->nxt;
            curIdx++;
        }
        return -1;
    }*/
    int GetVal(int idx){
        node *cur = head;
        int curIdx = 0;
        while(cur !=nullptr && curIdx < idx){
            cur = cur->nxt;
            curIdx++;
        }
        if(a !=nullptr)
            return a->data;
        return -1;
    }
    bool HasDuplicate(){
        node *a = head;
        while(a!=nullptr){
            node *b = a->nxt;
            while(b!=nullptr){
                if(a->data == b->data)
                    return true;
                b = b->nxt;
            }
            a = a->nxt;
        }
        return false;
    }
    void sortList(){
        if(head == nullptr || head->nxt == nullptr)
            return;
        node *a = head;
        bool swaped = true;
        node *b = nullptr;
        do {
            swaped = false;
            while(a->nxt !=b){
                if(a->data > a->nxt->data){
                    swap(a->data, a->nxt->data);
                    swaped = true;
                }
                a = a->nxt;
            }
            b = a;
        } while(swaped);
    }
};
