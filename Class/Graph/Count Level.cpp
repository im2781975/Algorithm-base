//count the level of each node of a graph.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    bool DFS(int src, int dest) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        stack<int> s;
        s.push(src);
        visited[src] = true;

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    parent[v] = u;
                    visited[v] = true;
                    s.push(v);
                }
            }
        }
        if (!visited[dest]) {
            cout << "Path from " << src << " to " << dest << " does not exist." << endl;
            return false;
        }
        // Print the path from src to dest
        vector<int> path;
        int current = dest;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        cout << "Path from " << src << " to " << dest << ": ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) {
                cout << " -> ";
            }
        }
        cout << "\n";
        return true;
    }
};
//print path
class Graph {
public:
    int V; 
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    void countLevels(int source) {
        vector<int> level(V, -1);
        queue<int> q;
        level[source] = 0;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (level[v] == -1) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << "Levels of nodes starting from node " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": Level " << level[i] << "\n";
        }
    }
};
int main() {
    int V = 6;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    
    int source = 3;
    graph.countLevels(source);
    
    int destination = 6;
    if (graph.DFS(source, destination)) 
        cout << "\nPath Exits.";
    else
        cout << "\nPath doesn't exits."
    return 0;
}
