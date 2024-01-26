// DFS traversal from a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V; 
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(); 
    // prints all not yet visited vertices reachable from s
    void DFSUtil(int s, vector<bool> &visited);
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
void Graph::DFSUtil(int s, vector<bool> &visited)
{
    stack<int> stack;
    stack.push(s);
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        int s = stack.top();
        stack.pop();
        //Stack may contain same vertex twice. So we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
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
// prints all vertices in DFS manner
void Graph::DFS()
{
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited);
}
int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    cout << "Following is Depth First Traversal\n";
    g.DFS();
    return 0;
}
