// cycle detection in a directed graph using DFS.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
private:
    int V; 
    vector<vector<int>> adj;

    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }
        recStack[v] = false;
        return false;
    }
    public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    bool isCyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack))
                return true;
        }
        return false;
    }
};
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Graph graph(V);
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }
    if (graph.isCyclic()) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    return 0;
}
