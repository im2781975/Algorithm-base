//find  the largest length of a path
#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int n;
    vector<vector<int>> adj;
    public:
    Graph(int nodes) {
        n = nodes;
        adj.resize(n);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        int max_depth = 0;
        for (int u : adj[v]) {
            if (!visited[u]) {
                int depth = DFS(u, visited);
                max_depth = max(max_depth, depth);
            }
        }
        return max_depth + 1;
    }
    int findLongestPath() {
        int longest_path = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            longest_path = max(longest_path, DFS(i, visited));
        }
        return longest_path - 1; // Subtract 1 because we count edges, not nodes
    }
};
//check is Bidirectional
class Graph {
public:
    int vertices;
    unordered_map<int, set<int>> adjList;
    Graph(int v) {
        vertices = v;
    }
    void addEdge(int u, int v) {
        adjList[u].insert(v);
    }

    bool isBiDirectional() {
        for (const auto& pair : adjList) {
            int u = pair.first;
            for (int v : pair.second) {
        // checks if there is an edge from v to u in the adjacency list. This is done using adjList[v].find(u) == adjList[v].end(), which checks if the vertex u is present in the list of neighbors of v.
                if (adjList[v].find(u) == adjList[v].end()) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    int longest_path = graph.findLongestPath();
    cout << "The longest path in the graph is of length: " << longest_path << endl;
    
    if (graph.isBiDirectional()) {
        cout << "The graph is bi-directional." << endl;
    } else {
        cout << "The graph is not bi-directional." << endl;
    }
    return 0;
}
