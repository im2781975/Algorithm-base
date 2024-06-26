#include<bits/stdc++.h>
using namespace std;

const int n = 1e5;
const long long INF = 1e18;
long long d[n + 1];
int parent[n];
int node, edge;
vector<pair<int, int>> adj_list[n];

int main() {
    cin >> node >> edge;
    
    for (int i = 0; i < node; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < edge; i++) {
        int u, v, w; // Added missing variable 'w' for edge weight.
        cin >> u >> v >> w; // Read the edge weight 'w'.
        adj_list[u].push_back({v, w});
    }

    bool negetive_cycle = false;
    int last_updated_node = -1;

    for (int i = 1; i <= node; i++) {
        for (int j = 1; j <= node; j++) {
            for (pair<int, int> adj_node : adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    // iterates over each node and relaxes the edges by updating the minimum 
                    //distance (d[]) and parent information (parent[]) if a shorter path is found.
                    //i would be more than (node -1) times.so the iteration contain neg cycle
                    if (i == node) {
                        negetive_cycle = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if (negetive_cycle == true) {
        cout << "yes";
        int selected_node = last_updated_node;

        for (int i = 1; i <= node - 1; i++) {
            selected_node = parent[selected_node];
        }

        int first_node = selected_node;
        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true) {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);

            if (selected_node == first_node) {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle) {
            cout << node << " ";
        }
    } else {
        cout << "No";
    }
    return 0;
}
