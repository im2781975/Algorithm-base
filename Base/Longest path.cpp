//find longest lath in DAG.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent_list[N];
int dp[N];

int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}

