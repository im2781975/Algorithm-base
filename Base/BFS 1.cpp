#include <bits/stdc++.h>
using namespace std;
void bfs(int src, vector<int> adj_list[], vector<int>& visited) {
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        cout << head << " ";

        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int node, edge;
    cin >> node >> edge;
    if (node <= 0 || edge < 0) {
        cout << "Invalid input values.";
        return 1;
    }
    vector<int> visited(node, 0);
    vector<int> adj_list[node];

    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u < 0 || v < 0 || u >= node || v >= node) {
            cout << "Invalid edge values.";
            return 1;
        }
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 0;
    bfs(src, adj_list, visited);
    return 0;
}
