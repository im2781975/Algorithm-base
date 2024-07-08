#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node *nxt;
    node(T val):data(val), nxt(nullptr){}
};
template<typename T>
class Stack{
    public:
    node <T> *head;
    Stack():head(nullptr){}
    void Push(T val){
        node <T> *newnode = new node <T> (val);
        newnode ->nxt = head;
        head = newnode;
    }
    void Pop(){
        if(head!=NULL){
            node <T> *tmp = head;
            head = head->nxt;
            delete tmp;
        }
        else
            cout << "Stack is empty";
    }
    T peek(){
        if(head!=NULL)
            return head->data;
        else
            throw "stack is empty";
    }
    bool IsEmpty(){
        return head == nullptr;
    }
    ~Stack(){
        while(!IsEmpty()){
            Pop();
        }
    }
};
int main(){
    Stack <int> st;
    for(int i = 1; i <= 10; i+=2)
        st.Push(i);
    while(!st.IsEmpty()){
        cout << st.peek() << " ";
        st.Pop();
    }
    Stack <string> stringStack;
    stringStack.Push("Hello");
    stringStack.Push("World");
    cout << "\nTop element of string stack: " << stringStack.peek() ;
    return 0;
}
