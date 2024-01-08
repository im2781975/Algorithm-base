#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n + 1];
int color[n + 1];
vector<int> adj_list[n];

bool dfs(int node, int c) {
    visited[node] = 1;
    color[node] = c;

    for (int adj_node : adj_list[node]) {
        if (visited[adj_node] == 0) {
            if (!dfs(adj_node, 3 - c)) { // Use 3 - c to toggle colors (1 to 2 or 2 to 1)
                return false;
            }
        } else if (color[adj_node] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool is_bicolorable = true;
    for (int i = 1; i <= node; i++) {
        if (visited[i] == 0) {
            bool ok = dfs(i, 1); // Start with color 1
            if (!ok) {
                is_bicolorable = false;
                break;
            }
        }
    }

    if (!is_bicolorable) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1; i <= node; i++) {
            cout << color[i] << " ";
        }
    }
    return 0;
}

