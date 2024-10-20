#include<bits/stdc++.h>
using namespace std;
const int n = 1e5;
int visited[n];
vector <int> adj[n];
bool DetectCycle(int node){
    visited[node] = 1;
    for(int child : adj[node]){
        // visited[0] = unexplored
        // visited[1] = paused | cycle detected
        // visited[2] = done | continue
        if(!visited[child]){
            bool gotCycle = DetectCycle(child);
            if(gotCycle)
                return true;
        }
        else if(visited[child] == 1)
            return true;
    }
    visited[node] = 2;
    return false;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    bool CycleExits = false;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool gotCycle = DetectCycle(i);
            if(gotCycle){
                CycleExits = true;
                break;
            }
        }
    }
    (CycleExits)?cout << "Cycle Exits" : cout << "Doesn't exits";
}
/***/
// detect cycle in an undirected graph using BFS.
using namespace std;
bool IsCyclicConnected(vector <int> adj[], int v, vector <bool> &visited){
    vector <int> parent(visited.size(), -1);
    queue <int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int child : adj[u]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
                parent[child] = u;
            }
            else if(parent[u] != child)
                return true;
        }
    }
    return false;
}
bool IsCyclicDisconnected(vector <int> adj[], int node){
    vector <bool> visited(node, false);
    for(int v = 0; v < node; v++){
        if(!visited[v] && IsCyclicConnected(adj, v, visited))
            return true;
    }
    return false;
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> adj[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    (IsCyclicDisconnected(adj, node)) ? cout << "Yes" : cout << "No";
}
