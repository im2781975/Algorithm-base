#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class DynamicStack{
    vector <T> vect;
    public:
    bool IsEmpty(){
        return vect.empty();
    }
    void Push(T value){
        vect.push_back(value);
    }
    void Pop(){
        if(!IsEmpty())
            vect.pop_back();
    }
    T Top(){
        if(!IsEmpty())
            return vect.back();
        else
            throw "exception";
    }
    size_t size(){
        return vect.size();
    }
};
int main(){
    DynamicStack<int> st;
    for(int i = 2; i <= 10; i+= 2)
        st.Push(i);
    while(!st.IsEmpty()){
        cout << st.Top() << " ";
        st.Pop();
    }
    cout << "\nSize is: " << st.size();
}
