#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;

int minDistance(vector<int>& dist, vector<bool>& sp, int n) {
    int minDist = INF, minIndex;

    for (int i = 0; i < n; i++) {
        if (!sp[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void dijkstra(vector<vector<int>>& graph, int src, int n) {
    vector<int> dist(n, INF);
    vector<bool> sp(n, false);

    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, sp, n);
        sp[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sp[v] && graph[u][v] && dist[u] != INF && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}
int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    dijkstra(graph, src, n);
    return 0;
}

