#include<bits/stdc++.h>
using namespace std;
//count the number of connected components in an undirected graph.
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector <int> adj[], int u, vector <bool> &visited){
    visited[u] = true;
    for(int v = 0; v < adj[u].size(); v++){
        if(!visited[adj[u][v]])
            DFS(adj, adj[u][v], visited);
    }
}
int main(){
    int node = 5; 
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    vector <bool> visited(node, false);
    int cnt = 0;
    for(int u = 0; u < node; u++){
        if(!visited[u]){
            DFS(adj, u, visited);
            cnt++;
        }
    }
    cout << cnt;
}
