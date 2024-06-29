#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
//visited: A map to keep track of visited vertices.
//adj: An adj list represented as a map, where each key is a vertex
//& the corresponding value is a list of adjacent vertices.
    map <int, bool> visited;
    map <int, list<int>> adj;
    void addEdge(int u, int v);
    void DFS(int u);
};
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
void Graph::DFS(int u){
    visited[u] = true;
    cout << u << " ";
    list <int> ::iterator it;
    for(it = adj[u].begin(); it!=adj[u].end(); ++it){
        if(!visited[*it])
            DFS(*it);
    }
}
int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
}
