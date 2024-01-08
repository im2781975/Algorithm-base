#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
int level[n];
vector<int> adj_list[n];

void bfs(int src) {
    queue<int> q;
    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
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

    int src = 0;
    bfs(src);

    for (int i = 0; i < nodes; i++) { // Added "int" before "i" to declare the variable.
        cout << "Node " << i << " Level " << level[i] << endl; // Added "endl" to end the line.
    }

    return 0;
}

