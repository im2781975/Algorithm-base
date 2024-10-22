#include<iostream>
#include<vector>
#include<climits>
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
