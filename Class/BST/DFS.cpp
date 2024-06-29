#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V; 
    list<int> *adj; 
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
    //void DFS(); 
    // prints all not yet visited vertices reachable from s
    //void DFSUtil(int s, vector<bool> &visited);
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
}/*
void Graph::DFSUtil(int s, vector<bool> &visited)
{
    stack<int> stack;
    stack.push(s);
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        int s = stack.top();
        stack.pop();
        //Stack may contain same vertex twice. So we 
        //need to print the popped item only if it is not visited.
        if (!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}
void Graph::DFS(){
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++){
        if (!visited[i])
            DFSUtil(i, visited);
    }
}*/
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
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
    //g.DFS();
    return 0;
}

