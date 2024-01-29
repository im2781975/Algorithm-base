#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int src)
{
    visited[src] = true;
    cout << src << " ";
    for (int child : adj[src])
    {
        if (!visited[child])
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int child : adj[i])
        {
            cout << child << ' ';
        }
        cout << '\n';
    }

    dfs(1);
    return 0;
}

