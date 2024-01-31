#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
vector<int>adj[maxn];
vector<bool>visited(maxn);
vector<int>color(maxn);
bool dfs(int src)
{
    visited[src]=true;
    for(int child:adj[src])
    {
        if(!visited[child])
        {
            if(color[src]==1)
                color[child]=2;
            else
                color[child]=1;
            bool bicolor=dfs(child);
            if(!bicolor)
                return false;
            
        }
        else
        {
            if(color[src]==color[child])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=1; i<=e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*for(int i=1; i<=n; i++)
    {
        cout << i << "->";
        for(auto child:adj[n])
        {
            cout << child << " ";
        }
        cout << "\n";
    }*/
    bool ok=true;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            color[i]=1;
            bool yes=dfs(i);
            if(!yes)
            {
                ok=false;
                break;
            }
        }
    }
    if(ok)
    {
        cout << "Yes";
        for(int i=1; i<=n; i++)
            cout << color[i] << " ";
        cout << "\n";
    }
    else
        cout << "No";
}
