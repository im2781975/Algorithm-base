#include<bits/stdc++.h>
using namespace std;

const int n=1e5+5;
const long long INF=1e18;
int visited[n+1],parent[n];
long long d[n+1];
int node, edge;
vector<pair<int, int>> adj_list[n];

void dijkstra(int src)
{
    for(int i=1; i<=node; i++)
        d[i] = INF;
        
    d[src] = 0;
    priority_queue<pair<long long,int>>pq;
    pq.push({0,src});
    
    while(!pq.empty())
    {
        pair<long long,int>head=pq.top();
        pq.pop();
        int select_node=head.second;
        if(visited[select_node])
            continue;
        visited[select_node]=1;
    
        for(auto adj_entry:adj_list[select_node])
        {
            int adj_node=adj_entry.first;
            
            int edge_cost=adj_entry.second;
            if(d[select_node] + edge_cost < d[adj_node])
            {
                d[adj_node] = d[select_node] + edge_cost;
                
            parent[adj_node]=select_node;
            pq.push({-d[adj_node],adj_node});
            }
        }
    }
}
int main()
{
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 1;
    dijkstra(src);
     
    if(visited[node]==0)
    {
        cout<<-1<<"\n";
        return 0;
    }
    int cur_node=node;
    vector<int>path;
    while(true)
    {
        path.push_back(cur_node);
        if(cur_node==src)
            break;
        cur_node=parent[cur_node];
    }
    reverse(path.begin(),path.end());
    for(auto node :path)
        cout<<node<<" ";
    cout<<"\n";
    return 0;
}
