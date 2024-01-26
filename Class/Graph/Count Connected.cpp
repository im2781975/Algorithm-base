// count the number of connected components in undirected graph.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Graph {
public:
    int V;
    vector<set<int>> adj;
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }
    // DFS traversal to count connected components
    void DFS(int v, vector<bool> &visited) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                    DFS(neighbor,     visited);
            }
        }
    }
    // Count the number of connected components
    int countConnectedComponents(){
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, visited);
                count++;
            }
        }
        return count;
    }
};
class Graph {
    int V;
    vector<vector<int>> adj;
    public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int countConnectedComponents(){
        vector<bool> visited(V, false);
        int components = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                BFS(i, visited);
                components++;
            }
        }
        return components;
    }
    void BFS(int start, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};
int main() {
    int V, E;
    cout << "Enter the number of vertices & edges: ";
    cin >> V >> E;
    Graph g(V);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int components = g.countConnectedComponents();
    cout << "Number of connected components: " << components << "\n";
}
