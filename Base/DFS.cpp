#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;
bool visited[n + 1];
vector <int> adj[n];
stack <int> st;
void DFS(int node){
    visited[node] = true;
    for(int child : adj[node]){
        if(!visited[child])
            DFS(child);
    }
    st.push(node);
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= node; i++){
        if(!visited[i])
            DFS(i);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
/***/
using namespace std;
const int n = 1e5;
vector <int> adj[n];
bool visited[n];
void DFS(int node){
    cout << node << " ";
    visited[node] = true;
    for(int child : adj[node]){
        if(!visited[child])
            DFS(child);
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    fill(visited, visited + node, false);
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0);
}
