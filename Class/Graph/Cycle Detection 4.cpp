//detect cycle in a graph
#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    // Pointer to an array containing adjacency lists
    list<int>* adj;
    // Used by isCyclic()
    bool isCyclicUtil(int v, bool visited[], bool* rs);
    public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[], bool* recStack)
{
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;
    // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]
                && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    // Remove the vertex from recursion stack
    recStack[v] = false;
    return false;
}
// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited
    // and not part of recursion stack
    bool* visited = new bool[V];
    bool* recStack = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
        if (!visited[i]
            && isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}
class Graph {
private:
    int V; 
    vector<vector<int> > adj;
 
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int v, int w) { adj[v].push_back(w); }
 
    bool isCyclic()
    {
        vector<int> inDegree(
            V, 0); 
        // stores in-degree of each vertex
        queue<int>q; 
        // queue to store vertices with 0 in-degree
        int visited = 0; 
        // count of visited vertices
        // calculate in-degree of each vertex
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                inDegree[v]++;
            }
        }
 
        // enqueue vertices with 0 in-degree
        for (int u = 0; u < V; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;
            // reduce in-degree of adjacent vertices
            for (auto v : adj[u]) {
                inDegree[v]--;
                // if in-degree becomes 0, enqueue the
                // vertex
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited != V; // if not all vertices are visited, there is a cycle
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
