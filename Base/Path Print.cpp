#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
int level[n];
int parent[n];
vector<int> adj_list[n];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    
    parent[src]=-1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                parent[adj_node]=head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int nodes, edges; // Changed variable name from "node" to "nodes" and "edge" to "edges".
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    bfs(src);

    vector<int>path;
    int dst=node;
    if(visited[dst]==0)
    {
        cout<<"Impossible";
    }
    cout<<level[dst]<<"\n";
    int selected_node=dst;
    while(true)
    {
        path.push_back(selected_node);
        if(selected_node==src)
        {
            break;
        }
        selecte_node=parent[src];
    }
    reverse(path.begin(),path.end())
    for(int node:path)
    {
        cout<<node<<" ";
    }

    return 0;
}

