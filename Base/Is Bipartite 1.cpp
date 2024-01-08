#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  // Initialize color array to -1 (unvisited)

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;  // Color the first vertex with 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Color adjacent vertices with the opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  // If an adjacent vertex has the same color, it's not Bipartite
                    }
                }
            }
        }
    }

    return true;  // If no adjacent vertices have the same color, the graph is Bipartite
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }
    if (isBipartite(graph)) {
        cout << "The graph is Bipartite." << endl;
    } else {
        cout << "The graph is not Bipartite." << endl;
    }
    return 0;
}

