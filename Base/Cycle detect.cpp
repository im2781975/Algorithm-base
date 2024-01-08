#include<bits/stdc++.h>
using namespace std;

const int n=1e5;
int visited[n+1];
vector<int> adj_list[n+1];

bool detect_cycle(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        // visited[0] = unexplored
        // visited[1] = paused | cycle detected
        // visited[2] = done | continue
        if (visited[adj_node] == 0)
        {
            bool got_cycle = detect_cycle(adj_node);
            if (got_cycle)
            {
                return true;
            }
        }
        else if (visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    bool cycle_exists = false;
    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == 0)
        {
            bool got_cycle = detect_cycle(i);
            if (got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }
    }
    if (cycle_exists)
        cout << "Cycle exists";
    else
        cout << "No cycle";
    return 0;
}

