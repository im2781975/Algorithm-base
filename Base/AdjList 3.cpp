#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
int main()
{
    int n ,e;
    cin >> n >> e;
    vector<pair<int, int> >adjlist[n+1];
    for(int i=1; i<=e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }
    for(int i=1; i<=n; i++)
    {
        cout << i << "->";
        for(auto j: adjlist[i])
        {
            cout << "{" << j.first << " " << j.second << "}" << " ";
        }
        cout << "\n";
    }
}
