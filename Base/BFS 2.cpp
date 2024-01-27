#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
vector<int>adj[maxn];
bool visited[maxn];
void bfs(int src) {
    queue<int> q;
    cout << src << " ";
    visited[src]=true;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int child : adj[head]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
                cout << child << " ";
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
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u < 0 || v < 0 || u >= node || v >= node) {
            cout << "Invalid edge values.";
            return 1;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src = 0;
    bfs(src);
    return 0;
}
