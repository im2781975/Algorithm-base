#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const long long INF = 1e18;
long long d[N][N];

int main()
{
    int node, edge, q;
    cin >> node >> edge >> q;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            d[i][j] = INF;
        }
    }
    // Updating distance matrix with given edges
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    // Setting diagonal elements to 0
    for (int i = 1; i <= node; i++)
    {
        d[i][i] = 0;
    }

    //find shortest paths
    for (int k = 1; k <= node; k++)
    {
        for (int u = 1; u <= node; u++)
        {
            for (int v = 1; v <= node; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }
    // Handling queries
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (d[u][v] == INF)
            cout << -1 << endl;
        else
            cout << d[u][v];
    }

    return 0;
}

