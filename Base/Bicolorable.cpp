#include<bits/stdc++.h>
// M Coloring problem using backtracking
using namespace std;
#define node 4
bool IsSafe(int src, int graph[node][node], int color[], int type){
    for(int v = 0; v < node; v++){
        if(graph[src][v] && type == color[v])
            return false;
    }
    return true;
}
bool graphcolor(int graph[node][node], int num, int color[], int src){
    if(src == node)
        return true;
    for(int i = 1; i <= num; i++){
        if(IsSafe(src, graph, color, i)){
            color[src] = i;
            if(graphcolor(graph, num, color, src + 1))
                return true;
                 //If assigning color c doesn't lead to a solution then remove it
            color[src] = 0;
        }
    }
    return false;
}
void print(int color[]){
    for(int i = 0; i < node; i++)
        cout << color[i] << " ";
}
int main(){
    int graph[node][node] = {
        { 0, 1, 1, 1 }, { 1, 0, 1, 0 },
        { 1, 1, 0, 1 }, { 1, 0, 1, 0 },
    };
    int num = 3; 
    //represent the color type
    int color[node] = {0}
    for(int i = 0; i < node; i++)
        color[i] = 0;
    for(int i = 0; i < node; i++){
        if(graphcolor(graph, num, color, 0) == false){
            cout << "Solution doesn't exit";
            return 0;
        }
    }
    print(color);
}
using namespace std;
const int n = 1e5;
int visited[n + 1];
int color[n];
vector <int> adj[n + 1];
bool DFS(int u, int type){
    visited[u] = 1;
    color[u] = type;
    for(int v : adj[u]){
        if(!visited[v]){
            if(!DFS(v, 3 - type))
                return false;
        }
        else if(color[v] == color[u])
            return false;
    }
    return true;
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool IsBicolorable = true;
    for(int i = 1; i <= node; i++){
        if(!visited[i]){
            bool ok = DFS(i, 1);
            if(!ok){
                IsBicolorable = false;
                break;
            }
        }
    }
    if(!IsBicolorable)
        cout << "Impossible";
    else{
        for(int i = 1; i <= node; i++)
            cout << color[i] << " ";
    }
}
