// find if there is a cycle in a directed graph.
#include <bits/stdc++.h>
using namespace std;
enum Color {WHITE, GRAY, BLACK};
class Graph
{
    int V; 
    list<int>* adj; 
    // DFS traversal of the vertices reachable from v
    bool DFSUtil(int v, int color[]);
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
// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[])
{
    // GRAY : This vertex is being processed (DFS for this vertex has started, but not
    //  ended (or this vertex is in function call stack)
    color[u] = GRAY;
    // Iterate through all adjacent vertices
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  
        // An adjacent of u If there is
        if (color[v] == GRAY)
          return true;
        // If v is not processed and there is a back edge in subtree rooted with v
        if (color[v] == WHITE && DFSUtil(v, color))
          return true;
    }
    // Mark this vertex as processed
    color[u] = BLACK;
    return false;
}
// Returns true if there is a cycle in graph
bool Graph::isCyclic()
{
    // Initialize color of all vertices as WHITE
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;
    // Do a DFS traversal beginning with all vertices
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
           if (DFSUtil(i, color) == true)
              return true;
    return false;
}
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
