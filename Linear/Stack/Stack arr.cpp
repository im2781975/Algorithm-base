#include<iostream>
#include<stack>
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
//Array Based Stack
class Stack{
    int arr[10], top;
    public:
    Stack():top(-1){}
    void push(int val){
        if(top < 9)
            arr[++top] = val;
        else{
            cout << "\nStack is full";
        }
    }
    int pop(){
        if(top >= 0)
            return arr[top--];
        else
            throw "Underflow";
    }
    bool IsEmpty(){
        return top == -1;
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
    //
    Stack st;
    for(int i = 1; i <= 5; i++){
        st.push(i);
        cout << st.pop() << " ";
    }
    cout << "\nIsEmpty: " << (st.IsEmpty()?"Yes":"No");
}
