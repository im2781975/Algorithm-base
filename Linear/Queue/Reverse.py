#include<bits/stdc++.h>
using namespace std;
void print(queue <int> &q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
void reverse(queue <int> &q){
    if(q.size() == 0)
        return;
    int first = q.front();
    q.pop();
    reverse(q);
    q.push(first);
}
void Reverse(queue <int> &q){
    stack <int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
};
// reverse first k elements of a queue.
void ReverseFirst(int k, queue <int> &q){
    if(q.empty() || k > q.size())
        return;
    if(k <= 0)
        return;
    stack <int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 0; i < q.size() - k; i++){
        q.push(q.front());
        q.pop();
    }
}
// Function to reverse first k elements of a queue
void solve(queue <int> q, int k){
    if(k == 0)
        return;
    int first = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(first);
}
queue <int> ReverseFirst(queue <int> q, int k){
    solve(q, k);
    int size = q.size() - k;
    while(size-- > 0){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
int main(){
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    reverse(q);
    Reverse(q);
    print(q);
    //
    queue <int> q;
    for(int i = 10; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    ReverseFirst(k, q);
    print(q);
    //
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    // Need to store the value in a queue
    q = ReverseFirst(q, k);
    print(q);
}
