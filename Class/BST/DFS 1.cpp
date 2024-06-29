#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V; 
    list<int> *adj; 
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
};
Graph::Graph(int V){
    this->V = V;
    //dynamically allocate an array of adjacency lists for a graph with N vertices.
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
// prints all not yet visited vertices reachable from s
void Graph::DFS(int src){
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(src);
    while (!st.empty()){
        int src = st.top();
        st.pop();
        // Stack may contain same vertex twice. So we 
        //need to print the popped item only if it is not visited.
        if (!visited[src]){
            cout << src << " ";
            visited[src] = true;
        }
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it to the stack.
        for (auto it = adj[src].begin(); it!= adj[src].end(); ++it)
            if (!visited[*it])
                st.push(*it);
    }
}
int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
    return 0;
}
