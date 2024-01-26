#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
    private:
    int V;
    vector<vector<int>> adj;
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& result);
};
Graph::Graph(int V) : V(V) {
    adj.resize(V);
}
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}
void Graph::topologicalSortUtil(int v, vector<bool>& visited, stack<int>& result) {
    visited[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            topologicalSortUtil(u, visited, result);
        }
    }
    result.push(v);
}
void Graph::topologicalSort() {
    stack<int> result;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, result);
        }
    }

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
}
class Graph {
    int V;
    vector<list<int>> adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
    bool isCyclicUtil(int v, bool visited, int parent);
};
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isCyclicUtil(int v, bool visited, int parent) {
    visited[v] = true;

    for (const auto& i : adj[v]) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, v))
                return true;
        }   else if (i != parent)
                return true;
    }
    return false;
}
bool Graph::isCyclic() {
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Topological Sort: ";
    g.topologicalSort();

    if (g.isCyclic())
        cout << "Graph contains a cycle." << "\n";
    else 
        cout << "Graph does not contain a cycle." << "\n";
    return 0;
}
