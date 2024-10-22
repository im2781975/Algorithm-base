#include<bits/stdc++.h>
using namespace std;
const int n = 1e5 + 5;
bool visited[n];
int dist[n];
int node, edge;
vector <pair <int, int> >adj[n];
void Dijkstra(int src){
    for(int i = 1; i <= node; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(int i = 0; i < node; i++){
        int select = -1;
        for(int j = 1; j <= node; j++){
            if(visited[j])
                continue;
            if(select == -1 || dist[select] > dist[j])
                select = j;
        }
        visited[select] = 1;
        for(auto u : adj[select]){
            int v = u.first;
            int w = u.second;
            if(dist[select] + w < dist[v])
                dist[v] = dist[select] + w;
        }
    }
}
int main(){
    cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(1);
    for(int i = 1; i <= node; i++)
        cout << dist[i] << " ";
}
/***/
using namespace std;
int minDist(vector <int> dist, vector <bool> visited, int node){
    int mini = INT_MAX, minidx;
    for(int i = 0; i < node; i++){
        if(!visited[i] && dist[i] <= mini){
            mini = dist[i];
            minidx = i;
        }
    }
    return minidx;
}
void Dijkstra(vector <vector <int> > &graph, int src, int node){
    vector <int> dist(node, INT_MAX);
    vector <bool> visited(node, false);
    dist[src] = 0;
    for(int i = 0; i < node - 1; i++){
        int u = minDist(dist, visited, node);
        visited[u] = true;
        for(int v = 0; v < node; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v]) < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    for(int i = 0; i < node; i++)
        cout << i << "\t" << dist[i] << "\n";
}
int main(){
    int node; cin >> node;
    vector <vector <int> >graph(node, vector <int>(node));
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++)
            cin >> graph[i][j];
    }
    int src; cin >> src;
    Dijkstra(graph, src, node);
}
