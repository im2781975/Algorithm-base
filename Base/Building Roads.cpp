//CSES
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
vector<int>adj[maxn];
vector<bool>visited(maxn);
void dfs(int src)
{
    visited[src]=true;
    for(auto child:adj[src])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
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
    vector<int>ans;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    if(ans.size()<=1)
        cout << 0;
    else
    {
        vector<pair<int, int >> roads;
        for(int i=0; i<roads.size() -1; i++)
            roads.push_back({ans[i], ans[i+1]});
        cout << roads.size() << "\n";
        for(auto val:roads)
            cout << val.first << " " << val.second << "\n";
    }
}
