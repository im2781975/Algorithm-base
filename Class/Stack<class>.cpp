#include<iostream>
using namespace std;
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
    for(int i = 1; i <= 5; i++){
        st.push(i);
        cout << st.pop() << " ";
    }
    cout << "\nIsEmpty: " << (st.IsEmpty()?"Yes":"No");
}
