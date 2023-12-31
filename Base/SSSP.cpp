// single source shortest path(SSSP)
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAXN = 1005;
vector<int> graph[MAXN]; 
int dist[MAXN];     
// Array to store the shortest distances
void bfs(int source) {
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    // Initialize distance array to -1 (unreachable)
    memset(dist, -1, sizeof(dist));

    bfs(source);

    cout << "Shortest distances from source " << source << " to all other vertices:" << endl;
    for (int i = 1; i <= vertices; i++) {
        cout << "Distance to vertex " << i << " is " << dist[i] << endl;
    }
    return 0;
}
