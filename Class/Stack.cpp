#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *nxt, *prv;
    node(int val):data(val), nxt(NULL), prv(NULL){}
};
class Stack{
    public:
    node *head, *tail;
    int size = 0;
    Stack(){
        head = tail = NULL;
    }
    bool IsEmpty(){
        if(size == 0)
            return true;
        return false;
    }
    void Push(int val){
        size++;
        node *newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        tail ->nxt = newnode;
        newnode -> prv = tail;
        tail = newnode;
    }
    void Pop(){
        if(IsEmpty())
            return;
        else{
            size--;
            node *tmp = tail;
            if(tail ->prv!=NULL){
                tail = tail->prv;
                tail->nxt = NULL;
            }
            else
                head = tail = NULL;
            delete tmp;
        }
    }
    int GetSize(){
        return size;
    }
    int Top(){
        return tail->data;
    }
};
int main(){
    Stack st;
    for(int i = 0; i < 6; i++){
        st.Push(i);
    }
    while(!st.IsEmpty()){
        cout << st.Top() << " ";
        st.Pop();
    }
}
