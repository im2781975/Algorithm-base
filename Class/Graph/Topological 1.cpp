// topological sorting of a DAG
#include <bits/stdc++.h>
using namespace std;
// Graph class represents a directed graph using adjacency
// list representation
class Graph {
    int V; 
    list<int>* adj;
 
    public:
    Graph(int); 
    ~Graph(); 
    void addEdge(int, int);
    void DFS(int, vector<bool>&, vector<int>&, int&);
    void topologicalSort();
};
Graph::Graph(int V)
{
    this->V = V;
    this->adj = new list<int>[V];
}
Graph::~Graph() { delete[] this->adj; }
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
// The function to do DFS() and stores departure time of all vertex
void Graph::DFS(int v, vector<bool>& visited,vector<int>& departure, int& time)
{
    visited[v] = true;
    // time++;    
    // arrival time of vertex v
 
    for (int i : adj[v])
        if (!visited[i])
            DFS(i, visited, departure, time);
 
    // set departure time of vertex v
    departure[time++] = v;
}
// The function to do Topological Sort. It uses DFS().
void Graph::topologicalSort()
{
    // vector to store departure time of vertex.
    vector<int> departure(V, -1);
 
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
    int time = 0;
    // perform DFS on all unvisited vertices
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            DFS(i, visited, departure, time);
        }
    }
    // print the topological sort
    for (int i = V - 1; i >= 0; i--)
        cout << departure[i] << " ";
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Topological Sort of the given graph is \n";
    g.topologicalSort();
 
    return 0;
}
