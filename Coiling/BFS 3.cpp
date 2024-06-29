#include<bits/stdc++.h>
using namespace std;
class Graph{
    int N;
    vector<list<int>>adj;
    public:
    Graph(int N);
    void addEdge(int u, int v);
    void BFS(int src);
};
Graph::Graph(int N){
    this->N = N;
    adj.resize(N);
}
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
void Graph::BFS(int src){
    vector<bool>visited(N, false);
    list <int> q;
    visited[src] = true;
    q.push_back(src);
    while(!q.empty()){
        int src = q.front();
        cout << src << " ";
        q.pop_front();
        for(auto adjacent:adj[src]){
            if(!visited[adjacent]){
                visited[adjacent] = 1;
                q.push_back(adjacent);
            }
        }
    }
}
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
}
