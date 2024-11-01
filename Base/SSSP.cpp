#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector <int> adj[maxn];
int dist[maxn];
void BFS(int src){
    queue <int> q;
    q.push(src); dist[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));
    int src; cin >> src;
    BFS(src);
    for(int i = 1; i <= node; i++)
        cout << dist[i] << " ";
}
