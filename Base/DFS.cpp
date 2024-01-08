#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n + 1];
vector<int> adj_list[n + 1];
stack<int> node_stack;

void dfs(int node) {
    visited[node] = 1;
    for (int adj_node : adj_list[node]) {
        if (visited[adj_node] == 0) {
            dfs(adj_node);
        }
    }
    node_stack.push(node);
}

int main() {
    int node, edge;
    cin >> node >> edge;
    
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= node; i++) {  
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    while (!node_stack.empty()) {
        cout << node_stack.top() << " ";
        node_stack.pop();
    }
    return 0;
}
