// find single source longest distances in a DAG
#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#define NINF INT_MIN
using namespace std;
class AdjListNode { 
    int v; 
    int weight; 
   
    public: 
    AdjListNode(int _v, int _w) 
    { 
        v = _v; 
        weight = _w; 
    } 
    int getV() { return v; } 
    int getWeight() { return weight; } 
}; 
class Graph { 
    int V;
    list<AdjListNode>* adj; 
   
    // A function used by longestPath 
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack); 
    public: 
    Graph(int V);
    ~Graph(); 
 
    void addEdge(int u, int v, int weight); 
   
    // Finds longest distances from given source vertex 
    void longestPath(int s); 
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<AdjListNode>[V]; 
} 
Graph::~Graph()  
{ 
    delete [] adj; 
} 
void Graph::addEdge(int u, int v, int weight) 
{ 
    AdjListNode node(v, weight); 
    adj[u].push_back(node);
} 
void Graph::topologicalSortUtil(int v, bool visited[], 
    stack<int>& Stack) 
{ 
    visited[v] = true; 
    // Recur for all the vertices adjacent to this vertex 
    list<AdjListNode>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) { 
        AdjListNode node = *i; 
        if (!visited[node.getV()]) 
            topologicalSortUtil(node.getV(), visited, Stack); 
    } 
    // Push current vertex to stack which stores topological sort 
    Stack.push(v); 
} 
//find longest distances from a given vertex. 
void Graph::longestPath(int s) 
{ 
    stack<int> Stack; 
    int dist[V]; 
   
    // Mark all the vertices as not visited 
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
   
    // Call the recursive helper function to store Topological 
    // Sort starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
   
    for (int i = 0; i < V; i++) 
        dist[i] = NINF; 
    dist[s] = 0; 
    // Process vertices in topological order 
    while (Stack.empty() == false)
    { 
        // Get the next vertex from topological order
        int u = Stack.top(); 
        Stack.pop(); 
        // Update distances of all adjacent vertices 
        list<AdjListNode>::iterator i; 
        if (dist[u] != NINF) { 
            for (i = adj[u].begin(); i != adj[u].end(); ++i){ 
             
                if (dist[i->getV()] < dist[u] + i->getWeight()) 
                    dist[i->getV()] = dist[u] + i->getWeight();
            }
        } 
    } 
    // Print the calculated longest distances 
    for (int i = 0; i < V; i++) 
        (dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
     
    delete [] visited;
}
int main() 
{ 
    Graph g(6); 
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 5, 1); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2); 
   
    int s = 1; 
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n"; 
    g.longestPath(s); 
    return 0; 
}
