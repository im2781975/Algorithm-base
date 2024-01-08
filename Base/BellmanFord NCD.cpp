//Negetive cycle detection
#include<bits/stdc++.h>
using namespace std;

const int n=1e5;
const int INF=1e9;
int d[n+1];
int node, edge;
vector<pair<int, int>> adj_list[n];

int main()
{
    cin >> node >> edge;
    for(int i=0; i<node; i++)
    {
        d[i]=INF;
    }
    for(int i=0; i<edge; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w; 
        adj_list[u].push_back({v, w});
    }
    int src = 1;
    d[src]=0;
    bool negetive_cycle=false;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            for(pair<int,int>adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                
                if(d[u]+w <d[v])
                {
                    d[v]=d[u] + w;
                    if(i==node)
                    {
                        negetive_cycle=true;
                    }
                }
            }
        }
    }
    if(negetive_cycle==true)
    {
        cout<<"NCD exist";
    }
    else
    {
        for(int i=1; i<=node; i++)
        {
            cout<<d[i]<<"\n";
        }
    }
    return 0;
}

