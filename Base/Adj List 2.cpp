#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
int main()
{
    int n ,e;
    cin >> n >> e;
    vector<int>adjlist[n+1];
    for(int i=1; i<=e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
    {
        cout << i << "->";
        for(int j=0; j<=adjlist[i].size(); j++)
            cout << adjlist[i][j] << " ";
        cout << "\n";
    }
}
