//You are given a weighted undirected graph. The vertices are numbered from 1 to n.find the shortest path from the vertex 1 to n using the dijkstra algorithm.
#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
const int INF = INT_MAX;
// Define a structure to represent an edge
struct Edge {
    int to, weight;
};
// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(const vector<vector<Edge>>& graph, vector<int>& distance, int n) {
    set<pair<int, int>> minDistances; 
    // Set to keep track of minimum distances
    distance[1] = 0;
    minDistances.insert({0, 1});
    while (!minDistances.empty()) {
        int v = minDistances.begin()->second;
        minDistances.erase(minDistances.begin());

        for (const Edge& edge : graph[v]) {
            int to = edge.to;
            int weight = edge.weight;

            if (distance[v] + weight < distance[to]) {
                minDistances.erase({distance[to], to});
                distance[to] = distance[v] + weight;
                minDistances.insert({distance[to], to});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    vector<int> distance(n + 1, INF); 
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(graph, distance, n);
    if (distance[n] == INF) {
        cout << "There is no path from vertex 1 to vertex n." << endl;
    } else {
        cout << "Shortest path from vertex 1 to vertex " << n << " is: " << distance[n] << endl;
    }
    return 0;
}

