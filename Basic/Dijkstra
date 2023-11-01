#include<bits/stdc++.h>
using namespace std;

const int n=1e5;
const int INF=1e9;
int visited[n+1];
int d[n+1];
int node, edge;
vector<pair<int, int>> adj_list[n];

void dijkstra(int src)
{
    for(int i=1; i<=node; i++)
    {
        d[i] = INF;
    }
    d[src] = 0; // Initialize the source node distance to 0.
    
    for(int i=0; i<node; i++)
    {
        int select_node = -1;
        for(int j=1; j<=node; j++)
        {
            if(visited[j] == 1) continue;
            if(select_node == -1 || d[select_node] > d[j])
            {
                select_node = j;
            }
        }
        visited[select_node] = 1;
        
        for(auto adj_entry : adj_list[select_node])
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;
            if(d[select_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[select_node] + edge_cost;
            }
        }
    }
}

int main()
{
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int u, v, w; // Added missing variable 'w' for edge weight.
        cin >> u >> v >> w; // Read the edge weight 'w'.
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 1;
    dijkstra(src);
    for(int i=1; i<=node; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}

